#ifndef __CNODO_H_
#define __CNODO_H_

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;


class CNodo
	{
		public:
			char* dato;
			CNodo* siguiente;
			CNodo* anterior;
		public:			
			CNodo(char* dato);
			~CNodo();
			char* Get_Dato();
//			void setDato(char* dato);
			CNodo*Get_anterior();
			CNodo* Get_Siguiente();
			void Set_Siguiente(CNodo* siguiente);
			
	};

CNodo::CNodo(char* dato)
	{
	//	this->dato = dato;
		this->dato = new char[100];
	/*	for (int i = 0; i < strlen(this->dato); i++)
			{
				if (int(dato[i]) == 32)
					break;
				this->dato[i] = dato[i];
			}*/
		strcpy(this->dato, dato);
		siguiente = NULL;
		anterior = NULL;
	}
CNodo::~CNodo(){}
char* CNodo::Get_Dato()			{ return dato;}
//void CNodo::setDato(char* dato)	{ this->dato = dato; }
//CNodo* CNodo::Get_Siguiente()	{ this->siguiente; }
void CNodo::Set_Siguiente(CNodo* siguiente)	{ this->siguiente = siguiente; }


CNodo*CNodo::Get_anterior(){
	return this->anterior;
}



#endif
