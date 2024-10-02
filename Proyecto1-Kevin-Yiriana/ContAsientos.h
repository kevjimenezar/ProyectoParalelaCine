#pragma once
#include "Asiento.h"


class ContAsientos {
	private:
		Asiento* matrizA[6][10];
		int filAct;
		int colAct;
	public:
		ContAsientos();
		virtual~ContAsientos();
		int getFilAct();
		int getColAct();
		void setFilAct(int);
		void setColAct(int);
		void ingresaAsiento(Asiento*);

		string buscarAsientosConsecutivos(int cantidad);

		void ocupadoEstado(string);
		void seleccionadoEstado(string);
		void disponibleEstado();
		string retornaIdentificador(string);
		string retornaEstIdent(string);
		string toString();

};