#ifndef KEYBOARD_H_INCLUDED
#define KEYBOARD_H_INCLUDED

void keyboard();
float velocidadePausa;
float gravidadePausa;

void keyboard(unsigned char key, int x, int y)
{
  static bool flag = false;

  switch (key)
  {
  case 'r':
    zBola = POSICAOINICIALZ;
    esfera->SetposicaoZ(zBola);
    velocidade = 25.0;
    gravidade = -10.0;
    break;

  case 'p':
    if (flag == false)
    {
      velocidadePausa = velocidade;
      gravidadePausa = gravidade;

      velocidade = 0;
      gravidade = 0;
      flag = true;
    }
    else
    {
      velocidade = velocidadePausa;
      gravidade = gravidadePausa;
      flag = false;
    }

    break;

  // Sair ao apertar 'Esc'
  case 27: //Escape key
    glutDestroyWindow(0);
    exit(0);
    break;
  }
}

#endif // KEYBOARD_H_INCLUDED
