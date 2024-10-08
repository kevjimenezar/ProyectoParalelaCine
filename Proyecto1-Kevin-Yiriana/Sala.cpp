#include "Sala.h"

Sala::Sala(){
	tipoSala = "";
	cantF = 0;
	cantA = 0;
	for (int i = 0; i < 3; i++){
		vecF[i] = NULL;
		vecA[i] = NULL;
	}
}
Sala::~Sala(){
	for (int i = 0; i < 3; i++){
		delete vecF[i];
		delete vecA[i];
		vecF[i] = NULL;
		vecA[i] = NULL;
	}
}

string Sala::getTipoSala() { return tipoSala; }
void Sala::setTipoSala(string tipSala){ tipoSala = tipSala; }

int Sala::getCantidadFunciones() {
	return cantF;
}

Funcion* Sala::getFuncion(int index) {
	if (index >= 0 && index < cantF) {
		return vecF[index];
	}
	return nullptr;
}

ContAsientos* Sala::getAsientos(int index) {
	if (index >= 0 && index < cantA) {
		return vecA[index];
	}
	return nullptr;
}
void Sala::ingresarFuncion(Funcion* ptrF) {
	if (cantF < 3) {
		vecF[cantF] = ptrF;
		cantF++;
	}
}

void Sala::ingresaMatrizAsientos(ContAsientos* ptrCA) {
	if (cantA < 3) {
		vecA[cantA] = ptrCA;
		cantA++;
	}
}

void Sala::cambiaEstado(int ho, string ident,int est, string ced) {
	if (est == 0) {
		vecA[ho]->seleccionadoEstado(ident);
	}
	else if (est == 1) {
		vecA[ho]->ocupadoEstado(ced);
	}
	else if (est == 2) {
		vecA[ho]->disponibleEstado();
	}
}

// Funcion para verificar el tipo de busqueda y realizarla
string Sala::buscaPeli(int op, string busq) {
	stringstream s;
	if (op == 6) {
		op = 5;
	}
	switch (op) {
	case 1:
		for (int i = 0; i < 3; i++) {
			if (vecF[i]->getPelicula()->getGenero() == busq) {
				s << vecF[i]->toString();
			}
		}
		break;
	case 2:
		for (int i = 0; i < 3; i++) {
			if (vecF[i]->getPelicula()->getNombre() == busq) {
				s << vecF[i]->toString();
			}
		}
		break;
	case 3:
		for (int i = 0; i < 3; i++) {
			if (vecF[i]->getPelicula()->getTipo() == busq) {
				s << vecF[i]->toString();
			}
		}
		break;
	case 4:
		for (int i = 0; i < 3; i++) {
			if (vecF[i]->getPelicula()->getDimensiones() == busq) {
				s << vecF[i]->toString();
			}
		}
		break;
	case 5:
		for (int i = 0; i < 3; i++) {
			if (vecF[i]->getPelicula()->getTipoPublico() == busq) {
				s << vecF[i]->toString();
			}
		}
		break;
	}
	return s.str();
}

string Sala::retornaFecha() {
	return vecF[1]->getFecha();
}

string Sala::retornaMaAsientos(int h) {
	return vecA[h]->toString();
}

string Sala::retornaNombrePeli(int h) {
	return vecF[h]->getPelicula()->getNombre();
}

string Sala::retornaAsientosComprados(int h, string ced) {
	return vecA[h]->retornaIdentificador(ced);

}

string Sala::retornaEstado(int h, string ident){
	return vecA[h]->retornaEstIdent(ident);
}
string Sala::toString(){
	stringstream s; 
	s << "SALA" << endl
		<< "Tipo sala: " << tipoSala << endl
		<< "------------------------" << endl;
		for (int i = 0; i < cantF; i++)
			s << vecF[i]->toString();
	return s.str();
}

