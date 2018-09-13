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
#include "extra.h"
#include "display.h"
#include "gravidade.h"
#include "keyboard.h"

float width_windows  = 800.0;
float height_windows = 700.0;

void display(void);
void init (void);
void keyboard(unsigned char key, int x, int y);


void criaPlano(){
    glPushMatrix();
        glTranslatef(0.0, 0.0, 0.0);
        glScalef(20.0 , 20.0, 5.0);
        glutSolidCube(1.0);
    glPopMatrix();

}

void display(void)
{
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glOrtho (-width/2, width/2, -height/2, height/2, 0.1, 500.0);//    RotateCamera();

    gluLookAt (400.0f, 0.0f, 0.0f,
               focoX, 0.0f, focoY,
               0.0f, 0.0f, 1.0f);

    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity ();


    glPushMatrix();
        setMaterial();
        glTranslatef(0.0, 0.0, zBola); /// Posicionamento inicial da esfera
        glutSolidSphere(5.0, 10.0, 10.0);
    glPopMatrix();



    criaPlanos();

    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();

    glutSwapBuffers();
}

void init(void)
{
   glClearColor (0.5, 0.5, 0.5, 0.0);
   glShadeModel (GL_SMOOTH);
   glEnable(GL_DEPTH_TEST);               /// Habilita Z-buffer
   initLight(width, height);
}


int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB| GLUT_DEPTH);
   glutInitWindowSize (width_windows, height_windows);
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("Maze");
   init ();
   glutDisplayFunc(display);
   glutKeyboardFunc(keyboard);
   glutIdleFunc( idle);
   glutReshapeFunc(reshape);
//   glutMotionFunc( motion );
//   glutSpecialUpFunc( specialKeyRelease);

	printf("Pressione ESC para fechar.\n");

   glutMainLoop();

   return 0;
}
