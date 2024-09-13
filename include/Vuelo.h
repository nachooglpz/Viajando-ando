#ifndef VUELO_H
#define VUELO_H
#include <iostream>
#include <vector>

using namespace std;


class Vuelo
{
    public:
        Vuelo();
        virtual ~Vuelo();

        //Métodos modificadores y accesores
        void setPartida(string p);
        string getPartida();
        void setDestino(string d);
        string getDestino();
        void setNumero(int n);
        int getNumero();
        void setDia(int d);
        int getDia();
        void setPrecio(float p);
        float getPrecio();
        void setKm(float k);
        float getKm();
        void setCapacidad(int c);
        int getCapacidad();
        void setOcupacion(int o);
        int getOcupacion();
        void setDuracion(int d);
        int getDuracion();


        //Métodos especializados
        void imprimirDatosVuelo();
        void anadirPasajero(string u);
        void quitarPasajero(string u);
        void imprimirPasajeros();


    protected:

    private:

        string partida;
        string destino;
        int numero;
        int dia;
        float precio;
        float km;
        int capacidad;
        int ocupacion;
        int duracion;

        vector <string> listaPasajeros;
};

#endif // VUELO_H
