// Globals
float desiredFPS = 100;
int width  = 1000;
int height = 700;

float tamanho_tela_pespectiva = 400.0;

float limite_janela_esquerda = (float) -(width/2);
float limite_janela_direita = (float) (width/2);

float limite_esquerda = 0.0;
float limite_direita = 0.0;

void criarPlano(float posicaoInicialY, float posicaoFinalY, float translateZ);
void criarPlanoPreto(float posicaoInicialY, float posicaoFinalY, float translateZ);
void criarPlanoVermelho(float posicaoInicialY, float posicaoFinalY, float translateZ);

void reshape (int w, int h)
{
    width = w;
    height = h;
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
}


void criaPlanos(){

    float widthPlano = (float) 3.0*width;



    glColor3f(0.0, 0.0, 0.0);

    glPushMatrix();
        setMaterialPreto();
        glTranslatef(0.0, 0.0, 0.0);
        glScalef( 20.0, widthPlano, 5.0);
        glutSolidCube(1.0);
    glPopMatrix();


    criarPlanoPreto(0.0, 200.0, 80.0);
    criarPlanoVermelho(-15.0, 0.0, 80.0);
    criarPlanoPreto(-100.0, -200.0, 80.0);
    criarPlanoVermelho(-50.0, -100.0, 80.0);

    criarPlanoPreto(80.0, 200.0, 40.0);
    criarPlanoVermelho(50.0, 80.0, 40.0);
    criarPlanoPreto(0.0, -200.0, 40.0);
    criarPlanoVermelho(30.0, 0.0, 40.0);
}

void criarPlanoPreto(float posicaoInicialY, float posicaoFinalY, float translateZ){
    setMaterialPreto();
    criarPlano(posicaoInicialY, posicaoFinalY, translateZ);
}

void criarPlanoVermelho(float posicaoInicialY, float posicaoFinalY, float translateZ){
    setMaterialVermelho();
    criarPlano(posicaoInicialY, posicaoFinalY, translateZ);
}

void criarPlano(float posicaoInicialY, float posicaoFinalY, float translateZ){

    float tamanhoY = 0.0;
    if( posicaoFinalY > posicaoInicialY){
        tamanhoY = posicaoFinalY - posicaoInicialY;
    }else{
        tamanhoY = posicaoInicialY - posicaoFinalY;
    }

    float translateY = (posicaoFinalY + posicaoInicialY)/2;


    glPushMatrix();
        glTranslatef(0.0, translateY, translateZ);
        glScalef( 20.0, tamanhoY, 5.0);
        glutSolidCube(1.0);
    glPopMatrix();
}
