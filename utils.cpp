#include <graphics.h>
#include "funciones.cpp"
#include <iostream>  

using namespace std; 

class Punto {
    private:
        float x;
        float y;

    public:
        Punto(float _x, float _y) {
            setX(_x);
            setY(_y);
        }

        void setX(float _x) {
            x = _x;
        }

        void setY(float _y) {
            y = _y;
        }

        float getX() {
            return x;
        }

        float getY() {
            return y;
        }
};

class Plano {
    private:
        int ancho;
        int alto;
        int k;

    public:
        Plano(int _ancho, int _alto, int _k) {
            ancho = _ancho;
            alto = _alto;
            k = _k;
        }

        void setAncho(int _ancho) {
            ancho = _ancho;
        }

        void setAlto(int _alto) {
            alto = _alto;
        }

        void setk(int _k) {
            k = _k;
        }

        float posX(float _x) {
            return ((ancho / 2) + (_x * k));
        }

        float posY(float _y) {
            return ((alto / 2) - (_y * k));
        }

        void pintar_lineas(int val_min, int val_max, bool tipo = true) {
            Punto plano_linea_1 = Punto(0.0f, 0.0f);
            Punto plano_linea_2 = Punto(0.0f, 0.0f);

            Punto pos_letra = Punto(0.0f, 0.0f);
            char unidad_texto[4];

            for (int i = val_min; i <= val_max; i++) {
                plano_linea_1.setX(posX((tipo) ? i : val_min));
                plano_linea_1.setY(posY((tipo) ? val_min : i));

                plano_linea_2.setX(posX((tipo) ? i : val_max));
                plano_linea_2.setY(posY((tipo) ? val_max : i));

                if (tipo) {
                    // Horizontal
                    pos_letra.setX(posX(i));
                    pos_letra.setY(posY(0.0f));
                } else {
                    // Vertical
                    pos_letra.setX(posX(0.0f));
                    pos_letra.setY(posY(i));
                }

                sprintf(unidad_texto, "%d", i);

                line(plano_linea_1.getX(), plano_linea_1.getY(),
                     plano_linea_2.getX(), plano_linea_2.getY());

                int color_actual = getcolor();

                setcolor(WHITE);
                outtextxy(pos_letra.getX(), pos_letra.getY(), unidad_texto);

                setcolor(color_actual);
            }
        }

        void pintar_punto(Punto p, int color = YELLOW) {
            putpixel(posX(p.getX()), posY(p.getY()), color);
        }

        void pintar_recta(float m, float b, int color = YELLOW) {
            Punto p(0.0f, 0.0f);
            Recta recta(m, b);

            float longitud = (float)ancho / (2 * k);

            for (float i = -longitud; i <= longitud; i += 0.01) {
                p.setX(i);
                p.setY(recta.getY(i));

                putpixel(posX(p.getX()), posY(p.getY()), color);
            }
        }

        void pintar_interseccion(float m1, float b1, float m2, float b2) {
            float x_interseccion = (b2 - b1) / (m1 - m2);
            float y_interseccion = m1 * x_interseccion + b1;

            Punto interseccion(x_interseccion, y_interseccion);
            pintar_punto(interseccion, WHITE);

            cout << "Punto de intersección: (" << x_interseccion << ", " << y_interseccion << ")" << endl;
        }
};







