// Globals

void criarPlano(float posicaoInicialY, float posicaoFinalY, float translateZ);
void criarPlanoPreto(float posicaoInicialY, float posicaoFinalY, float translateZ);
void criarPlanoVermelho(float posicaoInicialY, float posicaoFinalY, float translateZ);

void criarLabirinto();
void setPlanosVermelhos(Plano *p);
void setPlanosPretos(Plano *p);
void setPlanoAzul(Plano *p);

void completaVermelho(float posicaoInicial, float z);
void completaPreto(float posicaoInicial, float z);
void setVermelho100(float posicaoInicial, float z);
void setVermelho50(float posicaoInicial, float z);
void setPreto200(float posicaoInicial, float z);
void setPreto100(float posicaoInicial, float z);
void setPreto50(float posicaoInicial, float z);

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

    setVermelho100(-350.0, 0.0);
    setPreto100(-250.0, 0.0);
    setVermelho100(-150.0, 0);
    setPreto50(0.0, 0.0);
    setVermelho100(50.0, 0.0);
    setPreto50(150.0, 0.0);
    setVermelho50(200.0, 0.0);
    completaVermelho(250.0, 0.0);

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

    setPreto200(-350.0, 5);
    setVermelho100(-100.0, 5);
    setPreto50(0.0, 5);
    setPreto50(100.0, 5);
    setVermelho100(200.0, 5);
    completaPreto(350.0, 5);

    setVermelho100(-350.0, 6);
    setPreto50(-250.0, 6);
    setPreto200(-150.0, 6);
    setVermelho100(50.0, 6);
    completaPreto(250.0, 6);

    setPreto50(-350.0, 7);
    setVermelho100(-300.0, 7);
    setPreto50(-200.0, 7);
    setPreto50(-50.0, 7);
    setVermelho100(0.0, 7);
    completaPreto(100.0, 7);

    setPreto200(-350.0, 8);
    setVermelho50(-150.0, 8);
    setPreto50(-100.0, 8);
    setVermelho50(-50.0, 8);
    setPreto50(0.0, 8);
    completaPreto(150.0, 8);

    setPreto100(-350.0, 9);
    setVermelho100(-250.0, 9);
    setPreto100(-150.0, 9);
    setVermelho50(0.0, 9);
    setPreto100(50.0, 9);
    setVermelho100(150.0, 9);
    completaPreto(250.0, 9);

    setVermelho50(-350, 10);
    setVermelho100(-300, 10);
    setPreto50(-200, 10);
    setPreto50(-100, 10);
    setVermelho100(0.0, 10);
    setPreto100(100.0, 10);
    completaVermelho(200.0, 10);

    //Fim da pilha
    setPlanoAzul(new Plano(-350.0, 350.0, altura_entre_bloco * 40));

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

void setPreto200(float posicaoInicial, float z)
{
    preto.push_back(new Plano(posicaoInicial, (posicaoInicial + 200.0), altura_entre_bloco * z));
}

void setPreto100(float posicaoInicial, float z)
{
    preto.push_back(new Plano(posicaoInicial, (posicaoInicial + 100.0), altura_entre_bloco * z));
}

void setPreto50(float posicaoInicial, float z)
{
    preto.push_back(new Plano(posicaoInicial, (posicaoInicial + 50.0), altura_entre_bloco * z));
}

void completaPreto(float posicaoInicial, float z)
{
    preto.push_back(new Plano(posicaoInicial, 350.0, altura_entre_bloco * z));
}

void setVermelho100(float posicaoInicial, float z)
{
    vermelho.push_back(new Plano(posicaoInicial, (posicaoInicial + 100.0), altura_entre_bloco * z));
}

void setVermelho50(float posicaoInicial, float z)
{
    vermelho.push_back(new Plano(posicaoInicial, (posicaoInicial + 50.0), altura_entre_bloco * z));
}

void completaVermelho(float posicaoInicial, float z)
{
    vermelho.push_back(new Plano(posicaoInicial, 350.0, altura_entre_bloco * z));
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

void setPlanoAzul(Plano *p)
{
    fimAzul = p;
    setMaterialAzul();
    criarPlano(fimAzul);
}