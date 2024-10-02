#include "ContAsientos.h"


ContAsientos::ContAsientos() {
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 10; j++)
			matrizA[i][j] = NULL;
	filAct=0;
	colAct=0;
}

ContAsientos::~ContAsientos() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 10; j++) {
			delete matrizA[i][j];
			matrizA[i][j] = NULL;
		}
	}
}

int ContAsientos::getFilAct() { return filAct; }
int ContAsientos::getColAct() { return colAct; }
void ContAsientos::setFilAct(int fil) { filAct = fil; }
void ContAsientos::setColAct(int col) { colAct = col; }


void ContAsientos::ingresaAsiento(Asiento* asient) {
	if(filAct < 6){
		matrizA [filAct][colAct++] = asient;
		if(colAct == 10){
			colAct = 0;
			filAct++;
		}
	}
	else{
		colAct = 0;
		filAct = 0;
	}	
}

string ContAsientos::buscarAsientosConsecutivos(int cantidad) {
	stringstream s;
	for (int i = 0; i < 6; i++) {
		int contador = 0; 
		string asientosDisponibles;  // Cadena para almacenar asientos consecutivos
		for (int j = 0; j < 10; j++) {
			if (matrizA[i][j] != nullptr && matrizA[i][j]->getEstado() == 'V') {
				asientosDisponibles += matrizA[i][j]->getIdentificador() + " ";
				contador++;
			}
			else {
				if (contador >= cantidad) {
					s << asientosDisponibles << " | ";
				}
				contador = 0;
				asientosDisponibles.clear();
			}
		}
		if (contador >= cantidad) {
			s << asientosDisponibles << " | ";
		}
	}
	if (s.str().empty()) {
		return "No hay asientos consecutivos disponibles.";
	}
	return s.str();
}


string ContAsientos::retornaEstIdent(string ident){
stringstream s;
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 10; j++)
			if (matrizA[i][j]->getIdentificador() == ident) {
				s << matrizA[i][j]->getEstado();
			}
	return s.str();
}
void ContAsientos::seleccionadoEstado(string ident) {
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 10; j++)
			if (matrizA[i][j]->getIdentificador() == ident)
				matrizA[i][j]->setEstado('G');
}

void ContAsientos::ocupadoEstado(string ced) {
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 10; j++)
			if (matrizA[i][j]->getEstado() == 'G') {
				matrizA[i][j]->setEstado('R');
				matrizA[i][j]->setCedula(ced);
			}
}


void ContAsientos::disponibleEstado() {
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 10; j++)
			if (matrizA[i][j]->getEstado() == 'G')
				matrizA[i][j]->setEstado('V');
}
string ContAsientos::retornaIdentificador(string ced) {
	stringstream s;
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 10; j++)
			if (matrizA[i][j]->getCedula() == ced) {
				s << matrizA[i][j]->getIdentificador()
					<< " | ";
			}
	return s.str();
}
string ContAsientos::toString() {
	stringstream s;
	int aux;
	s << "   1  2  3  4  5  6  7  8  9  10" << endl;
	for (int i = 0; i < 6; i++) {
		aux = i;
		for (int j = 0; j < 10; j++) {
			if (aux == 0) {
				s << "A";
			}
			else if (aux == 1) {
				s << "B";
			}
			else if (aux == 2) {
				s << "C";
			}
			else if (aux == 3) {
				s << "D";
			}
			else if (aux == 4) {
				s << "E";
			}
			else if (aux == 5) {
				s << "F";
			}
			else if (aux == 6) {
				s << "G";
			}
			aux = -1;
			s << "  "
				<< matrizA[i][j]->getEstado();
			if (j == 9) {
				 s << endl;
			}
		}
	}
	return s.str();
}
