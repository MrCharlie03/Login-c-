#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <fstream>

using namespace std;


int main() {
    

    //Variables hundir la flota 
    char tablero[6][6] = {{'~','~','~','~','~','~'},
                          {'~','~','~','~','~','~'},
                          {'~','~','~','~','~','~'},
                          {'~','~','~','~','~','~'},
                          {'~','~','~','~','~','~'},
                          {'~','~','~','~','~','~'}};
    //termina variable hundir la flota
    
    srand(time(0));
    int posiciones[3][2];
    int barcos = 0, disparos = 0, aciertos = 0;
    int opcion;

    cout << "Seleccione una Juego: " << endl;
    cout << "1. Ejecutar Hundir la flota" << endl;
    cout << "3. Registrar nuevo usuario" << endl;

    cin >> opcion;

    switch (opcion) {
        case 1:
            // Generar aleatoriamente las posiciones de los barcos
            while(barcos < 3) {
                int fila, columna;
                fila = rand() % 6;
                columna = rand() % 6;
                bool disponible = true;
                for(int i = 0; i < barcos; i++) {
                    if(fila == posiciones[i][0] && columna == posiciones[i][1]) {
                        disponible = false;
                        break;
                    }
                }
                if(disponible) {
                    posiciones[barcos][0] = fila;
                    posiciones[barcos][1] = columna;
                    barcos++;
                }
            }

            do {
                for(int i = 0; i < 6; i++) {
                    for(int j = 0; j < 6; j++) {
                        cout << tablero[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << "Introduce la fila (1-6): ";
                int fila;
                cin >> fila;
                cout << "Introduce la columna (1-6): ";
                int columna;
                cin >> columna;
                fila--;
                columna--;
                bool acierto = false;
                for(int i = 0; i < barcos; i++) {
                    if(fila == posiciones[i][0] && columna == posiciones[i][1]) {
                        cout << "¡Has acertado!" << endl;
                        acierto = true;
                        aciertos++;
                        break;
                    }
                }
                if(acierto) {
                    tablero[fila][columna] = 'X';
                } else if(tablero[fila][columna] == '~') {
                    cout << "Has fallado" << endl;
                    tablero[fila][columna] = 'O';
                } else {
                    cout << "Ya has disparado en esa casilla" << endl;
                }
                disparos++;
            } while(aciertos < 3);
            cout << "¡Felicidades, has hundido todos los barcos en " << disparos << " disparos!" << endl;
              case 2:
        // ...
        break;
    case 3:
        {
            string usuario, contrasena;
            cout << "Ingrese el nombre de usuario: ";
            cin >> usuario;
            cout << "Ingrese la contraseña: ";
            cin >> contrasena;

            // Agregar el usuario y la contraseña al archivo de texto
            ofstream archivo("usuarios.txt", ios::app);
            if(archivo.is_open()) {
                archivo << usuario << ":" << contrasena << endl;
                archivo.close();
                cout << "Usuario registrado exitosamente" << endl;
            } else {
                cout << "Error al abrir el archivo" << endl;
            }
        }
        break;
    default:
        cout << "Opción inválida" << endl;
        break;
}
    
return 0;
}



 