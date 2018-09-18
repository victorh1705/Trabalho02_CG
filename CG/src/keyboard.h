#ifndef KEYBOARD_H_INCLUDED
#define KEYBOARD_H_INCLUDED

void keyboard();
float velocidadePausa;
float gravidadePausa;
float mouseYPausa;
bool flagMousePausa = false;

void keyboard(unsigned char key, int x, int y)
{
  static bool flag = false;

  switch (key)
  {
  case 'r':
    zBola = 100;
    velocidade = 1.0;
    break;

  case 'p':
     if(flag == false){
            velocidadePausa = velocidade;
            gravidadePausa = gravidade;
            mouseYPausa = mouseY;
            flagMousePausa = true;

            velocidade = 0;
            gravidade = 0;
            flag = true;

       }else{
            velocidade = velocidadePausa;
            gravidade = gravidadePausa;
            mouseY = mouseYPausa;
            flag = false;
            flagMousePausa = false;
       }
    break;

  // Sair ao apertar 'Esc'
  case 27: //Escape key
    glutDestroyWindow(0);
    exit(0);
    break;
  }
}

void motion(int x, int y )
{
   if(flagMousePausa == false){
        mouseY = x/3;
    }
}


#endif // KEYBOARD_H_INCLUDED
