#include "math.h" 

class Recta {
    private:
        float m;
        float b;

    public:
        Recta(float _m, float _b) {
            m = _m;
            b = _b;
        }

        float getY(float x) {
            return (m * x) + b;
        }

        float getM() {
            return m;
        }

        float getB() {
            return b;
        }
};









