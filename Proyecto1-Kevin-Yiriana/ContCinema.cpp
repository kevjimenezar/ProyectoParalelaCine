#include "ContCinema.h"


ContCinema::ContCinema(){
	tam = 364;
	cant = 0;
	for (int i = 0; i < tam; i++) 
		vecC[i] = NULL;
}

ContCinema:: ~ContCinema(){
	for (int i = 0; i < cant; i++){
		delete vecC[i];
		vecC[i] = NULL;
	}
}
void ContCinema::ingresaCinema(Cinema* cine){
	if (cant < tam)
		vecC[cant++] = cine;
}
bool ContCinema::verificaFecha(string fech) {
	for (int i = 0; i < cant; i++) {
		if (vecC[i]->getSala1()->retornaFecha() == fech) {
			return false;
		}
	}
			return true;
}

string ContCinema::busquedaP(int op, string busq) {
	stringstream s;

	if (op == 5) {
		s << "----------------------SALA 1----------------------" << endl;
		for (int i = 0; i < cant; i++) {
			if (vecC[i]->getSala1()->getTipoSala() == busq) {
				s << vecC[i]->getSala1()->toString();
			}
		}
		s << "----------------------SALA 2----------------------" << endl;
		for (int i = 0; i < cant; i++) {
			if (vecC[i]->getSala2()->getTipoSala() == busq) {
				s << vecC[i]->getSala2()->toString();
			}
		}
	}
	else {
		s << "----------------------SALA 1----------------------" << endl;
		for (int i = 0; i < cant; i++) {
			s << "Tipo de sala: " << vecC[i]->getSala1()->getTipoSala() << endl
				<< vecC[i]->getSala1()->buscaPeli(op, busq)
				<< "---------------------------------" << endl;
		}
		s << "----------------------SALA 2----------------------" << endl;
		for (int i = 0; i < cant; i++) {
			s << "Tipo de sala: " << vecC[i]->getSala2()->getTipoSala() << endl
				<< vecC[i]->getSala2()->buscaPeli(op, busq)
				<< "---------------------------------" << endl;
		}
	}
	return s.str();
}

string ContCinema::muestraP() {
	stringstream s;
	s << vecC[0]->stringPrecios();
	return s.str();
}

string ContCinema::muestraMatrizA(int hor, string fec, int sal) {
	int h;
	if (hor <= 11) {
		h = 0;
	}else if (hor <= 17) {
		h = 1;
	}else h = 2;
	
	for (int i = 0; i < cant; i++) 
		if (vecC[i]->getSala1()->retornaFecha() == fec) 
			if (sal == 1) {
				return vecC[i]->getSala1()->retornaMaAsientos(h);
			}else if (sal == 2) {
				return vecC[i]->getSala2()->retornaMaAsientos(h);
			}
	return "Sala no encontrada";
}

string ContCinema::retornaEstadoAsient(int hor, string fec, int sal, string ident) {
	int h;
	if (hor <= 11) {
		h = 0;
	}else if (hor <= 17) {
		h = 1;
	}else h = 2;

	for (int i = 0; i < cant; i++)
		if (vecC[i]->getSala1()->retornaFecha() == fec)
			if (sal == 1) {
				return vecC[i]->getSala1()->retornaEstado(h, ident);
			}
			else if (sal == 2) {
				return vecC[i]->getSala2()->retornaEstado(h, ident);
			}
	return "";
}

void ContCinema::estadoAsiento(int hor, string fec, int sal,string ident,int est,string ced) {
	int h;
	if (hor <= 11) {
		h = 0;
	}else if (hor <= 17) {
		h = 1;
	}else h = 2;
	
	for (int i = 0; i < cant; i++)
		if (vecC[i]->getSala1()->retornaFecha() == fec)
			if (sal == 1) {
				vecC[i]->getSala1()->cambiaEstado(h, ident, est, ced);
			}else if (sal == 2) {
				vecC[i]->getSala2()->cambiaEstado(h, ident, est, ced);
			}
}

int ContCinema::montoTiquete(int numN, int numA, int s, string f) {
	int total;

	for (int i = 0; i < cant; i++)
		if (vecC[i]->getSala1()->retornaFecha() == f)
			if (s == 1) {
				if(vecC[i]->getSala1()->getTipoSala()=="VIP"){
					total = numN * vecC[i]->getNiVIP();
					total += numA * vecC[i]->getAdulVIP();
					return total;
				}else if(vecC[i]->getSala1()->getTipoSala()=="Regular"){
					total = numN * vecC[i]->getNiReg();
					total += numA * vecC[i]->getAdulReg();
					return total;
				}
			}
			else if (s == 2) {
				if (vecC[i]->getSala2()->getTipoSala() == "VIP") {
					total = numN * vecC[i]->getNiVIP();
					total += numA * vecC[i]->getAdulVIP();
					return total;
				}
				else if (vecC[i]->getSala2()->getTipoSala() == "Regular") {
					total = numN * vecC[i]->getNiReg();
					total += numA * vecC[i]->getAdulReg();
					return total;
				}
			}
	return 0;
}

string ContCinema::buscaNombrePelicula(string f, int s, int hor) {
	int h;
	if (hor <= 11) {
		h = 0;
	}else if (hor <= 17) {
		h = 1;
	}
	else h = 2;
	for (int i = 0; i < cant; i++)
		if (vecC[i]->getSala1()->retornaFecha() == f)
			if (s == 1) {
				return vecC[i]->getSala1()->retornaNombrePeli(h);
			}else if(s == 2) {
				return vecC[i]->getSala2()->retornaNombrePeli(h);
			}
	return "";
}
string ContCinema::MuestraIdentificadores(string fec, int sal, int hor, string ced) {
	int h=0;
	if (hor <= 11) {
		h = 0;
	}else if (hor <= 17) {
		h = 1;
	}
	for (int i = 0; i < cant; i++)
		if (vecC[i]->getSala1()->retornaFecha() == fec)
			if (sal == 1) {
				return vecC[i]->getSala1()->retornaAsientosComprados(h, ced);
			}else if (sal == 2) {
			return vecC[i]->getSala2()->retornaAsientosComprados(h, ced);
		}
			return "";
}

string ContCinema::toString(){
stringstream s;
	for (int i = 0; i < cant; i++)
		if(vecC[i]!=NULL)
			s << vecC[i]->toString();
	return s.str();
}



