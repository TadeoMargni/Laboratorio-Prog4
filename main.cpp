#include <iostream>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include "include/Experiencia.h"
#include "include/Turista.h"
#include "include/Alojamiento.h"
#include "include/TourGuiado.h"
#include "include/EventoCultural.h"
#include "include/DTFecha.h"
#include "include/DTExpe.h"

std::list<Experiencia*> experiencias;
std::map<std::string, Experiencia*> map_experiencias;

std::list<Turista*> turistas;
std::map<std::string, Turista*> map_turistas;

void coleccion_guardarExperiencia(Experiencia* exp){
	if  (map_experiencias.count(exp->getCodigoReserva())) {
		std::cerr << "Error: Ya existe una experiencia con el codigo de reserva " << exp->getCodigoReserva() << std::endl;
		return;
	}

	experiencias.push_back(exp);
	std::pair<std::string, Experiencia*> entry(exp->getCodigoReserva(), exp);
    map_experiencias.insert(entry);
}

Turista* coleccion_getTurista(std::string ci){
	return map_turistas[ci];
}

Experiencia* coleccion_getExperiencia(std::string codigoReserva){
	return map_experiencias[codigoReserva];
}

void coleccion_eliminarExperiencia(Experiencia* exp){

	std::list<Turista*> turistasEXP = exp -> getTuristas(); // Obtengo los turistas en la experiencia
	std::list<Turista*>::iterator it; //Para iterar
	for (it = turistasEXP.begin(); it != turistasEXP.end(); ++it) {
		(*it) -> eliminarExperiencia(exp); //  Elimino la experiencia de cada turista
	}
	experiencias.remove(exp); // Elimino la experiencia de la coleccion
	map_experiencias.erase(exp->getCodigoReserva());
	delete(exp); //liberamos memoria

}

void coleccion_guardarTurista(Turista* tur){
	if  (map_turistas.count(tur->getCi())) {
		std::cerr << "Error: Ya existe un turista con la CI " << tur->getCi() << std::endl;
		return;
	}

	turistas.push_back(tur);
	std::pair<std::string, Turista*> entry(tur->getCi(), tur);
    map_turistas.insert(entry);
}

void coleccion_eliminarTurista(Turista* tur){
	std::list<Experiencia*> experienciasTur = tur -> getExperiencias(); // Obtengo las experiencias del turista
	std::list<Experiencia*>::iterator it; //Para iterar
    for (it = experienciasTur.begin(); it != experienciasTur.end(); ++it) {
        (*it) -> eliminarTurista(tur); // Elimino el turista de cada experiencia
    }
    turistas.remove(tur); // Elimino el turista de la coleccion
    map_turistas.erase(tur->getCi());
    delete(tur);
}

void coleccion_vincularTuristayExperiencia(Turista* tur, Experiencia* exp){
	tur -> agregarExperiencia(exp);
	exp -> agregarTurista(tur);
}

void coleccion_desvincularTuristayExperiencia(Turista* tur, Experiencia* exp){

	std::list<Turista*> turistasExp = exp -> getTuristas();
	std::list<Experiencia*> experienciasTur = tur -> getExperiencias();
	const bool pertenece = experienciasTur.end() != std::find(experienciasTur.begin(), experienciasTur.end(), exp);

	if ((turistasExp.size() == 1) && (pertenece))  { // Turista es el unico en la experiencia se debe eliminar la misma para mantener consistencia
		std::cout << "El turista " << tur->getNombre() << " es el unico en la experiencia " << exp->getCodigoReserva() << ". Se eliminara la experiencia." << std::endl;
		coleccion_eliminarExperiencia(exp);

	} else {
		tur -> eliminarExperiencia(exp);
		exp -> eliminarTurista(tur);
	}
}


void parte_a(){
	//Crear los siguientes Alojamientos

	// codigoReserva: ALX5489 -- descripcion: Hotel Moderno -- precioBase: 30 -- fecha: 18/05/2020 -- hotel: Hotel Lindorf -- regimen: AllInclusive -- cantNoches: 5
	Alojamiento* a1 = new Alojamiento("ALX5489", "Hotel Moderno",
		30, new DTFecha(18, 5, 2020), "Hotel Lindorf", AllInclusive, 5);

	// codigoReserva: ALJ4789 -- descripcion: Todas las habitaciones con vista al mar -- precioBase: 100 -- fecha: 10/02/2025 -- hotel: Hotel SeaView -- regimen: MediaPension -- cantNoches: 15
	Alojamiento* a2 = new Alojamiento("ALJ4789", "Todas las habitaciones con vista al mar",
		100, new DTFecha(10, 2, 2025), "Hotel SeaView", MediaPension, 15);


	coleccion_guardarExperiencia(a1);
	coleccion_guardarExperiencia(a2);

	}

void parte_b(){
	//Crear los siguientes Tours

	//hay q hacerlo asi si no no compila en ++98
	std::set<std::string> l1;
	l1.insert("Plaza Independencia");
	l1.insert("Plaza Matriz");
	// codigoReserva: TGO4657 -- descripcion: Plazas de Montevideo -- precioBase: 10 -- fecha: 29/08/2024 -- agencia: Paseos SA -- lugaresVisitados: Plaza Independencia, Plaza Matriz
	TourGuiado* t1 = new TourGuiado("TGO4657", "Plazas de Montevideo",
		10, new DTFecha(29, 8, 2024), "Paseos SA", l1);

	//hay q hacerlo asi si no no compila en ++98
	std::set<std::string> l2;
	l2.insert("Puerta de la Ciudadela");
	l2.insert("Mausoleo");
	l2.insert("Cabildo");
	l2.insert("Palacio Salvo");
	// codigoReserva: TGR3257 -- descripcion: Puntos emblematicos -- precioBase: 5 -- fecha: 29/08/2024 -- agencia: Recorre -- lugaresVisitados: Puerta de la Ciudadela, Mausoleo, Cabildo, Palacio Salvo
	TourGuiado* t2 = new TourGuiado("TGR3257", "Puntos emblematicos",
		5, new DTFecha(29, 8, 2024), "Recorre", l2);

	coleccion_guardarExperiencia(t1); //Agrego los Tours a la coleccion
	coleccion_guardarExperiencia(t2);
}

void parte_c(){
	//Crear el siguiente Evento

	// codigoReserva: ECP1346 -- descripcion: Danza en el Solis -- precioBase: 10 -- fecha: 29/10/2025 -- ubicacion: Teatro Solis -- usoCupon: true
	EventoCultural* e1 = new EventoCultural("ECP1346", "Danza en el Solis", 10, new DTFecha(29, 10, 2025), "Teatro Solis", true);

	coleccion_guardarExperiencia(e1); //Agrego los Eventos a la coleccion
}

void parte_d(){
	//Imprimir cada uno de los objetos Experiencias utilizando getDT()
	//Sin turistas

	std::list<Experiencia*>::iterator it; //Creo una variable que it para iterar en la lista
	for (it = experiencias.begin(); it != experiencias.end(); ++it) {
		//Falta getDT, ademas en la parte_k se pide el mismo codigo pero getDT tiene que soportar turistas
		DTExpe* dt = (*it)->getDT(); //agarramos la exp it y creamos dtexpe con los dtexpe de esa exp
									// no necesita if pq no puede haber dt null aun
		std::cout << *dt << std::endl; // imprimimos con la sobrecarga d <<
		delete dt;		//liberamos memoria
	}
}

void parte_e(){
	//Crear los siguientes Turistas

	//ci: 49512789 -- nombre: Vanesa Castro -- email: vcastro.uy@servidor.net
	Turista* tur1 = new Turista ("49512789", "Vanesa Castro", "vcastro.uy@servidor.net");

	//ci: 15354420 -- nombre: Karen Santos -- email: karen.s89@internet.uy
	Turista* tur2 = new Turista ("15354420", "Karen Santos", "karen.s89@internet.uy");

	coleccion_guardarTurista(tur1); //Agrego Turistas a la coleccion
	coleccion_guardarTurista(tur2);
}

void parte_f(){
	//Imprimir cada uno de los Turistas utilizando toString()

	std::list<Turista*>::iterator it; //Para iterar
	for (it = turistas.begin(); it != turistas.end(); ++it) {
		std::cout << (*it)->toString() << std::endl;
	}
}

void parte_g(){
	//Registrar relaciones entre turistas y experiencias

	//4.951.278-9 (Vanesa Castro) - ALX5489 - ALJ4789 - TGR3257 - ECP1346
	//1.535.442-0 (Karen Santos) - TGO4657 - TGR3257

	Turista* tur1 = coleccion_getTurista("49512789"); //Get ambos turistas
	Turista* tur2 = coleccion_getTurista("15354420");

	Experiencia* expALX = coleccion_getExperiencia("ALX5489"); //Get todas las experiencias necesarias
	Experiencia* expALJ = coleccion_getExperiencia("ALJ4789");
	Experiencia* expTGR = coleccion_getExperiencia("TGR3257");
	Experiencia* expECP = coleccion_getExperiencia("ECP1346");
	Experiencia* expTGO = coleccion_getExperiencia("TGO4657");

	coleccion_vincularTuristayExperiencia(tur1, expALX);
	coleccion_vincularTuristayExperiencia(tur1, expALJ);
	coleccion_vincularTuristayExperiencia(tur1, expTGR);
	coleccion_vincularTuristayExperiencia(tur1, expECP);

	coleccion_vincularTuristayExperiencia(tur2, expTGO);
	coleccion_vincularTuristayExperiencia(tur2, expTGR);
}

void parte_h(){
	//Invocar listarExperiencias(10/12/2023, 0, 1000) para Vanesa Castro
	//imprimir el resultado un string por linea

	Turista* vanesa = coleccion_getTurista("49512789"); //Obtengo a Vanesa
	DTFecha* fechaConsulta = new DTFecha(10, 12, 2023);
	std::set<std::string> experienciasVanesa = vanesa -> listarExperiencias(fechaConsulta, 0, 1000); //Experiencias en una lista
	delete fechaConsulta;
	std::set<std::string>::iterator it; //Para iterar la lsita
	for (it = experienciasVanesa.begin(); it != experienciasVanesa.end(); ++it) {
		std::cout << *it << std::endl; //Imprimo cada experiencia con salto de linea
	}
}

void parte_i(){
	//Eliminar el objeto TGR3257 (Puntos emblematicos) de Experiencia

	Experiencia* exp = coleccion_getExperiencia("TGR3257");

	coleccion_eliminarExperiencia(exp); //Elimino la experiencia de la coleccion

}

void parte_j(){
	//Invocar listarExperiencias(10/10/2020, 0, 1000) para Karen Santos
	//imprimir el resultado un string por linea

	Turista* karen = coleccion_getTurista("15354420"); //Obtengo a karen
	DTFecha* fechaConsulta = new DTFecha(10, 10, 2020);
	std::set<std::string> experienciasKaren = karen -> listarExperiencias(fechaConsulta, 0, 1000); //Experiencias en una lista
	delete fechaConsulta;
	std::set<std::string>::iterator it; //Para iterar la lsita
	for (it = experienciasKaren.begin(); it != experienciasKaren.end(); ++it) {
		std::cout << *it << std::endl; //Imprimo cada experiencia con salto de linea
	}
}

void parte_k(){
	//Mismo codigo que parde d)
	//Imprimir cada uno de los objetos Experiencias utilizando getDT()

	std::list<Experiencia*>::iterator it; //Creo una variable que it para iterar en la lista
	for (it = experiencias.begin(); it != experiencias.end(); ++it) {
		//Falta getDT, getDT tiene que soportar turistas
		DTExpe* dt = (*it)->getDT();
		if(dt != NULL) { //luego de las partes anteriores puede q dt sea null
			std::cout << *dt << std::endl;
			delete dt;
		}
	}
}

void cleanUp(){
	//iteramos y liberamos memoria 6
	std::list<Experiencia*>::iterator itE;
    for(itE = experiencias.begin(); itE != experiencias.end(); ++itE){
        delete *itE;
    }
	experiencias.clear();
	map_experiencias.clear();

    std::list<Turista*>::iterator itT;
    for(itT = turistas.begin(); itT != turistas.end(); ++itT){
        delete *itT;
    }
	turistas.clear();
	map_turistas.clear();
}

int main() {
	std::cout << "parte_a" <<  std::endl;
	parte_a();
	std::cout << "parte_b" <<  std::endl;
	parte_b();
	std::cout << "parte_c" <<  std::endl;
	parte_c();
	std::cout << "parte_d" <<  std::endl;
	parte_d();
	std::cout << "parte_e" <<  std::endl;
	parte_e();
	std::cout << "parte_f" <<  std::endl;
	parte_f();
	std::cout << "parte_g" <<  std::endl;
	parte_g();
	std::cout << "parte_h" <<  std::endl;
	parte_h();
	std::cout << "parte_i" <<  std::endl;
	parte_i();
	std::cout << "parte_j" <<  std::endl;
	parte_j();
	std::cout << "parte_k" <<  std::endl;
	parte_k();
	std::cout << "cleanUp" <<  std::endl;
	cleanUp();
	std::cout << "fin" <<  std::endl;

	return 0;
}
