

#ifndef __CLista_Simple_PF_H
#define __CLista_Simple_PF_H
#include "CNodo.h"
#include"Metodos_Dibujo.h"

using namespace std;
using namespace System::Drawing;
using namespace System;

class CLista_Simple_PF
{
public:
	CNodo* inicio;
	CNodo* rear;
	int numElementos;
public:
	CLista_Simple_PF();
	~CLista_Simple_PF();

	bool Insertar_Inicio(char* dato);
	bool Insertar_Final(char* dato);
	bool Insertar_Posicion(char* dato, int pos);
	bool Eliminar_Posicion(int pos);
	bool Eliminar_Inicio();
	bool Eliminar_Final();
	string toString();

	void Draw_Lista(Graphics^g);

};

CLista_Simple_PF::CLista_Simple_PF()
{
	inicio = nullptr;
	numElementos = 0;
}
CLista_Simple_PF::~CLista_Simple_PF() {}

bool CLista_Simple_PF::Insertar_Inicio(char* dato)
{
	CNodo* Agregar_Inicio = new CNodo(dato);
	if (Agregar_Inicio == nullptr)
		return false;
	Agregar_Inicio->siguiente = inicio;
	if (inicio == nullptr)
		inicio = rear = Agregar_Inicio;
	else
		inicio = Agregar_Inicio;
	numElementos++;
	return true;
}
bool CLista_Simple_PF::Insertar_Final(char* dato)
{
	if (inicio == nullptr)
		return Insertar_Inicio(dato);

	rear->siguiente = new CNodo(dato);
	if (rear->siguiente == nullptr)
		return false;

	else
		rear = rear->siguiente;

	numElementos++;
	return true;


}
bool CLista_Simple_PF::Insertar_Posicion(char* dato, int pos)
{
	if (pos <1 || pos>numElementos)
		return false;
	if (pos == 1)
	{
		Insertar_Inicio(dato);
		return true;
	}
	CNodo* aux = inicio;
	CNodo* ant = inicio;//anterior a la posicion
	for (int i = 1; i < pos; i++)
		aux = aux->siguiente;
	CNodo* Dato_Ingresado = new CNodo(dato);
	for (int i = 1; i < pos - 1; i++)
		ant = ant->siguiente;
	Dato_Ingresado->siguiente = aux;
	ant->siguiente = Dato_Ingresado;
	numElementos++;
	return true;

}
bool CLista_Simple_PF::Eliminar_Posicion(int pos)
{
	if (pos <1 || pos>numElementos)
		return false;
	if (pos == 1)
		return Eliminar_Inicio();

	if (pos == numElementos)
		return Eliminar_Final();

	CNodo* aux = inicio;

	for (int i = 1; i < pos; i++)
		aux = aux->siguiente;
	CNodo*ant = inicio;
	for (int i = 1; i < pos - 1; i++)
		ant = ant->siguiente;

	ant->siguiente = aux->siguiente;

	free(aux);
	/*while (aux->siguiente != nullptr)
		aux = aux->siguiente;*/
	//rear = aux->siguiente;
	numElementos--;
	return true;
}
bool CLista_Simple_PF::Eliminar_Inicio()
{
	if (inicio->siguiente == nullptr)
	{
		inicio == nullptr;
		free(inicio);
		numElementos--;
		return true;
	}
	CNodo*aux = inicio;
	inicio = inicio->siguiente;
	free(aux);
	numElementos--;
	return true;

}
bool CLista_Simple_PF::Eliminar_Final()
{
	if (inicio->siguiente == nullptr)
		return Eliminar_Inicio();

	CNodo*aux = inicio;
	while (aux->siguiente->siguiente != nullptr)
		aux = aux->siguiente;
	aux->siguiente = nullptr;
	free(aux->siguiente);
	rear = aux;
	numElementos--;
	return true;
}
string CLista_Simple_PF::toString()
{
	if (numElementos == 0)
		return "";

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

void CLista_Simple_PF::Draw_Lista(Graphics^g)
{
	g->Clear(SystemColors::Control);
	if (numElementos == 0) {
		return;
	}
	CNodo*aux = inicio;
	System::String^dat = gcnew System::String(aux->Get_Dato());
	int xini, y;
	int x;
	//int ancho = 70, alto = 50;

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
	Draw_final(g, x, y);
	Draw_Rear(g, x, y);

}

#endif