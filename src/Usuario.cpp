#include "Usuario.h"
#include "Vuelo.h"
#include <iostream>

using namespace std;

Usuario::Usuario()
{
    usuario = "";
    contrasena = "";
    km = 0;
}

Usuario::~Usuario()
{
    //dtor
}

//Métodos modificadores y accesores
void Usuario::setUsuario(string u){
    usuario = u;
}

string Usuario::getUsuario(){
    return usuario;
}

void Usuario::setContrasena(string c){
    contrasena = c;
}

string Usuario::getContrasena(){
    return contrasena;
}

void Usuario::setKm(float k){
    km = k;
}

float Usuario::getKm(){
    return km;
}

void Usuario::anadirVuelo(string par, string des, int num, int di, float pre, float k, int dur)
{
    Vuelo v;
    v.setPartida(par);
    v.setDestino(des);
    v.setNumero(num);
    v.setDia(di);
    v.setPrecio(pre);
    v.setKm(k);
    v.setDuracion(dur);

    vuelos.push_back(v);
}

void Usuario::quitarVuelo(int num)
{
    for (int i = 0; i < vuelos.size(); i++){
        if (vuelos[i].getNumero() == num){
            vuelos.erase(vuelos.begin(), vuelos.begin() + i);
        }
    }
}

void Usuario::imprimirVuelos()
{
    for (int i = 0; i < vuelos.size(); i++){
        cout << endl;
        vuelos[i].imprimirDatosVuelo();
    }
}

void Usuario::actualizarKm(float k){
    km += k;
}
