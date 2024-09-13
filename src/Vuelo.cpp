#include "Vuelo.h"
#include <iostream>

using namespace std;

Vuelo::Vuelo()
{
    partida = "";
    destino = "";
    numero = 0;
    dia = 0;
    precio = 0.0;
    km = 0.0;
    capacidad = 0;
    ocupacion = 0;
    duracion = 0;
}

Vuelo::~Vuelo()
{
    //dtor
}

//Métodos modificadores y accesores
void Vuelo::setPartida(string p){
    partida = p;
}

string Vuelo::getPartida(){
    return partida;
}

void Vuelo::setDestino(string d){
    destino = d;
}

string Vuelo::getDestino(){
    return destino;
}

void Vuelo::setNumero(int n){
    numero = n;
}

int Vuelo::getNumero(){
    return numero;
}

void Vuelo::setDia(int d){
    dia = d;
}

int Vuelo::getDia(){
    return dia;
}

void Vuelo::setPrecio(float p){
    precio = p;
}

float Vuelo::getPrecio(){
    return precio;
}

void Vuelo::setKm(float k){
    km = k;
}

float Vuelo::getKm(){
    return km;
}

void Vuelo::setCapacidad(int c){
    capacidad = c;
}

int Vuelo::getCapacidad(){
    return capacidad;
}

void Vuelo::setOcupacion(int o){
    ocupacion = o;
}

int Vuelo::getOcupacion(){
    return ocupacion;
}

void Vuelo::setDuracion(int d){
    duracion = d;
}

int Vuelo::getDuracion(){
    return duracion;
}

//Métodos especializados
void Vuelo::imprimirDatosVuelo(){
    cout << "Partida: " << partida << endl;
    cout << "Destino: " << destino << endl;
    cout << "Numero de vuelo: " << numero << endl;
    cout << "Dia: " << dia << endl;
    cout << "Precio: " << precio << endl;
    cout << "Distancia: " << km << endl;
    cout << "Duracion: " << duracion << endl;
}

void Vuelo::anadirPasajero(string u){
    listaPasajeros.push_back(u);
    ocupacion++;
}

void Vuelo::quitarPasajero(string u){
    for (int i = 0; i < listaPasajeros.size(); i++){
        if (listaPasajeros[i] == u){
            listaPasajeros.erase(listaPasajeros.begin(), listaPasajeros.begin() + i);
            ocupacion--;
        }
    }
}

void Vuelo::imprimirPasajeros(){
    cout << "Pasajeros:" << endl;
    for (int i = 0; i < listaPasajeros.size(); i++){
        cout << listaPasajeros[i] << endl;
    }
}
