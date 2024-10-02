#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <chrono>
using namespace std;

class Pelicula {
	private:
		string nombre;
		string genero;
		string tipo;
		string dimensiones;
		string tipoPublico;
		string sinopsis;
		string pais;
		int annio;

	public:
		Pelicula(string, string, string, string, string, string, string, int);
		virtual ~Pelicula();
		string getNombre();
		string getGenero();
		string getTipo();
		string getDimensiones();
		string getTipoPublico();
		string getSinopsis();
		string getPais();
		int getAnnio();

		void setNombre(string);
		void setGenero(string);
		void setTipo(string);
		void setDimensiones(string);
		void setTipoPublico(string);
		void setSinopsis(string);
		void setPais(string);
		void setAnnio(int);

		string toString();
		
		

};
