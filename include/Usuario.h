#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
#include <vector>
#include "Vuelo.h"

using namespace std;


class Usuario
{
    public:
        Usuario();
        virtual ~Usuario();

        void setUsuario(string u);
        string getUsuario();
        void setContrasena(string c);
        string getContrasena();
        void setKm(float k);
        float getKm();

        //Métodos especializados
        void anadirVuelo(string par, string des, int num, int di, float pre, float k, int dur);
        void quitarVuelo(int num);
        void imprimirVuelos();
        void actualizarKm(float k);

    protected:

    private:
        string usuario;
        string contrasena;
        float km;

        vector <Vuelo> vuelos;

};

#endif // USUARIO_H
