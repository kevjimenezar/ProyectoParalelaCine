#include "ContCinema.h"

using namespace std;


void llenarAsientosAleatorios(ContAsientos* contAsientos) {
	srand((unsigned)time(0));

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 10; j++) {
			Asiento* asiento = new Asiento();

			int estadoAleatorio = rand() % 2; // 0 para 'V', 1 para 'R'
			if (estadoAleatorio == 0) {
				asiento->setEstado('V'); // Espacio Disponible o Vacío
			}
			else {
				asiento->setEstado('R'); // Espacio Reservado
				asiento->setCedula("Ced-" + to_string(rand() % 10000 + 10000)); // Cedula aleatoria
			}

			asiento->setIdentificador(asiento->identAsiento(i, j));
			contAsientos->ingresaAsiento(asiento);
		}
	}
}

void crearDatosQuemados(ContCinema* contCinema) {

	// Crear las películas
	Pelicula* peliculas[] = {
		new Pelicula("Interstellar", "Ciencia Ficcion", "Subtitulada", "2D", "Adultos", "Exploracion espacial", "USA", 2014),
		new Pelicula("The Dark Knight", "Accion", "Doblada", "2D", "Adultos", "Superheroes y crimen", "USA", 2008),
		new Pelicula("Inception", "Thriller", "Subtitulada", "3D", "Adultos", "Suenos y realidad", "USA", 2010),
		new Pelicula("Toy Story", "Animacion", "Doblada", "2D", "Ninios", "Aventura infantil", "USA", 1995),
		new Pelicula("Avengers: Endgame", "Accion", "Subtitulada", "3D", "Adultos", "Superheroes", "USA", 2019),
		new Pelicula("La La Land", "Musical", "Doblada", "2D", "Adultos", "Suenos y amor", "USA", 2016),
		new Pelicula("Parasite", "Thriller", "Subtitulada", "2D", "Adultos", "Clase y sociedad", "Corea del Sur", 2019),
		new Pelicula("Frozen II", "Animacion", "Doblada", "2D", "Ninios", "Aventura magica", "USA", 2019),
		new Pelicula("Joker", "Drama", "Subtitulada", "2D", "Adultos", "Psicologia y crimen", "USA", 2019),
		new Pelicula("The Matrix", "Ciencia Ficcion", "Subtitulada", "2D", "Adultos", "Realidad virtual", "USA", 1999),
		new Pelicula("Coco", "Animacion", "Doblada", "2D", "Ninios", "Familia y tradiciones", "Mexico", 2017),
		new Pelicula("Spider-Man: No Way Home", "Accion", "Subtitulada", "3D", "Adultos", "Superheroes y multiverso", "USA", 2021)
	};


	// Crear funciones para las películas
	Funcion* funciones[] = {
		new Funcion(10, 9, "10/10/2024", peliculas[0]),   // Mañana
		new Funcion(15, 14, "10/10/2024", peliculas[1]),  // Tarde
		new Funcion(20, 19, "10/10/2024", peliculas[2]),  // Noche
		new Funcion(5, 10, "10/10/2024", peliculas[3]),   // Mañana
		new Funcion(25, 15, "10/10/2024", peliculas[4]),  // Tarde
		new Funcion(30, 20, "10/10/2024", peliculas[5]),  // Noche
		new Funcion(45, 11, "11/10/2024", peliculas[6]),  // Mañana
		new Funcion(50, 16, "11/10/2024", peliculas[7]),  // Tarde
		new Funcion(35, 21, "11/10/2024", peliculas[8]),  // Noche
		new Funcion(55, 9, "11/10/2024", peliculas[9]),   // Mañana
		new Funcion(40, 14, "11/10/2024", peliculas[10]), // Tarde
		new Funcion(25, 19, "11/10/2024", peliculas[11])  // Noche
	};

	// Crear las salas
	Sala* sala1 = new Sala();
	Sala* sala2 = new Sala();
	Sala* sala3 = new Sala();
	Sala* sala4 = new Sala();

	// Crear contenedores de asientos aleatorios
	ContAsientos* contAsientosSala1_1 = new ContAsientos();
	ContAsientos* contAsientosSala1_2 = new ContAsientos();
	ContAsientos* contAsientosSala1_3 = new ContAsientos();

	ContAsientos* contAsientosSala2_1 = new ContAsientos();
	ContAsientos* contAsientosSala2_2 = new ContAsientos();
	ContAsientos* contAsientosSala2_3 = new ContAsientos();

	ContAsientos* contAsientosSala3_1 = new ContAsientos();
	ContAsientos* contAsientosSala3_2 = new ContAsientos();
	ContAsientos* contAsientosSala3_3 = new ContAsientos();

	ContAsientos* contAsientosSala4_1 = new ContAsientos();
	ContAsientos* contAsientosSala4_2 = new ContAsientos();
	ContAsientos* contAsientosSala4_3 = new ContAsientos();

	llenarAsientosAleatorios(contAsientosSala1_1);
	llenarAsientosAleatorios(contAsientosSala1_2);
	llenarAsientosAleatorios(contAsientosSala1_3);

	llenarAsientosAleatorios(contAsientosSala2_1);
	llenarAsientosAleatorios(contAsientosSala2_2);
	llenarAsientosAleatorios(contAsientosSala2_3);

	llenarAsientosAleatorios(contAsientosSala3_1);
	llenarAsientosAleatorios(contAsientosSala3_2);
	llenarAsientosAleatorios(contAsientosSala3_3);

	llenarAsientosAleatorios(contAsientosSala4_1);
	llenarAsientosAleatorios(contAsientosSala4_2);
	llenarAsientosAleatorios(contAsientosSala4_3);

	// Asignar las funciones y los contenedores de asientos a las salas
	sala1->ingresarFuncion(funciones[0]);
	sala1->ingresarFuncion(funciones[1]);
	sala1->ingresarFuncion(funciones[2]);
	sala1->ingresaMatrizAsientos(contAsientosSala1_1);
	sala1->ingresaMatrizAsientos(contAsientosSala1_2);
	sala1->ingresaMatrizAsientos(contAsientosSala1_3);
	sala1->setTipoSala("VIP");

	sala2->ingresarFuncion(funciones[3]);
	sala2->ingresarFuncion(funciones[4]);
	sala2->ingresarFuncion(funciones[5]);
	sala2->ingresaMatrizAsientos(contAsientosSala2_1);
	sala2->ingresaMatrizAsientos(contAsientosSala2_2);
	sala2->ingresaMatrizAsientos(contAsientosSala2_3);
	sala2->setTipoSala("Regular");

	sala3->ingresarFuncion(funciones[6]);
	sala3->ingresarFuncion(funciones[7]);
	sala3->ingresarFuncion(funciones[8]);
	sala3->ingresaMatrizAsientos(contAsientosSala3_1);
	sala3->ingresaMatrizAsientos(contAsientosSala3_2);
	sala3->ingresaMatrizAsientos(contAsientosSala3_3);
	sala3->setTipoSala("VIP");

	sala4->ingresarFuncion(funciones[9]);
	sala4->ingresarFuncion(funciones[10]);
	sala4->ingresarFuncion(funciones[11]);
	sala4->ingresaMatrizAsientos(contAsientosSala4_1);
	sala4->ingresaMatrizAsientos(contAsientosSala4_2);
	sala4->ingresaMatrizAsientos(contAsientosSala4_3);
	sala4->setTipoSala("Regular");

	// Crear los cines y agregarlos al contenedor de cines
	Cinema* cine1 = new Cinema(sala1, sala2);
	Cinema* cine2 = new Cinema(sala3, sala4);

	cine1->setNiReg(10);
	cine1->setNiVIP(50);
	cine1->setAdulReg(20);
	cine1->setAdulVIP(70);

	cine2->setNiReg(15);
	cine2->setNiVIP(30);
	cine2->setAdulReg(25);
	cine2->setAdulVIP(50);

	contCinema->ingresaCinema(cine1);
	contCinema->ingresaCinema(cine2);
}



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
	crearDatosQuemados(CO);

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
						<< "3) Desea hacer la busqueda por tipo? (Doblada o Subtitulada)" << endl
						<< "4) Desea hacer la busqueda por dimensiones? (2D O 3D)" << endl
						<< "5) Desea hacer la busqueda por sala? (VIP o Regular)" << endl
						<< "6) Desea hacer la busqueda por tipo de publico? (Infantil o Adultos)" << endl
						<< "7) Desea hacer la busqueda por asientos consecutivos disponibles?" << endl
						<< "8) Salir" << endl
						<< "-------------------------------------------------------------------------------" << endl
						<< "   Digite su opcion: ";
					cin >> op;
					if (op == 8) break;
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
					if (op == 8) break;
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
					if (op == 8) break;
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
							if (op == 8) break;
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




