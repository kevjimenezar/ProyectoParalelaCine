#include "Pelicula.h"

Pelicula::Pelicula(string nom, string gen, string tip, string dim, string tipPu, string sinop, string pai, int an){
	nombre = nom;
	genero = gen;
	tipo = tip;
	dimensiones = dim;
	tipoPublico = tipPu;
	sinopsis = sinop;
	pais = pai;
	annio = an;
}

Pelicula:: ~Pelicula(){}
string Pelicula::getNombre() { return nombre; }
string Pelicula::getGenero() { return genero; }
string Pelicula::getTipo() { return tipo; }
string Pelicula::getDimensiones() { return dimensiones; }
string Pelicula::getTipoPublico() { return tipoPublico; }
string Pelicula::getSinopsis() { return sinopsis; }
string Pelicula::getPais() { return pais; }
int Pelicula::getAnnio() { return annio; }

void Pelicula::setNombre(string nom) { nombre = nom; }
void Pelicula::setGenero(string gen) { genero = gen; }
void Pelicula::setTipo(string tip) { tipo = tip; }
void Pelicula::setDimensiones(string dim) { dimensiones = dim; }
void Pelicula::setTipoPublico(string tipPu) { tipoPublico = tipPu; }
void Pelicula::setSinopsis(string sinop) { sinopsis = sinop; }
void Pelicula::setPais(string pai) { pais = pai; }
void Pelicula::setAnnio(int an) { annio = an; }

string Pelicula::toString(){
	stringstream s;
	s << "----------Pelicula----------" << endl
		<< "Nombre: " << nombre << endl
		<< "Genero: " << genero << endl
		<< "Tipo: " << tipo << endl
		<< "Dimensiones: " << dimensiones << endl
		<< "Tipo Publico: " << tipoPublico << endl
		<< "Sinopsis: " << sinopsis << endl
		<< "Pais:" << pais << endl
		<< "Annio: " << annio << endl;
	return s.str();
}