#include "ContCinema.h"

using namespace std;

int main() {

	string nom;					//Pelicula
	string gen;
	string tip;
	string dim;
	string tipoP;
	string sinop;
	string pai;
	int an;

	string fec;					//Funcion
	int ho;
	int mi;

	string tipS;				//Sala

	int op=0;					//Auxiliares
	string  busq;
	int sal;
	string fecha;
	string hora;
	int fil, col;
	string asient;
	int tiquetNi, tiqueteAdult;
	string selectA;
	int cont=0;
	string ced="";
	Sala* ptrSal1 = NULL;
	Sala* ptrSal2 = NULL;
	Pelicula* ptrPeli = NULL;
	Funcion* ptrFunc = NULL;
	Cinema* ptrCine = NULL;
	Asiento* ptrAsient = NULL;
	ContAsientos* CA = NULL;
	ContCinema* CO = new ContCinema();

	while(op != 3){
		system("CLS");
		cout << "Digite el tipo de usuario (Administrador o Cliente): " << endl;
		cout << "1) Administrador" << endl << "2) Cliente" << endl << "3) Salir " << endl;
		cout << "Usuario: ";
		cin >> op;
		system("CLS");

		switch (op) {
		case 1:
		do {
			ptrSal1 = new Sala();
			ptrSal2 = new Sala();
			cout << "\nDigite la fecha de las funciones (dia/mes/anio): " << endl;
			cin >> fec;
			if (CO->verificaFecha(fec) == false) {
				cout << "Ya existe un cinema con esta fecha.";
				system("PAUSE");
				break;
			}
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 3; j++) {
					system("CLS");
					cout << "---------------------------------MENU-----------------------------------------" << endl;
					cout << "                                SALA " << i + 1 << endl << endl;
					if (j == 0) {
						cout << "----------Ingrese los datos de la funcion de la manana----------" << endl;
					}else if (j == 1) {
						cout << "----------Ingrese los datos de la funcion de la tarde----------" << endl;
					}else if (j == 2) {
						cout << "----------Ingrese los datos de la funcion de la noche----------" << endl;
					}
					cout << "Pelicula " << j + 1 << endl;
					cout << "Digite el nombre: ";
					cin.ignore();
					getline(cin, nom);
					cout << "Digite el genero: ";
					getline(cin, gen);
					cout << "Digite el tipo (subtitulada o doblada): ";
					getline(cin, tip);
					cout << "Digite la dimension (2D o 3D): ";
					getline(cin, dim);
					cout << "Digite el tipo de publico (ninios o adultos): ";
					getline(cin, tipoP);
					cout << "Digite la sinopsis: ";
					getline(cin, sinop);
					cout << "Digite el pais en el que se creo: ";
					getline(cin, pai);
					cout << "Digite el annio de creacion: ";
					cin >> an;
					ptrPeli = new Pelicula(nom, gen, tip, dim, tipoP, sinop, pai, an);
					cout << "---------------------------------------------------" << endl;
					cout << "Digite la hora de la funcion (Formato 24h):" << endl;
					cout << "Hora: ";
					cin >> ho;
					cout << "Minutos: ";
					cin >> mi;
					ptrFunc = new Funcion(mi, ho, fec, ptrPeli);
					if (i == 0) {
						ptrSal1->ingresarFuncion(ptrFunc);
					}
					else {
						ptrSal2->ingresarFuncion(ptrFunc);
					}
					CA = new ContAsientos();
					for (int i = 0; i < 60; i++) {
						ptrAsient = new Asiento();
						fil = CA->getFilAct();
						col = CA->getColAct();
						asient = ptrAsient->identAsiento(fil, col);
						ptrAsient->setIdentificador(asient);
						CA->ingresaAsiento(ptrAsient);
					}
					if (i == 0) {
						ptrSal1->ingresaMatrizAsientos(CA);
					}
					else {
						ptrSal2->ingresaMatrizAsientos(CA);
					}
				}
				cout << "---------------------------------------------------" << endl;
				cout << "Digite el tipo de sala (VIP o Regular): " << endl;
				cin >> tipS;

				if (i == 0) {
					ptrSal1->setTipoSala(tipS);
				}
				else {
					ptrSal2->setTipoSala(tipS);
				}
			}
			ptrCine = new Cinema(ptrSal1, ptrSal2);
			CO->ingresaCinema(ptrCine);
			cout << "---------------------------------------------------" << endl;
			system("CLS");
			cout << "\n\nDesea ingresar los datos de las funciones de otro dia?\n";
			cout << "1) SI" << endl << "2) NO" << endl;
			cout << "Opcion: ";
			cin >> op;
		} while (op == 1);
		break;
		case 2:
			do {
				do {
					system("CLS");
					cout << "---------------------------------Menu de busqueda de pelicula-----------------------------------------" << endl
						<< "1) Desea hacer la busqueda por genero?" << endl
						<< "2) Desea hacer la busqueda por nombre?" << endl
						<< "3) Desea hacer la busqueda por tipo? (doblada o subtitulada)" << endl
						<< "4) Desea hacer la busqueda por dimenciones? (2D O 3D)" << endl
						<< "5) Desea hacer la busqueda por sala? (VIP o Regular)" << endl
						<< "6) Desea hacer la busqueda por tipo de publico? (ninios o adultos)" << endl
						<< "7) Salir" << endl
						<< "-------------------------------------------------------------------------------" << endl
						<< "   Digite su opcion: ";
					cin >> op;
					if (op == 7) break;
					cout << " Digite el dato de su busqueda: ";
					cin.ignore();
					getline(cin, busq);

					cout << CO->busquedaP(op, busq);
					system("PAUSE");
					cout << "\n\n-------------------------------------------------------------------------" << endl
						<< "1) Desea realizar otra busqueda de una pelicula?" << endl
						<< "2) Desea compra tiquetes?" << endl
						<< "-------------------------------------------------------------------------------" << endl
						<< "   Digite su opcion: ";
					cin >> op;
				} while (op == 1);
				do {
					if (op == 7) break;
					cout << "\n\n---------------------------------Menu de compra de tickets-----------------------------------------" << endl;
					cout << "Digite la sala que desea (1 o 2): ";
					cin >> sal;
					cout << "Digite la fecha de la pelicula(dia/mes/anio): ";
					cin >> fecha;
					cout << "Digite la hora de la funcion (Formato 24h):" << endl;
					cout << "Hora: ";
					cin >> ho;
					cout << "Minutos: ";
					cin >> mi;
					if (CO->muestraMatrizA(ho, fecha, sal) == "Sala no encontrada"){
						cout << "Sala no encontrada";
						op = 2;
					}else {
						op = 1;
					}
				} while (op == 2);
				do {
					if (op == 7) break;
					system("CLS");
					cout << "\n\n---------------------------------PANTALLA-----------------------------------------\n";
					cout << CO->muestraMatrizA(ho, fecha, sal) << endl << endl;
					cout<<"  V: Disponible  |  G: Seleccionado  |  R: Ocupado";
					cout << "\n\n-------------------------------------------------------------------------------" << endl <<endl;
					cout << CO->muestraP() << endl;
					cout << "---------------------------------------" << endl;
					cout << "Digite la cantidad de asientos que desea: ";
					cin >> cont;
					cout << "Digite los identificadores de los asientos que desea (Ejemplo: A8):" << endl;
					for (int k = 0; k < cont; k++) {
						cout << k + 1 << ") ";
						cin >> selectA;
						if ("V" == CO->retornaEstadoAsient(ho, fecha, sal, selectA)) {
							CO->estadoAsiento(ho, fecha, sal, selectA, 0, ced);
						}else {
							cout << "\n\nEl asiento seleccionado se encuentra ocupado" << endl;
							k--;
						}
					}
					system("CLS");
					cout << "\n\n---------------------------------PANTALLA-----------------------------------------\n";
					cout << CO->muestraMatrizA(ho, fecha, sal) << endl << endl;
					cout << "  V: Disponible  |  G: Seleccionado  |  R: Ocupado";
					cout << "\n\n-------------------------------------------------------------------------" << endl;
					cout << "1) Comprar los asientos" << endl;
					cout << "2) Cancelar la seleccion de asientos " << endl;
					cout << "Opcion: ";
					cin >> op;
					if (op == 1) {
						cout << "Ingrese su numero de cedula: ";
						cin >> ced;
						CO->estadoAsiento(ho, fecha, sal, selectA, 1, ced);
						do {
							if (op == 7) break;
							cout << "Los asientos comprados son: " << cont << endl;
							cout << "Digite la cantidad de tiquetes ninios que desea comprar: ";
							cin >> tiquetNi;
							cout << "Digite la cantidad de tiquetes adulto que desea comprar: ";
							cin >> tiqueteAdult;
						
							if (tiquetNi + tiqueteAdult == cont) {
								system("CLS");
								cout << "\n\n---------------------------------PANTALLA-----------------------------------------\n";
								cout << CO->muestraMatrizA(ho, fecha, sal) << endl << endl;
								cout << "  V: Disponible  |  G: Seleccionado  |  R: Ocupado";
								cout << "\n\n----------Informacion de la compra----------" << endl;
								cout << "Sala: " << sal << endl;
								cout << "Nombre de la pelicula: " << CO->buscaNombrePelicula(fecha, sal, ho) << endl;
								cout << "El monto a pagar es de: " << endl;
								cout << CO->montoTiquete(tiquetNi, tiqueteAdult, sal, fecha) << endl;
								cout << "Fecha de la funcion: " << fecha << endl;
								cout << "Hora de la funcion: " << ho << ":" << mi << endl;
								cout << "Cantidad de asientos de esta compra: " << cont << endl;
								cout << "Asientos totales del cliente: " << CO->MuestraIdentificadores(fecha, sal, ho, ced) << endl;
								system("PAUSE");
								op = 0;
							}else cout << "La cantidad de tiquetes no coinciden" << endl ;
						} while (op == 1);
					}else if (op == 2) {
						CO->estadoAsiento(ho, fecha, sal, selectA, 2, ced);
					}
				} while (op == 2);
			} while (op == 0);
		break;
		case 0:
			break;
	default:
		break;
	}
	}
	delete CO;
	return 0;
}




