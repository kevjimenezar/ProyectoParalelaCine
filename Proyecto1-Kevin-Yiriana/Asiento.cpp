#include "Asiento.h"

Asiento::Asiento(){
	cedula = "INDEFINIDO";
	estado = 'V';		
	identificador = "";

}

Asiento:: ~Asiento(){}

string Asiento::getCedula() { return cedula; }
char Asiento::getEstado() { return estado; }
string Asiento::getIdentificador() { return identificador; }


void Asiento::setCedula(string ced) { cedula = ced; }
void Asiento::setEstado(char est) { estado=est; }
void Asiento::setIdentificador(string ident) { identificador = ident; }

string Asiento::identAsiento(int filAct,int colAct) {
	string ident;

	if (filAct == 0) {
		ident = "A";
	}
	else if (filAct == 1) {
		ident = "B";
	}
	else if (filAct == 2) {
		ident = "C";
	}
	else if (filAct == 3) {
		ident = "D";
	}
	else if (filAct == 4) {
		ident = "E";
	}
	else if (filAct == 5) {
		ident = "F";
	}
	ident += to_string(colAct+1);

	return ident;
}

string Asiento::toString(){
	stringstream s;
	s << "------ASIENTO------" << endl
		<< "Estado: " << estado << endl
		<< "Cedula Propietaria" << cedula << endl
		<< "Identificador: " << identificador << endl;
	return s.str();
}
