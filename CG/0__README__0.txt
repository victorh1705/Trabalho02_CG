DCC065 - Computa��o Gr�fica
---------------------------

Para come�ar, abra o arquivo 'linux.workspace' que contem todos os arquivos 
para Linux. Para windows, entre na pasta 'src' e utilize o projeto windows.cbp.
No projeto do windows os arquivos fontes tem que ser inclu�dos individualmente.

===============================================================================
Instru��es gerais
===============================================================================
Linux

Para compilar os arquivos deste projeto no Linux, os seguintes pacotes (ou
seus pacotes equivalentes) devem estar instalados:
* codeblocks
* g++
* freeglut3-dev
* libglew-dev 
* lib32z1-dev
* zlib1g-dev
* libalut-dev
* libpng16-dev
* libjpeg-dev
* libglm-dev    (NOVO)
* libglfw3      (NOVO)
* libglfw3-dev  (NOVO)
* libglfw3-doc  (NOVO)
* libsoil-dev   (NOVO)
* libassimp-dev (NOVO)


Essas instru��es foram testadas no Linux Mint 18.2 64 bits.

===============================================================================

Windows

N�o � preciso configurar nada no windows pois os arquivos para este sistema 
j� est�o presentes neste projeto, que foi criado para ser executado na IDE 
Codeblocks que pode ser baixada gratuitamente no link abaixo:
http://downloads.sourceforge.net/codeblocks

===============================================================================
Corre��o de erros comuns
===============================================================================

Sistema operacional: Ubuntu 14.04 LTs

Erro: Ao compilar c�digos com o GLUI no linux aparece a seguinte mensagem
Inconsistency detected by ld.so: dl-version.c: 224: _dl_check_map_versions: 
Assertion `needed != ((void *)0)' failed!

Solu��o:
Em "Build Options" selecionar a op��o "Linux".
A seguir, v� em "Linker settings" e na op��o "Other Linker options" acrescente:
-L/usr/lib/nvidia-304
Substitua a pasta "nvidia-304" pela correspondente do seu sistema operacional.

-------------------------------------------------------------------------------
