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
        velocidade = 25;
        zBola = 0;
      break;

      case 'p':
       if(flag == false){
            velocidadePausa = velocidade;
            gravidadePausa = gravidade;

            velocidade = 0;
            gravidade = 0;
            flag = true;

       }else{
            velocidade = velocidadePausa;
            gravidade = gravidadePausa;
            flag = false;
       }

      break;
   }
}

#endif // KEYBOARD_H_INCLUDED
