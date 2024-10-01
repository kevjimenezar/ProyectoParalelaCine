#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Asiento {
private:
	string cedula;
	char estado;
	string identificador;

public:
	Asiento();

	virtual ~Asiento();

	string getCedula();
	char getEstado();
	string getIdentificador();

	void setCedula(string);
	void setEstado(char);
	void setIdentificador(string);

	string identAsiento(int,int);
	string toString();


};