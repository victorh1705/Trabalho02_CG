// Globals

void criarPlano(float posicaoInicialY, float posicaoFinalY, float translateZ);
void criarPlanoPreto(float posicaoInicialY, float posicaoFinalY, float translateZ);
void criarPlanoVermelho(float posicaoInicialY, float posicaoFinalY, float translateZ);

void criarLabirinto();
void setPlanosVermelhos(Plano *p);
void setPlanosPretos(Plano *p);

void criarPlano(float posicaoInicialY, float posicaoFinalY, float translateZ);
void criarPlano(Plano *p);

void reshape(int w, int h)
{
    width = w;
    height = h;
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}

void criaPlanos()
{
    glColor3f(0.0, 0.0, 0.0);
    criarLabirinto();
}

void criarLabirinto()
{
    vermelho.push_back(new Plano(-50.0, -100.0, 0.0));
    preto.push_back(new Plano(-100.0, -200.0, 0.0));
    preto.push_back(new Plano(-15.0, 200.0, 0.0));

    vermelho.push_back(new Plano(-100.0, -50.0, altura_entre_bloco * 1));
    preto.push_back(new Plano(-50.0, -10.0, altura_entre_bloco * 1));
    vermelho.push_back(new Plano(20.0, 750.0, altura_entre_bloco * 1));
    preto.push_back(new Plano(75.0, 100.0, altura_entre_bloco * 1));

    preto.push_back(new Plano(-200.0, 0.0, altura_entre_bloco * 2));
    vermelho.push_back(new Plano(0.0, 20.0, altura_entre_bloco * 2));
    vermelho.push_back(new Plano(50.0, 80.0, altura_entre_bloco * 2));
    preto.push_back(new Plano(80.0, 200.0, altura_entre_bloco * 2));

    vermelho.push_back(new Plano(-200.0, -100.0, altura_entre_bloco * 3));
    preto.push_back(new Plano(-100.0, -50.0, altura_entre_bloco * 3));
    vermelho.push_back(new Plano(-10.0, 30.0, altura_entre_bloco * 3));
    preto.push_back(new Plano(30.0, 100.0, altura_entre_bloco * 3));

    preto.push_back(new Plano(-200.0, -50.0, altura_entre_bloco * 4));
    vermelhoMovel.push_back(new Plano(-50.0, -20.0, altura_entre_bloco * 4));
    preto.push_back(new Plano(30.0, 100.0, altura_entre_bloco * 4));

    for_each(vermelho.begin(), vermelho.end(), setPlanosVermelhos);
    for_each(preto.begin(), preto.end(), setPlanosPretos);
}

void criarPlano(float posicaoInicialY, float posicaoFinalY, float translateZ)
{

    float tamanhoY = 0.0;
    if (posicaoFinalY > posicaoInicialY)
    {
        tamanhoY = posicaoFinalY - posicaoInicialY;
    }
    else
    {
        tamanhoY = posicaoInicialY - posicaoFinalY;
    }

    float translateY = (posicaoFinalY + posicaoInicialY) / 2;

    glPushMatrix();
    glTranslatef(0.0, translateY, translateZ);
    glScalef(TAMANHO_X, tamanhoY, TAMANHO_Z);
    glutSolidCube(1.0);
    glPopMatrix();
}

void criarPlano(Plano *p)
{

    float tamX = (p->GetalturaX() * 2.0);
    float tamY = (p->GetalturaY() * 2.0);
    float tamZ = (p->GetalturaZ() * 2.0);

    glPushMatrix();
    glTranslatef(p->GetposicaoX(), p->GetposicaoY(), p->GetposicaoZ());
    glScalef(tamX, tamY, tamZ);
    glutSolidCube(1.0);
    glPopMatrix();
}

void criarPlanoVermelho(Plano *p)
{
    setMaterialVermelho();
    criarPlano(p);
}

void setPlanosVermelhos(Plano *p)
{
    criarPlanoVermelho(p);
}

void criarPlanoPreto(Plano *p)
{
    setMaterialPreto();
    criarPlano(p);
}

void setPlanosPretos(Plano *p)
{
    criarPlanoPreto(p);
}
