#ifndef __CLista_Enlazada_
#define __CLista_Enlazada_

#include "CNodo.h"
#include"Metodos_Dibujo.h"

using namespace std;
using namespace System::Windows::Forms;
using namespace System::Drawing;

class CLista_Enlazada
	{
	public:
		CNodo* inicio;
		int numElementos;
	public:
		CLista_Enlazada();
		~CLista_Enlazada();
		bool Insertar_Inicio(char* dato);
		bool Insertar_Final(char* dato);	
		bool Insertar_Posicion(char* dato, int pos);
		bool Eliminar_Posicion(int pos);
		bool Eliminar_Inicio();
		bool Eliminar_Final();
		string toString();
		//void Draw_Arrow(Graphics^g, int xini, int yini, int xfin, int yfin, int mode);
		void Draw_Lista(Graphics^g);
};

CLista_Enlazada::CLista_Enlazada()
	{
		inicio = nullptr;
		numElementos = 0;
	}
CLista_Enlazada::~CLista_Enlazada(){}

bool CLista_Enlazada::Insertar_Inicio(char* dato)
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

		inicio = Agregar_Inicio;
		numElementos++;
		return true;
	}

bool CLista_Enlazada::Insertar_Final(char* dato)
	{
		if (inicio == nullptr)
			return Insertar_Inicio(dato);
		
		CNodo* Agregar_Final = inicio;

		while (Agregar_Final->siguiente != nullptr)
			Agregar_Final = Agregar_Final->siguiente;
		
		Agregar_Final->siguiente = new CNodo(dato);
		if (Agregar_Final->siguiente == nullptr)
			return false;

		numElementos++;
		return true;
	}

bool CLista_Enlazada::Insertar_Posicion(char* dato, int pos) // Restarle -1 al pos.
	{
	if (pos <1 || pos>numElementos)
		return false;
	if (pos == 1){
		Insertar_Inicio(dato);
		return true;
	}
	/*if (pos == numElementos){
		Insertar_Final(dato);
	}*/
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

bool CLista_Enlazada::Eliminar_Posicion(int pos)
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

string CLista_Enlazada::toString()
	{
	if (numElementos == 0) {
		return "";
		}
		CNodo* aux = inicio;
		ostringstream  Cadena;
		Cadena << "Inicio -->";
		int i = 0;
		while (aux!=nullptr)
			{
				Cadena << (i++ == 0 ? "" : "--> ") << aux->dato;
				aux = aux->siguiente;
			}
		Cadena << "-->Fin";
		return Cadena.str();
		
	}

bool CLista_Enlazada::Eliminar_Inicio(){
	
	if (inicio->siguiente == nullptr){
		inicio == nullptr;
		free(inicio);
		numElementos--;
		return true;
	}
	CNodo*aux=inicio;
	inicio = inicio->siguiente;
	free(aux);
	numElementos--;
	return true;
}
bool CLista_Enlazada::Eliminar_Final() {
	if (inicio->siguiente == nullptr) {
		return Eliminar_Inicio();
	}
	CNodo*aux = inicio;
	while (aux->siguiente->siguiente != nullptr) {
		aux = aux->siguiente;
	}
	aux->siguiente = nullptr;
	free(aux->siguiente);
	numElementos--;
	return true;
}

/*void CLista_Enlazada::Draw_Arrow(Graphics^g,int xini, int yini, int xfin, int yfin,int mode ) {
	g->DrawLine(Pens::Black, xini, yini, xfin, yfin);
	if(mode==1){
	Point p1 =  Point(xfin, yfin);
	Point p2 = Point(xfin - 8, yfin + 8);
	Point p3 = Point(xfin - 8, yfin - 8);
	cli::array<Point>^tri = { p1,p2,p3 };
	g->FillPolygon(Brushes::Black, tri);
	}
	else {
		Point p1 = Point(xfin, yfin);
		Point p2 = Point(xfin + 8, yfin - 8);
		Point p3 = Point(xfin - 8, yfin - 8);
		cli::array<Point>^tri = { p1,p2,p3 };
		g->FillPolygon(Brushes::Black, tri);
	}
}*/

void CLista_Enlazada::Draw_Lista(Graphics^g) {

	//MAXIMO ELEMENTO 8 PARA QUE SE NOTE GRAFICAMENTE BIEN
	//LIMITAR NUMERO DE CARACTERES QUE ENTRAN
	
	g->Clear(SystemColors::Control);
	if (numElementos == 0) {
		return;
	}
	CNodo*aux = inicio;
	System::String^dat = gcnew System::String(aux->Get_Dato());
	int xini, y;
	int x;
	//int ancho=68, alto=50;

	xini = (g->VisibleClipBounds.Width / numElementos) / 2;
	x = xini;
	y = (g->VisibleClipBounds.Height / 2);

	Draw_Inicio(g, x, y);

	for (int i = 0; i < numElementos; i++)
	{
		if (i>0)
			Draw_Arrow(
				g,
				x + ancho,
				y + alto / 2,
				x + (2 * xini*(i == 0 ? 0 : 1)) - 10,
				y + alto / 2,
				1
			);
		Draw_boxes(g,aux, dat, &x, y, xini, i);
		aux = aux->siguiente;
	}
	Draw_final(g, x, y);
}

#endif