#include"Cinema.h"


Cinema::Cinema(Sala* ptrSala1, Sala* ptrSala2){
	sala1 = ptrSala1;
	sala2 = ptrSala2;
	niReg = 3000;
	niVIP = 4500;
	adulReg = 5000;
	adulVIP = 6500;
}

	Cinema:: ~Cinema(){
		delete sala1;
		delete sala2;
		sala1 = NULL;
		sala2 = NULL;
	}

	Sala* Cinema::getSala1() { return sala1; }
	Sala* Cinema::getSala2(){return sala2;}
	int Cinema::getNiReg() { return niReg; }
	int Cinema::getNiVIP() { return niVIP; }
	int Cinema::getAdulReg() { return adulReg; }
	int Cinema::getAdulVIP() { return adulVIP; }

	void Cinema::setSala1(Sala* ptrSala1){ sala1 = ptrSala1; }
	void Cinema::setSala2(Sala* ptrSala2){ sala2 = ptrSala2; }
	void Cinema::setNiReg(int ng) { niReg = ng; }
	void Cinema::setNiVIP(int nv){niVIP=nv;}
	void Cinema::setAdulVIP(int av) { adulVIP = av; }
	void Cinema::setAdulReg(int ar) { adulReg = ar; }

	

	string Cinema::stringPrecios() {
		stringstream s;
		s << "----------PRECIOS----------" << endl
			<< "Ninnio sala regular: " << niReg << endl
			<< "Ninnio sala VIP: " << niVIP << endl
			<< "Adulto sala regular: " << adulReg << endl
			<< "Adulto sala VIP: " << adulVIP << endl
			<< "---------------------------" << endl;
		return s.str();
	}

	string Cinema::toString(){
		stringstream s;
		s << "**********SALAS**********" << endl;
		if(sala1!=NULL)
			s << "----------SALA 1----------" << endl
				<< "Sala 1" << sala1->toString() << endl;
		if(sala2!=NULL)
			s << "----------SALA 2----------" << endl
				<< "Sala 2" << sala2->toString() << endl;
		return s.str();
	}

	
