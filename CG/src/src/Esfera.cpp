#include "Esfera.h"

Esfera::Esfera()
{
    //ctor
}

Esfera::Esfera(float x, float y, float z){
    posicaoX = x;
    posicaoY = y;
    posicaoZ = z;
}

Esfera::Esfera(float x, float y, float z, float r){
    posicaoX = x;
    posicaoY = y;
    posicaoZ = z;
    raio = r;

    alturaX = r;
    alturaY = r;
    alturaZ = r;
}

Esfera::~Esfera()
{
    //dtor
}

bool Esfera::haColisao(float x, float y, float z){
    if( x > posicaoX - raio && posicaoX - raio < x){
        if( y > posicaoY - raio && posicaoY - raio < y){
            if( z > posicaoZ - raio && posicaoZ - raio < z){
                return true;
            }
        }
    }
    return false;
}
