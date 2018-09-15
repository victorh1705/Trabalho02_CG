#ifndef PLANO_H
#define PLANO_H

#include <AbstractGeom.h>
#include <Esfera.h>

class Plano : public AbstractGeom
{
  public:
    Plano();
    Plano(float inicialY, float finalY, float posicaoZ);
    virtual ~Plano();

    ///Get e Set
    float GetinicialY() { return inicialY; }
    void SetinicialY(float val) { inicialY = val; }
    float GetfinalY() { return finalY; }
    void SetfinalY(float val) { finalY = val; }
    float GetposicaoZ() { return posicaoZ; }
    void SetposicaoZ(float val) { posicaoZ = val; }

    void definePlano(float inicialY, float finalY, float posicaoZ);

    ///Funcoes a serem implementadas
    //virtual haColisaoX(float posicaoInicial, float posicaoFinal);
    bool haColisao(Esfera *esfera);

  protected:
  private:
    float inicialY;
    float finalY;
};

#endif // PLANO_H
