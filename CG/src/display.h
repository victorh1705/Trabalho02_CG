// Globals

void criarPlano(float posicaoInicialY, float posicaoFinalY, float translateZ);
void criarPlanoPreto(float posicaoInicialY, float posicaoFinalY, float translateZ);
void criarPlanoVermelho(float posicaoInicialY, float posicaoFinalY, float translateZ);
void criarPlanoVermelhoMovel(float posicaoInicialY, float posicaoFinalY, float translateZ);
void criarPlanoVariavel(Plano *p, float finalY);

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

void movimentoHarminoco(Plano *p);

float aleatorio = 0.0;

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
    vermelho.clear();
    vermelhoMovel.clear();
    preto.clear();

    setVermelho100(-350.0, 0.0);
    setPreto100(-250.0, 0.0);
    setVermelho100(-150.0, 0);
    setPreto50(0.0, 0.0);
    setVermelho100(50.0, 0.0);
    setPreto50(150.0, 0.0);
    setVermelho50(200.0, 0.0);
    completaVermelho(250.0, 0.0);

    setPreto200(-350.0, 1.);
    setVermelho50(-100.0, 1.);
    setPreto100(-50., 1.);
    setVermelho50(50., 1.);
    setPreto100(100., 1.);
    completaVermelho(200., 1.);

    setVermelho100(-350.0, 2);
    setPreto50(-250.0, 2);
    setPreto200(-150.0, 2);
    setVermelho100(50.0, 2);
    completaPreto(250.0, 2);

    setPreto100(-350.0, 3);
    setVermelho100(-250.0, 3);
    setPreto100(-150.0, 3);
    setVermelho50(0.0, 3);
    setPreto100(50.0, 3);
    setVermelho100(150.0, 3);
    completaPreto(250.0, 3);

    setPreto200(-350.0, 4);
    setVermelho50(-150.0, 4);
    setPreto50(-100.0, 4);
    setVermelho50(-50.0, 4);
    setPreto50(0.0, 4);
    completaPreto(150.0, 4);

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

    for (float i = 20.; i < 40; i++)
    {
        criarLabirintoAleatorio(i);
    }

    //Fim da pilha
    setPlanoAzul(new Plano(-350.0, 350.0, altura_entre_bloco * 40));

    for_each(vermelho.begin(), vermelho.end(), setPlanosVermelhos);
    for_each(vermelhoMovel.begin(), vermelhoMovel.end(), setPlanosVermelhos);
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

void criarPlanoVermelhoMovel(float posicaoInicialY, float posicaoFinalY, float translateZ)
{
    criarPlanoVariavel(new Plano(posicaoInicialY, translateZ), posicaoFinalY);
}

void criarPlanoVariavel(Plano *p, float finalY)
{
    p->SetposicaoY(finalY);
    vermelhoMovel.push_back(p);
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

void criarLabirintoAleatorio(float z)
{

    int randnumber = rand() % 11;

    switch (randnumber)
    {
    case 0:
        setVermelho50(-350, z);
        setVermelho100(-300, z);
        setPreto50(-200, z);
        setPreto50(-100, z);
        setVermelho100(0.0, z);
        setPreto100(100.0, z);
        completaVermelho(200.0, z);
        break;
    case 1:
        setVermelho100(-350.0, z);
        setPreto100(-250.0, z);
        setVermelho100(-150.0, 0);
        setPreto50(0.0, z);
        setVermelho100(50.0, z);
        setPreto50(150.0, z);
        setVermelho50(200.0, z);
        completaVermelho(250.0, z);
        break;
    case 2:
        setPreto200(-350.0, z);
        setVermelho50(-100.0, z);
        setPreto100(-50., z);
        setVermelho50(50., z);
        setPreto100(100., z);
        completaVermelho(200., z);
        break;
    case 3:
        setVermelho100(-350.0, z);
        setPreto50(-250.0, z);
        setPreto200(-150.0, z);
        setVermelho100(50.0, z);
        completaPreto(250.0, z);
        break;
    case 4:
        setPreto100(-350.0, z);
        setVermelho100(-250.0, z);
        setPreto100(-150.0, z);
        setVermelho50(0.0, z);
        setPreto100(50.0, z);
        setVermelho100(150.0, z);
        completaPreto(250.0, z);
        break;
    case 5:
        setPreto200(-350.0, z);
        setVermelho50(-150.0, z);
        setPreto50(-100.0, z);
        setVermelho50(-50.0, z);
        setPreto50(0.0, z);
        completaPreto(150.0, z);
        break;
    case 6:
        setPreto200(-350.0, z);
        setVermelho100(-100.0, z);
        setPreto50(0.0, z);
        setPreto50(100.0, z);
        setVermelho100(200.0, z);
        completaPreto(350.0, z);
        break;
    case 7:
        setVermelho100(-350.0, z);
        setPreto50(-250.0, z);
        setPreto200(-150.0, z);
        setVermelho100(50.0, z);
        completaPreto(250.0, z);
        break;
    case 8:
        setPreto50(-350.0, z);
        setVermelho100(-300.0, z);
        setPreto50(-200.0, z);
        setPreto50(-50.0, z);
        setVermelho100(0.0, z);
        completaPreto(100.0, z);
        break;
    case 9:
        setPreto200(-350.0, z);
        setVermelho50(-150.0, z);
        setPreto50(-100.0, z);
        setVermelho50(-50.0, z);
        setPreto50(0.0, z);
        completaPreto(150.0, z);
        break;
    case 10:
        setPreto100(-350.0, z);
        setVermelho100(-250.0, z);
        setPreto100(-150.0, z);
        setVermelho50(0.0, z);
        setPreto100(50.0, z);
        setVermelho100(150.0, z);
        completaPreto(250.0, z);
        break;
    }
}