#ifndef GRAVIDADE_H_INCLUDED
#define GRAVIDADE_H_INCLUDED

float velocidade = 1.0;
float gravidade = -10.0;
float dt = 0.1;

float posicaoAtual;
bool colisao = false;

vector<Plano *> colisaoPreto;
vector<Plano *> colisaoVermelho;

vector<Plano *> planosPosicaoZ(float z, vector<Plano *> planos);
void updateVelocidadePosicao();
void idle();
float haColisao();

void idle()
{
    float t, desiredFrameTime, frameTime;
    static float tLast = 0.0;

    /// Get elapsed time
    t = glutGet(GLUT_ELAPSED_TIME);

    /// convert milliseconds to seconds
    t /= 1000.0;

    /// Calculate frame time
    frameTime = t - tLast;
    /// Calculate desired frame time
    desiredFrameTime = 1.0 / (float)(desiredFPS);

    // Check if the desired frame time was achieved. If not, skip animation.
    if (frameTime <= desiredFrameTime)
        return;

    // **  UPDATE ANIMATION VARIABLES ** //
    float step = 1; // Speed of the animation

    updateVelocidadePosicao();
    vector<Plano *> colisaoVermelho = planosPosicaoZ(zBola, vermelho);
    vector<Plano *> colisaoPreto = planosPosicaoZ(zBola, preto);

    tLast = t;

    glutPostRedisplay();
}

void updateVelocidadePosicao()
{

    if(haColisao() != 120){
        posicaoAtual = haColisao();
        colisao = true;
        velocidade = 25;
    }

    if(colisao == true){
         focoX = focoY = posicaoAtual;
    }else{
        focoX = focoY = zBola;
    }

    if(zBola <= posicaoAtual -5){
        colisao = false;
    }

    velocidade = velocidade + gravidade * dt;
    zBola = esfera->GetposicaoZ() + (velocidade * dt) + 0.5 * gravidade * (dt * dt);
    esfera->SetposicaoZ(zBola);
}

float haColisao()
{
    static int i = 0;
    if(preto[i]->GetfinalY() < mouseY ){
        i = 5;
        return 120;
    }

    if(preto[i]->GetposicaoZ() + 5  >= zBola){
        return preto[i]->GetposicaoZ();
    }
    if( (vermelho[i]->GetinicialY() <= mouseY) && (vermelho[i]->GetfinalY() <= mouseY) ){
        return 120;
    }
}

vector<Plano *> planosPosicaoZ(float z, vector<Plano *> planos)
{
    vector<Plano *> retorno;

    for (float i = 0; i <= planos.size(); i++)
    {
        Plano *it = vermelho[0];
        if (it->GetposicaoZ() == z)
        {
            retorno.push_back(it);
        }
    }
    return retorno;
}

#endif // GRAVIDADE_H_INCLUDED
