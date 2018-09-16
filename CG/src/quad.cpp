/*
  Name:        quad.cpp
  Copyright:   Version 0.1
  Author:      Rodrigo Luis de Souza da Silva
  Last Update: 03/09/2014
  Release:     18/09/2004
  Description: Simple opengl program
*/

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <vector>
#include <algorithm>
using namespace std;

float desiredFPS = 100;
int width = 100;
int height = 100;

const float TAMANHO_X = 20.0;
const float TAMANHO_Z = 5.0;

float altura_entre_bloco = -60.0;

float tamanho_tela_pespectiva = 400.0;

float limite_janela_esquerda = (float)-(width / 2);
float limite_janela_direita = (float)(width / 2);

float limite_esquerda = 0.0;
float limite_direita = 0.0;

float width_windows = 800.0;
float height_windows = 700.0;

float zBola = 0.0;
float focoX = zBola;
float focoY = zBola;

bool inicializado = false;

#include <AbstractGeom.h>
#include <Esfera.h>
#include <plano.h>

Esfera *esfera;
vector<Plano *> preto;
vector<Plano *> vermelho;
vector<Plano *> vermelhoMovel;

#include "extra.h"
#include "display.h"
#include "gravidade.h"
#include "keyboard.h"

void display(void);
void init(void);
void keyboard(unsigned char key, int x, int y);

void criaPlano()
{
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
    glScalef(20.0, 20.0, 5.0);
    glutSolidCube(1.0);
    glPopMatrix();
}

void inicializa()
{
    esfera = new Esfera(0.0, 0.0, zBola, 5.0);
}

void display(void)
{
    if (!inicializado)
    {
        inicializa();
        inicializado = true;
    }

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-width / 4, width / 4, -height / 4, height / 4, 0.1, 800.0); //    RotateCamera();

    gluLookAt(400.0f, 0.0f, 0.0f,
              focoX, 0.0f, focoY,
              0.0f, 0.0f, 1.0f);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
    setMaterial();
    glTranslatef(0.0, 0.0, esfera->GetposicaoZ()); /// Posicionamento inicial da esfera
    glutSolidSphere(5.0, 10.0, 10.0);
    glPopMatrix();

    criaPlanos();

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glutSwapBuffers();
}

void init(void)
{
    glClearColor(0.5, 0.5, 0.5, 0.0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST); /// Habilita Z-buffer
    initLight(width, height);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width_windows, height_windows);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Maze");
    glutFullScreen();
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(idle);
    glutReshapeFunc(reshape);
    //   glutMotionFunc( motion );
    //   glutSpecialUpFunc( specialKeyRelease);

    printf("Pressione ESC para fechar.\n");

    glutMainLoop();

    return 0;
}
