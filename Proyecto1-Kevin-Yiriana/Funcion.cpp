#include "Funcion.h"


Funcion::Funcion(int m, int h, string fe, Pelicula* ptrP){
	fecha = fe;
	hora = h;
	minutos = m;
	ptrPeli = ptrP;
}
Funcion::~Funcion(){
	delete ptrPeli;
	ptrPeli = NULL;
}
string Funcion::getFecha() { return fecha; }
int Funcion::getHora() { return hora; }
int Funcion::getMinutos() { return minutos; }
Pelicula* Funcion::getPelicula() { return ptrPeli; }

void Funcion::setFecha(string fe) { fecha = fe; }
void Funcion::setHora(int h) { hora = h; }
void Funcion::setMinutos(int m) { minutos = m; }
void Funcion::setPelicula(Pelicula* ptrP) { ptrPeli = ptrP; }

string Funcion::toString(){
	stringstream s;
		s << ptrPeli->toString()
			<< "Fecha: " << fecha << endl
			<< "Hora: " << hora <<":"<<minutos << endl;
	return s.str();
}


