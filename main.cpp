/*
    Nombre: Luis Ignacio Gómez López
    Matrícula: A01644423
    Fecha: 6 de febrero de 2024

    Sistema que permite buscar vuelos en fechas específicas y buscar vuelos en función de algún detalle (como disponibilidad).
    El cliente también puede reservar un vuelo o cancelarlo.
    El sistema muestra todos los detalles del vuelo.
    Para reservar un vuelo, el sistema le pide al cliente que inicie sesión si ya se ha registrado.
    El sistema también le permite al cliente cancelar su reserva, si surge algún problema.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Usuario.h"
#include "Vuelo.h"

using namespace std;

vector <Usuario> arrayUsuarios;
vector <Vuelo> arrayVuelos;

void subirDatosUsuarios();
void subirDatosVuelos();
void buscarVuelos();
void reservarCancelarVuelo();
string iniciarSesion();
string crearCuenta();
int buscarIndiceUsuario(string nombreUsuario);
void revisarPasajeros();
void revisarVuelosUsuario();
void anadirVuelo();
void consultarKmAcumulados();


int main()
{
    subirDatosVuelos();

    //Menú de opciones
    int opcion = 0;
    while (true){
        cout << "Bienvenido(a), menu de opciones:" << endl;
        cout << "1-Buscar vuelos. 2-Reservar o cancelar un vuelo." << endl;
        cout << "3-Revisar los pasajeros en un vuelo." << endl;
        cout << "4-Revisar los vuelos reservados de un pasajero." << endl;
        cout << "5-Anadir un vuelo. 6-Consultar km acumulados." << endl;
        cout << "7.Salir" << endl;
        cout << "Elija la opcion: ";
        cin >> opcion;

        //Ejecutable del menú de opciones
        switch (opcion){
            case 1: cout << endl; buscarVuelos(); break;
            case 2: cout << endl; reservarCancelarVuelo(); break;
            case 3: cout << endl; revisarPasajeros(); break;
            case 4: cout << endl; revisarVuelosUsuario(); break;
            case 5: cout << endl; anadirVuelo(); break;
            case 6: cout << endl; consultarKmAcumulados(); break;
            case 7: return 1;
            default:{
                cout << "Opcion no disponible, por favor vuelva a intentar." << endl;
                break;
            }
        }
            cout << endl;
    }

    return 0;
}

void subirDatosUsuarios(){
    ifstream archivoUsuarios;
    string cadena;
    string nombreArchivo = "usuarios.txt";

    archivoUsuarios.open(nombreArchivo, ios::in);
    if(archivoUsuarios.fail()){
        cout<<"El archivo no se pudo abrir";
        exit(3);
    }

    int linea = 0;
    Usuario u;
    while (!archivoUsuarios.eof()){
        int atributo = linea % 3;
        getline(archivoUsuarios, cadena);
        switch (atributo){
            case 0:{
                u.setUsuario(cadena);
                linea++;
                break;
            }
            case 1:{
                u.setContrasena(cadena);
                linea++;
                break;
            }
            case 2:{
                u.setKm(stof(cadena));
                arrayUsuarios.push_back(u);
                linea++;
                break;
            }
        }

    }
}

void subirDatosVuelos(){
    ifstream archivoVuelos;
    string cadena;
    string nombreArchivo = "vuelos.txt";

    archivoVuelos.open(nombreArchivo, ios::in);
    if(archivoVuelos.fail()){
        cout<<"El archivo no se pudo abrir";
        exit(4);
    }

    int linea = 0;
    Vuelo v;
    while (!archivoVuelos.eof()){
        getline(archivoVuelos, cadena);

        int atributo = linea % 9;

        switch (atributo){
            case 0:{
                v.setPartida(cadena);
                linea++;
                break;
            }
            case 1:{
                v.setDestino(cadena);
                linea++;
                break;
            }
            case 2:{
                v.setNumero(stoi(cadena));
                linea++;
                break;
            }
            case 3:{
                v.setDia(stoi(cadena));
                linea++;
                break;
            }
            case 4:{
                v.setPrecio(stof(cadena));
                linea++;
                break;
            }
            case 5:{
                v.setKm(stof(cadena));
                linea++;
                break;
            }
            case 6:{
                v.setCapacidad(stoi(cadena));
                linea++;
                break;
            }
            case 7:{
                v.setOcupacion(stoi(cadena));
                linea++;
                break;
            }
            case 8:{
                v.setDuracion(stoi(cadena));
                arrayVuelos.push_back(v);
                linea++;
                break;
            }
        }

    }
}

void buscarVuelos(){
    int opcion = 0;
    while (opcion <= 0 || opcion > 7){
        cout << "Buscar vuelos por:" << endl;
        cout << "1-Partida. 2-Destino. 3-Numero de vuelo. 4-Dia." << endl;
        cout << "5-Precio. 6-Distancia. 7-Duracion." << endl;
        cout << "Elija la opcion: ";
        cin >> opcion;

        //Ejecutable del menú de opciones
        switch (opcion){
            case 1:{
                string partida;
                cout << "Ingrese la ciudad de partida: ";
                cin >> partida;
                cout << "Los vuelos con partida desde " << partida << " son:" << endl << endl;

                for (int i = 0; i < arrayVuelos.size(); i++){
                    if (arrayVuelos[i].getPartida() == partida){
                        arrayVuelos[i].imprimirDatosVuelo();
                        cout << endl;
                    }
                }
                break;
            }
            case 2:{
                string destino;
                cout << "Ingrese la ciudad de destino: ";
                cin >> destino;
                cout << "Los vuelos con destino a " << destino << " son:" << endl << endl;

                for (int i = 0; i < arrayVuelos.size(); i++){
                    if (arrayVuelos[i].getDestino() == destino){
                        arrayVuelos[i].imprimirDatosVuelo();
                        cout << endl;
                    }
                }
                break;
            }
            case 3:{
                int numeroDeVuelo;
                cout << "Ingrese el numero de vuelo: ";
                cin >> numeroDeVuelo;

                for (int i = 0; i < arrayVuelos.size(); i++){
                    if (arrayVuelos[i].getNumero() == numeroDeVuelo){
                        cout << "El vuelo es el siguiente: " << endl << endl;
                        arrayVuelos[i].imprimirDatosVuelo();
                        cout << endl;
                    }
                }
                break;
            }
            case 4:{
                int dia;
                cout << "Ingrese el dia de partida: ";
                cin >> dia;
                cout << "Los vuelos con partida el dia " << dia << " son:" << endl << endl;

                for (int i = 0; i < arrayVuelos.size(); i++){
                    if (arrayVuelos[i].getDia() == dia){
                        arrayVuelos[i].imprimirDatosVuelo();
                        cout << endl;
                    }
                }
                break;
            }
            case 5:{
                int maximo;
                cout << "Ingrese el precio maximo: ";
                cin >> maximo;
                cout << "Los vuelos con precio maximo de " << maximo << " son:" << endl << endl;

                for (int i = 0; i < arrayVuelos.size(); i++){
                    if (arrayVuelos[i].getPrecio() <= maximo){
                        arrayVuelos[i].imprimirDatosVuelo();
                        cout << endl;
                    }
                }
                break;
            }
            case 6:{
                float distancia;
                cout << "Ingrese la distancia maxima: ";
                cin >> distancia;
                cout << "Los vuelos con maxima distancia de " << distancia << " son:" << endl << endl;

                for (int i = 0; i < arrayVuelos.size(); i++){
                    if (arrayVuelos[i].getKm() <= distancia){
                        arrayVuelos[i].imprimirDatosVuelo();
                        cout << endl;
                    }
                }
                break;
            }
            case 7:{
                int duracion;
                cout << "Ingrese la duracion maxima: ";
                cin >> duracion;
                cout << "Los vuelos con duracion maxima de " << duracion << " son:" << endl << endl;

                for (int i = 0; i < arrayVuelos.size(); i++){
                    if (arrayVuelos[i].getDuracion() <= duracion){
                        arrayVuelos[i].imprimirDatosVuelo();
                        cout << endl;
                    }
                }
                break;
            }
            default:{
                cout << "Opcion no disponible, por favor vuelva a intentar." << endl;
                break;
            }
        }
    }
}

void reservarCancelarVuelo(){
    string sesionUsuario = ""; //Nombre de usuario del usuario
    int opcion = 0;
    while (opcion !=1 && opcion != 2){
        cout << "1-Reservar un vuelo. 2-Cancelar un vuelo." << endl;
        cout << "Elija la opcion: ";
        cin >> opcion;

        //Ejecutable del menú de opciones
        switch (opcion){
            case 1:{
                //Pide al usuario que inicie sesion
                int opSesion = 0;
                while (opSesion !=1 && opSesion != 2){
                    cout << "1-Iniciar sesion. 2-Crear cuenta." << endl;
                    cout << "Elija la opcion: ";
                    cin >> opSesion;

                    switch (opSesion){
                        case 1:{
                            sesionUsuario = iniciarSesion();
                            if (sesionUsuario == "NoExisteElUsuario"){
                                cout << "No existe su usuario. Por favor registrese." << endl;
                                sesionUsuario = crearCuenta();
                                break;
                            }
                            break;
                        }
                        case 2:{
                            sesionUsuario = crearCuenta();
                            break;
                        }
                        default:{
                            cout << "Opcion no disponible, por favor vuelva a intentar." << endl;
                            break;
                        }
                    }
                }

                int ingNumVuelo = 0;
                while (ingNumVuelo < 1){
                    cout << "Ingrese el numero de vuelo al que desea reservar: ";
                    cin >> ingNumVuelo;

                    //Revisa que el número de vuelo exista, lo agrega y actualiza los kilómetros que ya tiene
                    for (int i = 0; i < arrayVuelos.size(); i++){
                        if (arrayVuelos[i].getNumero() == ingNumVuelo){
                            arrayVuelos[i].anadirPasajero(sesionUsuario);
                            float kilometrosAgregar = arrayVuelos[i].getKm();

                            //Agrega el vuelo a la lista de vuelos del usuario y el usuario a la lista de ocupantes del vuelo
                            int indiceDeUsuario = buscarIndiceUsuario(sesionUsuario);
                            arrayUsuarios[indiceDeUsuario].anadirVuelo(arrayVuelos[i].getPartida(), arrayVuelos[i].getDestino(), arrayVuelos[i].getNumero(), arrayVuelos[i].getDia(), arrayVuelos[i].getPrecio(), arrayVuelos[i].getKm(), arrayVuelos[i].getDuracion());
                            arrayVuelos[i].anadirPasajero(sesionUsuario);

                            //Total a pagar
                            float precioAPagar;
                            float revisarKmUsuario = arrayUsuarios[indiceDeUsuario].getKm();
                            if (revisarKmUsuario > 50000){
                                precioAPagar = arrayVuelos[i].getPrecio() * 0.6;
                                cout << "Se ha aplicado el descuento del 40%." << endl;
                            }
                            else {
                                precioAPagar = arrayVuelos[i].getPrecio();
                            }

                            cout << "Se ha completado la reservacion para el vuelo " << arrayVuelos[i].getNumero() << " con destino a " << arrayVuelos[i].getDestino() << "." << endl;
                            cout << "El total a pagar es de: $" << precioAPagar << endl;

                            arrayUsuarios[indiceDeUsuario].actualizarKm(kilometrosAgregar);
                            return;
                        }
                    }
                    cout << "El vuelo no existe, vuelva a intentar." << endl;
                }
                break;
            }
            case 2:{
                sesionUsuario = iniciarSesion();
                if (sesionUsuario == "NoExisteElUsuario"){
                    cout << "No existe su usuario. Reinicie el programa." << endl;
                    exit(6);
                }

                int ingNumVuelo = 0;
                while (ingNumVuelo < 1){
                    cout << "Ingrese el numero de vuelo que desea cancelar: ";
                    cin >> ingNumVuelo;

                    //Revisa que el número de vuelo exista, lo quita y actualiza los datos en el vuelo y el usuario
                    if (ingNumVuelo > 0){
                        for (int i = 0; i < arrayVuelos.size(); i++){
                            if (arrayVuelos[i].getNumero() == ingNumVuelo){
                                arrayVuelos[i].quitarPasajero(sesionUsuario);
                                int indiceDeUsuario = buscarIndiceUsuario(sesionUsuario);
                                float kilometrosQuitar = arrayVuelos[i].getKm() * (-1);
                                arrayUsuarios[indiceDeUsuario].actualizarKm(kilometrosQuitar);
                                arrayUsuarios[indiceDeUsuario].quitarVuelo(ingNumVuelo);
                                cout << "El vuelo " << arrayVuelos[i].getNumero() << " con destino a " << arrayVuelos[i].getDestino() << " ha sido cancelado." << endl;
                                return;
                            }
                        }
                    }
                    cout << "El vuelo no existe, vuelva a intentar." << endl;
                }
                break;
            }
            default:{
                cout << "Opcion no disponible, por favor vuelva a intentar." << endl;
                break;
            }
        }
    }
}

//Valida que el usuario exista y devuelve el nombre de usuario
string iniciarSesion(){
    subirDatosUsuarios();
    string ingUsuario = "";
    string ingContrasena = " ";
    cout << "Ingrese su usuario: ";
    cin >> ingUsuario;

    //Verifica que el usuario exista
    for (int i = 0; i < arrayUsuarios.size(); i++){
        if (ingUsuario == arrayUsuarios[i].getUsuario()){
            //Verifica su contrasena
            cout << "Ingrese su contrasena: ";
            cin >> ingContrasena;
            while (ingContrasena != arrayUsuarios[i].getContrasena()){
                cout << "Contrasena incorrecta, vuelva a intentar: ";
                cin >> ingContrasena;
            }
            return ingUsuario;
        }
    }
    return "NoExisteElUsuario";
}

//Crea una cuenta y devuelve el nombre de usuario
string crearCuenta(){
    subirDatosUsuarios();
    Usuario n;

    //Pide los datos del nuevo usuario
    string ingUsuario, ingContrasena;
    //Revisa que el usuario no exista
    bool permiteUsuario = false;
    while (permiteUsuario == false){
        bool usuarioRepedito = false;
        cout << "Ingrese su nuevo usuario: ";
        cin >> ingUsuario;
        for (int i = 0; i < arrayUsuarios.size(); i++){
            if (arrayUsuarios[i].getUsuario() == ingUsuario){
                usuarioRepedito = true;
                cout << "El nombre de usuario ya existe, intente de nuevo." << endl;
                break;
            }
        }
        if (usuarioRepedito == false){
            permiteUsuario = true;
        }
    }
    n.setUsuario(ingUsuario);
    cout << "Ingrese su contrasena: ";
    cin >> ingContrasena;
    n.setContrasena(ingContrasena);
    n.setKm(0);

    arrayUsuarios.push_back(n);

    ofstream archUsuarios;
    archUsuarios.open("usuarios.txt", ios::out);

    if(archUsuarios.fail()){
        cout<<"El archivo no se pudo abrir";
        exit(7);
    }

    for (int i = 0; i < arrayUsuarios.size(); i++){
        archUsuarios << arrayUsuarios[i].getUsuario() << endl;
        archUsuarios << arrayUsuarios[i].getContrasena() << endl;
        archUsuarios << arrayUsuarios[i].getKm() << endl;
    }

    archUsuarios.close();
    return ingUsuario;
}

//Busca el indice de usuario en la lista de usuarios
int buscarIndiceUsuario(string nombreUsuario){
    for (int i = 0; i < arrayUsuarios.size(); i++){
        if (arrayUsuarios[i].getUsuario() == nombreUsuario){
            return i;
        }
    }
}

//Revisa los pasajeros de un vuelo
void revisarPasajeros(){
    cout << "Ingrese el numero de vuelo: ";
    int num;
    cin >> num;

    //Busca que el número de vuelo exista
    for (int i = 0; i < arrayVuelos.size(); i++){
        if (arrayVuelos[i].getNumero() == num){
            cout << "Los pasajeros del vuelo " << num << " son:" << endl << endl;
            arrayVuelos[i].imprimirPasajeros();
            return;
        }
    }
    //Si el número de vuelo no existe
    cout << "No existe el numero de vuelo." << endl;
        return;
}

//Revisa los vuelos a los que el usuario pertenece
void revisarVuelosUsuario(){
    string usuario = iniciarSesion();
    int indiceUsuario = buscarIndiceUsuario(usuario);

    arrayUsuarios[indiceUsuario].imprimirVuelos();

}

void anadirVuelo(){
    Vuelo n;
    string ingPartida;
    string ingDestino;
    int ingNumero;
    int ingDia;
    int ingCapacidad;
    int ingDuracion;
    float ingPrecio;
    float ingKm;

    //Ingresa los datos del vuelo
    cout << "Ingrese la ciudad de partida: ";
    cin >> ingPartida;
    n.setPartida(ingPartida);
    cout << "Ingrese la ciudad de destino: ";
    cin >> ingDestino;
    n.setDestino(ingDestino);
    cout << "Ingrese el numero de vuelo: ";
    cin >> ingNumero;
    n.setNumero(ingNumero);
    cout << "Ingrese el dia del vuelo: ";
    cin >> ingDia;
    n.setDia(ingDia);
    cout << "Ingrese el precio del vuelo: ";
    cin >> ingPrecio;
    n.setPrecio(ingPrecio);
    cout << "Ingrese la distancia del vuelo: ";
    cin >> ingKm;
    n.setKm(ingKm);
    cout << "Ingrese la capacidad del vuelo: ";
    cin >> ingCapacidad;
    n.setCapacidad(ingCapacidad);
    n.setOcupacion(0);
    cout << "Ingrese la duracion del vuelo: ";
    cin >> ingDuracion;
    n.setDuracion(ingDuracion);

    arrayVuelos.push_back(n);

    //Abre el archivo
    ofstream archivo;
    archivo.open("vuelos.txt", ios::out);

    if(archivo.fail()){
        cout<<"El archivo no se pudo abrir";
        exit(8);
    }

    //Añade los vuelos ya existentes al documento
    for (int i = 0; i < arrayVuelos.size(); i++){
        archivo << arrayVuelos[i].getPartida() << endl;
        archivo << arrayVuelos[i].getDestino() << endl;
        archivo << arrayVuelos[i].getNumero() << endl;
        archivo << arrayVuelos[i].getDia() << endl;
        archivo << arrayVuelos[i].getPrecio() << endl;
        archivo << arrayVuelos[i].getKm() << endl;
        archivo << arrayVuelos[i].getCapacidad() << endl;
        archivo << arrayVuelos[i].getOcupacion() << endl;
        archivo << arrayVuelos[i].getDuracion() << endl;
    }

    //Finaliza el proceso
    archivo.close();
    cout << "El vuelo ha sido anadido." << endl;
}

void consultarKmAcumulados(){
    string sesion = iniciarSesion();
    int indiceUsuario = buscarIndiceUsuario(sesion);

    float kmAcumulados = arrayUsuarios[indiceUsuario].getKm();
    cout << "Los kilometros acumulados son: " << kmAcumulados << " km." << endl;
}
