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
#include "display.h"
#include "extra.h"


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
    gluPerspective(40.0f,(GLfloat)width/(GLfloat)height, 0.1 ,2500);

//    RotateCamera();

    gluLookAt (200.0f, 0.0f, 0.0f,
               0.0f, 0.0f, 0.0f,
               0.0f, 0.0f, 1.0f);

    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity ();


    glPushMatrix();
        setMaterial();
        glTranslatef(0.0, 0.0, 15.0); /// Posicionamento inicial da esfera
        glutSolidSphere(5.0, 10.0, 10.0);
    glPopMatrix();


    criaPlano();

    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key)
   {
      case 27:
         exit(0);
      break;
   }
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
   glutInitWindowSize (width, height);
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("Maze");
   init ();
   glutDisplayFunc(display);
   glutKeyboardFunc(keyboard);
//   glutIdleFunc( idle);
   glutReshapeFunc(reshape);
//   glutMotionFunc( motion );
//   glutSpecialUpFunc( specialKeyRelease);

	printf("Pressione ESC para fechar.\n");

   glutMainLoop();

   return 0;
}
