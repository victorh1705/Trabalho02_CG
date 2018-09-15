// Globals

void criarPlano(float posicaoInicialY, float posicaoFinalY, float translateZ);
void criarPlanoPreto(float posicaoInicialY, float posicaoFinalY, float translateZ);
void criarPlanoVermelho(float posicaoInicialY, float posicaoFinalY, float translateZ);

void criarLabirinto();
void setPlanosVermelhos(Plano* p);
void setPlanosPretos(Plano* p);

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

    criarLabirinto();


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
        glScalef( TAMANHO_X, tamanhoY, TAMANHO_Z);
        glutSolidCube(1.0);
    glPopMatrix();
}


void criarLabirinto(){
    vermelho.push_back(new Plano(20.0, 80.0, altura_entre_bloco*3));

    for_each(vermelho.begin(), vermelho.end(), setPlanosVermelhos);
    //for_each(preto.begin(), preto.end(), setPlanosPretos);
}


void setPlanosVermelhos(Plano* p){
    criarPlanoVermelho(p->GetinicialY(), p->GetfinalY(), p->GetposicaoZ());
}


void setPlanosPretos(Plano* p){
    criarPlanoPreto(p->GetinicialY(), p->GetfinalY(), p->GetposicaoZ());
}
