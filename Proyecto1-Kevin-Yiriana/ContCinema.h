#pragma once
#include"Cinema.h"


class ContCinema{
private:
	Cinema* vecC[364];
	int cant;
	int tam;
public:
	ContCinema();
	virtual ~ContCinema();
	void ingresaCinema(Cinema*);
	bool verificaFecha(string);
	string busquedaP(int,string);
	string muestraP();
	string retornaEstadoAsient(int, string, int, string);
	void estadoAsiento(int , string , int , string, int, string);
	string muestraMatrizA(int, string, int);
	int montoTiquete(int, int, int, string);
	string buscaNombrePelicula(string, int, int);
	string MuestraIdentificadores(string, int, int, string);
	string toString();
	string buscarAsientosConsecutivos(Sala* sala, int numAsientos);
};