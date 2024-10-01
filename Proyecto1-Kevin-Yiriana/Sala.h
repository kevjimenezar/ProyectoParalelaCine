#pragma once
#include"Funcion.h"
#include"ContAsientos.h"


class Sala {
	private:
		int cantF;
		int cantA;
		Funcion* vecF[3];
		ContAsientos* vecA[3];
		string tipoSala;
	public:
		Sala();
		virtual ~Sala();

		string getTipoSala();
		void setTipoSala(string);
		void ingresarFuncion(Funcion*);
		void ingresaMatrizAsientos(ContAsientos*);
		string buscaPeli(int, string);
		string retornaFecha();
		string retornaMaAsientos(int);
		void cambiaEstado(int, string,int, string);
		string retornaNombrePeli(int);
		string retornaAsientosComprados(int, string);
		string retornaEstado(int, string);
		string toString();


};
