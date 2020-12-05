#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <time.h>


int main(){
	time_t t = time(NULL);
	printf("Hora desde el Epoch en segundos: %li\n", t);
	return 0;
}

//Se verifica que el fichero tiene activado el bit setuid cuando usuario y usuario efectivo tienen el mismo id.