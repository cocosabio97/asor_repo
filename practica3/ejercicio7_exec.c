#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv){

  if (argc < 2) {
    printf("Fallo al leer el comando.\n");
    return -1;
  }

  //Ejecutamos el comando correspondiente a la entrada por argumentos
  if (execvp(argv[1], argv + 1) == -1) {
    printf("ERROR: No se ha ejecutado correctamente.\n");
  }

  printf("Todo ha ido bien.\n");


  return 0;
}