
#ifndef _LISTAMADRE_
#define _LISTAMADRE_

#include<iostream>
#include<sstream>
#include"CNodo.h"

using namespace std;

class ListaMadre{
public:
	CNodo*inicio;
	int numElementos;

public:
	ListaMadre(){
		inicio = nullptr;
		numElementos = 0;
	}

	virtual bool insertarInicio(CNodo*dato)abstract;
	virtual bool insertarFinal(CNodo*dato)abstract;
	virtual bool insertarPosicion(CNodo*dato)abstract;
	virtual CNodo* buscarPosisicion(int pos)abstract;
	virtual bool deletePosicion(int pos)abstract;
	virtual bool deleteInicio()abstract;
	virtual bool deleteFinal()abstract;
};


#endif // !_LISTAMADRE_
