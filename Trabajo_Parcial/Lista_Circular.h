#ifndef __CLista_Circular_
#define __CLista_Circular_

#include "CNodo.h"
#include"Metodos_Dibujo.h"

using namespace std;
using namespace System::Drawing;
using namespace System;

class Lista_Circular
{
public:
	CNodo* inicio;
	int numElementos;
public:
	Lista_Circular();
	~Lista_Circular();

	bool Insertar_Inicio(char* dato);
	bool Insertar_Final(char* dato);
	bool Insertar_Posicion(char* dato, int pos);
	bool Eliminar_Posicion(int pos);
	bool Eliminar_inicio();
	bool Eliminar_Final();
	string toString();
	void Draw_List(Graphics^g);

};

Lista_Circular::Lista_Circular()
{
	inicio = nullptr;
	numElementos = 0;
}
Lista_Circular::~Lista_Circular(){}

bool Lista_Circular::Insertar_Inicio(char* dato)
{
	
	CNodo* Agregar_Inicio = new CNodo(dato);
	if (Agregar_Inicio == nullptr)
		return false;
	if (numElementos == 0){
		inicio = Agregar_Inicio;
		inicio->siguiente = inicio;
		numElementos++;
		return true;
	}
	CNodo* aux = inicio;
	while (aux->siguiente!=inicio)
	{
		aux = aux->siguiente;
	}
	Agregar_Inicio->siguiente = inicio;
	
	inicio = Agregar_Inicio;
	aux->siguiente = inicio;
	
	numElementos++;
	return true;
}

bool Lista_Circular::Insertar_Final(char* dato)
{
	if (inicio == nullptr)
		return Insertar_Inicio(dato);

	CNodo* Agregar_Final = inicio;
	
	while (Agregar_Final->siguiente != inicio)
		Agregar_Final = Agregar_Final->siguiente;

	Agregar_Final->siguiente = new CNodo(dato);

	if (Agregar_Final->siguiente == nullptr)
		return false;
	Agregar_Final->siguiente->siguiente = inicio;

	numElementos++;
	return true;
}

bool Lista_Circular::Insertar_Posicion(char* dato, int pos) // Restarle -1 al pos.
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
	ant->siguiente = Dato_Ingresado;
	// inicio = aux;
	numElementos++;
	return true;
}

bool Lista_Circular::Eliminar_Posicion(int pos)
{
	if (pos <1 || pos>numElementos)
		return false;
	if (pos == 1) {
		return Eliminar_inicio();
	}
	if (pos == numElementos) {
		return Eliminar_Final();
	}
	CNodo* aux = inicio;

	for (int i = 1; i < pos; i++)
		aux = aux->siguiente;
	CNodo*ant = inicio;
	for (int i = 1; i < pos - 1; i++)
	{
		ant = ant->siguiente;
	}


	ant->siguiente = aux->siguiente;

	free(aux);
	numElementos--;
	return true;
}

string Lista_Circular::toString()
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


bool Lista_Circular::Eliminar_inicio() {
	if (numElementos == 1) {
		inicio = nullptr;
		return true;
	}
	CNodo*aux = inicio;
	while (aux->siguiente != inicio) {
		aux = aux->siguiente;
	}
	aux->siguiente = inicio->siguiente;
	inicio = inicio->siguiente;
	numElementos--;
	return true;
}
bool Lista_Circular::Eliminar_Final() {
	if (numElementos == 1) {
		return Eliminar_inicio();
	}
	CNodo*aux = inicio;
	while (aux->siguiente->siguiente != inicio) {
		aux = aux->siguiente;
	}
	free(aux->siguiente);
	aux->siguiente = inicio;
	numElementos--;
	return true;
}

void Lista_Circular::Draw_List(Graphics^g) {
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
		if (i>0)
			Draw_Arrow(g, x + ancho, y + alto / 2, x + (2 * xini*(i == 0 ? 0 : 1)) - 10, y + alto / 2, 1);
		Draw_boxes(g, aux, dat, &x, y, xini, i);
		aux = aux->siguiente;
	}
	Draw_Final_circular(g, x, y, xini);
}

#endif