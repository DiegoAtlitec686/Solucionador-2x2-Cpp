#include <graphics.h>
#include <iostream>
#include <conio.h> 
//ATLITEC SARABIA DIEGO ALEJANDRO
#include "utils.cpp"
#include "constantes.cpp"   

using namespace std; 

void pintarPlano();
void menu_funciones(Plano);
void menu_punto(Plano);
void menu_recta(Plano);
void menu_interseccion(Plano);

int main() {
    int eleccion;

    Plano plano(ancho, alto, k);

    do {
        system("cls");
        cout << " SOLUCIONADOR DE UN SISTEMA DE ECUACIONES 2X2 USANDO EL METODO GRAFICO " << endl;
        cout << "[1].Iniciar el modo grafico" << endl;
        cout << "[2].Pintar grafica" << endl; 
        cout << "[3].Limpiar ventana" << endl;
        cout << "[4].Ingresar sistema de ecuaciones" << endl;
        cout << "[0].Salir" << endl;
        cin >> eleccion;

        switch(eleccion) {
            case 1:
                initwindow(ancho, alto); 
                pintarPlano();
                break;
            case 2:
                menu_funciones(plano); 
                break;
            case 3:
                cleardevice();
                pintarPlano();
                break;
            case 4:
                menu_interseccion(plano);
                break;
            default:
                break;
        }

    } while(eleccion != 0);

    system("pause>null");
    return 0;
}

void pintarPlano() {
    Plano plano = Plano(ancho, alto, k);

    Punto p1 = Punto(plano.posX(-ancho / 2 * k), plano.posY(0));
    Punto p2 = Punto(plano.posX(ancho / 2 * k), plano.posY(0));
    Punto p3 = Punto(plano.posX(0), plano.posY(-alto / 2 * k));
    Punto p4 = Punto(plano.posX(0), plano.posY(alto / 2 * k));

    // Líneas del plano
    setcolor(RED);    
    plano.pintar_lineas(-ancho / 2 * k, ancho / 2 * k, true); 
    plano.pintar_lineas(-alto / 2 * k, alto / 2 * k, false);

    // Líneas del eje
    setcolor(WHITE);
    line((int)p1.getX(), (int)p1.getY(), (int)p2.getX(), (int)p2.getY()); 
    line((int)p3.getX(), (int)p3.getY(), (int)p4.getX(), (int)p4.getY());
}

void menu_funciones(Plano plano) {
    int eleccion;

    do {
        system("cls");
        cout << "MENU DE FUNCIONES" << endl;
        cout << "[1]. Punto" << endl;
        cout << "[2]. Recta" << endl;
        cout << "[0]. Volver" << endl;
        cin >> eleccion;

        switch(eleccion) {
            case 1:
                menu_punto(plano);
                break;
            case 2:
                menu_recta(plano);
                break;
            default:
                break;
        }
    } while(eleccion != 0);
}

void menu_punto(Plano p) {
    float x, y;
    int color;
    int opcion;

    do {
        system("cls");
        cout << "MENU PUNTO" << endl;
        cout << "Punto (x, y)" << endl;
        cout << " X: ";
        cin >> x;
        cout << " Y: ";
        cin >> y;
        cout << " Color: ";
        cin >> color;

        p.pintar_punto(Punto(x, y), color);

        cout << "Presione 0 para volver al menu anterior: ";
        cin >> opcion;

    } while (opcion != 0);
}

void menu_recta(Plano p) {
    float m, b;
    int color;
    int opcion;

    do {
        system("cls");
        cout << "MENU RECTA" << endl;
        cout << " y = mx + b " << endl;
        cout << " m: ";
        cin >> m;
        cout << " b: ";
        cin >> b;
        cout << " Color: ";
        cin >> color;

        p.pintar_recta(m, b, color);

        cout << "Presione 0 para volver al menu anterior: ";
        cin >> opcion;

    } while (opcion != 0);
}

void menu_interseccion(Plano p) {
    float m1, b1, m2, b2;
    int opcion;

    do {
        system("cls");
        cout << "MENU SISTEMA DE ECUACIONES" << endl;
        cout << "Ingrese la primera ecuacion lineal de la forma: y = m1x + b1" << endl;
        cout << " m1: ";
        cin >> m1;
        cout << " b1: ";
        cin >> b1;
        cout << "Ingrese la segunda ecuacion lineal de la forma: y = m2x + b2" << endl;
        cout << " m2: ";
        cin >> m2;
        cout << " b2: ";
        cin >> b2;

        p.pintar_recta(m1, b1, YELLOW);
        p.pintar_recta(m2, b2, YELLOW);

        p.pintar_interseccion(m1, b1, m2, b2);

        cout << "Presione 0 para volver al menu anterior: ";
        cin >> opcion;

    } while (opcion != 0);
}












