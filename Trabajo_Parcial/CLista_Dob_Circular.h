#ifndef __CLista_Dob_Circular_
#define __CLista_Dob_Circular_

#include "CNodo.h"
#include"Metodos_Dibujo.h"

using namespace std;
using namespace System;
using namespace Drawing;
class Lista_Dob_Circular
{
public:
	CNodo* inicio;
	int numElementos;
public:
	Lista_Dob_Circular();
	~Lista_Dob_Circular();

	bool Insertar_Inicio(char* dato);
	bool Insertar_Final(char* dato);
	bool Insertar_Posicion(char* dato, int pos);
	bool Eliminar_Posicion(int pos);
	bool Eliminar_Inicio();
	bool Eliminar_Final();
	string toString();
	void Draw_List(Graphics^g);
};

Lista_Dob_Circular::Lista_Dob_Circular()
{
	inicio = nullptr;
	numElementos = 0;
}
Lista_Dob_Circular::~Lista_Dob_Circular(){}

bool Lista_Dob_Circular::Insertar_Inicio(char* dato)
{

	CNodo* Agregar_Inicio = new CNodo(dato);
	if (Agregar_Inicio == nullptr)
		return false;
	if (numElementos == 0){
		inicio = Agregar_Inicio;
		inicio->siguiente = inicio;
		inicio->anterior = inicio;
		numElementos++;
		return true;
	}
	CNodo* aux = inicio;
	while (aux->siguiente != inicio)
	{
		aux = aux->siguiente;
	}
	Agregar_Inicio->siguiente = inicio;
	inicio->anterior = Agregar_Inicio;
	inicio = Agregar_Inicio;
	aux->siguiente = inicio;
	inicio->anterior = aux;

	numElementos++;
	return true;
}

bool Lista_Dob_Circular::Insertar_Final(char* dato)
{
	if (inicio == nullptr)
		return Insertar_Inicio(dato);

	CNodo* Agregar_Final = inicio->anterior;
	//CNodo*aux = new CNodo(dato);
	

	Agregar_Final->siguiente = new CNodo(dato);

	if (Agregar_Final->siguiente == nullptr)
		return false;

	Agregar_Final->siguiente->siguiente = inicio;
	inicio->anterior = Agregar_Final->siguiente;
	Agregar_Final->siguiente->anterior = Agregar_Final;
	
	//aux->siguiente->siguiente = inicio;
	//aux->siguiente->anterior = aux;
	//inicio->anterior = aux->siguiente;

	numElementos++;
	return true;
}

bool Lista_Dob_Circular::Insertar_Posicion(char* dato, int pos) // Restarle -1 al pos.
{
	if (pos <1 || pos>numElementos)
		return false;
	if (pos == 1){
		Insertar_Inicio(dato);
		return true;
	}
	
	CNodo* aux = inicio;
	CNodo*ant = inicio;//anterior a la posicion
	for (int i = 1; i < pos; i++)
		aux = aux->siguiente;
	CNodo* Dato_Ingresado = new CNodo(dato);
	for (int i = 1; i < pos - 1; i++)
	{
		ant = ant->siguiente;
	}
	/*	CNodo* Dato_Ingresado;
	strcpy(Dato_Ingresado->dato, dato);*/

	Dato_Ingresado->siguiente = aux;
	aux->anterior = Dato_Ingresado;

	ant->siguiente = Dato_Ingresado;
	Dato_Ingresado->anterior = ant;
	// inicio = aux;
	numElementos++;
	return true;
}

bool Lista_Dob_Circular::Eliminar_Posicion(int pos)
{
	if (pos <1 || pos>numElementos)
		return false;
	CNodo* aux = inicio;
	if (pos == 1) {
		return Eliminar_Inicio();
	}
	if (pos == numElementos) {
		return Eliminar_Final();
	}
	for (int i = 1; i < pos; i++)
		aux = aux->siguiente;
	CNodo*ant = inicio;
	for (int i = 1; i < pos - 1; i++)
	{
		ant = ant->siguiente;
	}


	ant->siguiente = aux->siguiente;
	aux->siguiente->anterior = ant;

	free(aux);
	numElementos--;
	return true;
}

string Lista_Dob_Circular::toString()
{
	CNodo* aux = inicio;
	ostringstream  Cadena;
	Cadena << "Inicio -->";
	int i = 0;
	while (aux != nullptr)
	{
		Cadena << (i++ == 0 ? "" : "--> ") << aux->dato;
		aux = aux->siguiente;
	}
	Cadena << "-->Fin";
	return Cadena.str();

}


bool Lista_Dob_Circular::Eliminar_Inicio() {
	if (numElementos == 1) {
		inicio = nullptr;
		return true;
	}
	CNodo*aux = inicio->anterior;
	
	aux->siguiente = inicio->siguiente;
	inicio->siguiente->anterior = aux;
	inicio = inicio->siguiente;
	numElementos--;
	return true;
}
bool Lista_Dob_Circular::Eliminar_Final() {
	if (numElementos == 1) {
		Eliminar_Inicio();
		return true;
	}
	CNodo*aux = inicio->anterior;
	
	
	aux->anterior->siguiente = inicio;
	inicio->anterior = aux->anterior;
	numElementos--;
	return true;

}

void Lista_Dob_Circular::Draw_List(Graphics^g) {

	g->Clear(SystemColors::Control);
	if (numElementos == 0) {
		return;
	}
	CNodo*aux = inicio;
	System::String^dat = gcnew System::String(aux->Get_Dato());
	int xini, y;
	int x;
	//int ancho = 68, alto = 50;

	xini = (g->VisibleClipBounds.Width / numElementos) / 2;
	x = xini;
	y = (g->VisibleClipBounds.Height / 2);

	Draw_Inicio(g, x, y);

	for (int i = 0; i < numElementos; i++)
	{
		if (i>0) {
			Draw_Arrow(g, x + ancho, y + alto / 4, x + (2 * xini*(i == 0 ? 0 : 1)) - 10, y + alto / 4, 1);
			Draw_Arrow(g, x + (2 * xini*(i == 0 ? 0 : 1)) - 10, y + alto * 3 / 4, x + ancho, y + alto * 3 / 4, 4);
		}
		Draw_boxes(g, aux, dat, &x, y, xini, i);
		aux = aux->siguiente;

	}
	Draw_Final_DobCirc(g, x, y, xini);


}
#endif