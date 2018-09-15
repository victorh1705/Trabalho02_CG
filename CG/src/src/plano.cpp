#include "plano.h"

const float TAMANHO_X = 20.0;
const float TAMANHO_Z = 5.0;

Plano::Plano()
{
    //ctor
}

Plano::Plano(float inicialY, float finalY, float posicaoZ)
{
    //inicialY(inicialY),finalY(finalY), posicaoZ(posicaoZ){};

    this->inicialY = inicialY;
    this->finalY = finalY;
    this->posicaoZ = posicaoZ;

    float tamanhoY = 0;
    if (finalY > inicialY)
    {
        tamanhoY = finalY - inicialY;
    }
    else
    {
        tamanhoY = inicialY - finalY;
    }

    this->posicaoX = 0.0;
    this->posicaoY = (finalY + inicialY) / 2.0;
    this->posicaoZ = posicaoZ;

    this->alturaX = TAMANHO_X / 2.0;
    this->alturaY = tamanhoY / 2.0;
    this->alturaZ = TAMANHO_Z / 2.0;
}

Plano::~Plano()
{
    //dtor
}

void Plano::definePlano(float inicialY, float finalY, float posicaoZ)
{
    SetinicialY(inicialY);
    SetinicialY(finalY);
    SetposicaoZ(posicaoZ);
}

bool Plano::haColisao(Esfera *esfera)
{
    float menorZ = esfera->GetposicaoZ() - esfera->GetalturaZ();

    if (this->GetalturaInicialZ() > menorZ && menorZ > this->GetalturaFinalZ())
    {
        if (this->GetalturaInicialY() > esfera->GetposicaoY() && esfera->GetposicaoY() > this->GetalturaFinalY())
        {
            return true;
        }
    }
    return false;
}
