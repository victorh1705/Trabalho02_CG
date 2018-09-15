#ifndef ESFERA_H
#define ESFERA_H

#include <AbstractGeom.h>

class Esfera : public AbstractGeom
{
    public:
        Esfera();
        Esfera(float raio): raio(raio){};
        Esfera(float x, float y, float z);
        Esfera(float x, float y, float z, float r);
        virtual ~Esfera();

        float Getraio() { return raio; }
        void Setraio(float val) {
            raio = val;
            alturaX = raio;
            alturaY = raio;
            alturaZ = raio;
        }

        bool haColisao(float x, float y, float z);

    protected:

    private:
        float raio;
};

#endif // ESFERA_H
