#ifndef _LISTA_DOB_ENLAZ_
#define	_LISTA_DOB_ENLAZ_

#include<iostream>
#include<sstream>


#include"CNodo.h"
#include"Metodos_Dibujo.h"

using namespace std;
using namespace System::Windows::Forms;
using namespace System::Drawing;

class ListaDob{
public:
	CNodo*inicio;
	int numElementos;
public:
	ListaDob();
	~ListaDob();

	bool Insertar_Inicio(char* dato);
	bool Insertar_Final(char* dato);
	bool Insertar_Posicion(char* dato, int pos);
	bool Eliminar_Posicion(int pos);
	bool Eliminar_Inicio();
	bool Eliminar_Final();
	string toString();
	void Draw_List(Graphics^g);
};

ListaDob::ListaDob()
{
	inicio = nullptr;
	numElementos = 0;
}
ListaDob::~ListaDob(){}

bool ListaDob::Insertar_Inicio(char* dato)
{
	CNodo* Agregar_Inicio = new CNodo(dato);
	if (Agregar_Inicio == nullptr)
		return false;
	if (numElementos == 0){
		inicio = Agregar_Inicio;
		numElementos++;
		return true;
	}
	Agregar_Inicio->siguiente = inicio;
	Agregar_Inicio->siguiente->anterior = Agregar_Inicio;
	inicio = Agregar_Inicio;
	numElementos++;
	return true;
}

bool ListaDob::Insertar_Final(char* dato)
{
	if (inicio == nullptr)
		return Insertar_Inicio(dato);

	CNodo* Agregar_Final = inicio;

	while (Agregar_Final->siguiente != nullptr)
		Agregar_Final = Agregar_Final->siguiente;

	Agregar_Final->siguiente = new CNodo(dato);
	Agregar_Final->siguiente->anterior = Agregar_Final;
	if (Agregar_Final->siguiente == nullptr)
		return false;

	numElementos++;
	return true;
}

bool ListaDob::Insertar_Posicion(char* dato, int pos) // Restarle -1 al pos.
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
	if (Dato_Ingresado == nullptr) {
		return false;
	}
	for (int i = 1; i < pos - 1; i++)
	{
		ant = ant->siguiente;
	}
	/*	CNodo* Dato_Ingresado;
	strcpy(Dato_Ingresado->dato, dato);*/

	Dato_Ingresado->siguiente = aux;
	ant->siguiente = Dato_Ingresado;
	aux->anterior = Dato_Ingresado;
	Dato_Ingresado->anterior = ant;

	numElementos++;
	return true;

}

bool ListaDob::Eliminar_Posicion(int pos)
{
	if (pos <1 || pos>numElementos)
		return false;
	
	if (pos == 1) {
		return Eliminar_Inicio();
	}
	if (pos == numElementos) {
		return Eliminar_Final();
	}

	CNodo* aux = inicio;

	for (int i = 1; i < pos; i++)
		aux = aux->siguiente;

	CNodo*ant=inicio;

	for (int i = 1; i < pos-1; i++)
	{
		ant = ant->siguiente;
	}
	
	ant->siguiente = aux->siguiente;
	aux->siguiente->anterior = ant;

	

	//free(aux);
	numElementos--;
	return true;
}

string ListaDob::toString()
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

bool ListaDob::Eliminar_Inicio() {
	if (numElementos == 1) {
		inicio = nullptr;
		free(inicio);
		return true;
	}
	inicio = inicio->siguiente;
	free(inicio->anterior);
	inicio->anterior = nullptr;
	numElementos--;
	return true;
}
bool ListaDob::Eliminar_Final() {
	if (numElementos == 1) {
		return Eliminar_Inicio();
	}
	CNodo*aux = inicio;
	while (aux->siguiente != nullptr) {
		aux = aux->siguiente;
	}
	aux->anterior->siguiente = nullptr;
	aux = nullptr;
	free(aux);
	numElementos--;
	return true;
}

void ListaDob::Draw_List(Graphics^g) {

	g->Clear(SystemColors::Control);
	if (numElementos == 0) {
		return;
	}
	CNodo*aux = inicio;
	System::String^dat = gcnew System::String(aux->Get_Dato());
	int xini, y;
	int x;
//	int ancho = 70, alto = 50;

	xini = (g->VisibleClipBounds.Width / numElementos) / 2;
	x = xini;
	y = (g->VisibleClipBounds.Height / 2);

	Draw_Inicio(g, x, y);

	for (int i = 0; i < numElementos; i++)
	{
		if (i>0){
			Draw_Arrow(g, x + ancho, y + alto / 4, x + (2 * xini*(i == 0 ? 0 : 1)) - 10, y + alto / 4, 1);
			Draw_Arrow(g, x + (2 * xini*(i == 0 ? 0 : 1)) - 10, y + alto *3/4, x + ancho, y + alto *3/4, 4);
		}
		Draw_boxes(g, aux, dat, &x, y, xini, i);
		aux = aux->siguiente;

	}
	Draw_final(g, x, y);

	
}

#endif // !_LISTA_DOB_ENLAZ_
