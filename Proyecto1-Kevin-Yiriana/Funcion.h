#pragma once
#include "Pelicula.h"


class Funcion {
private:
	string fecha;
	int hora;
	int minutos;
	Pelicula* ptrPeli;

public:
	Funcion(int, int, string, Pelicula*);
	virtual~Funcion();

	string getFecha();
	int getHora();
	int getMinutos();
	Pelicula* getPelicula();

	void setFecha(string);
	void setHora(int);
	void setMinutos(int);
	void setPelicula(Pelicula*);

	string toString();
};