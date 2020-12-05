#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <time.h>


int main(){
	struct timeval tiempo;
	int hora = gettimeofday(&tiempo, NULL);
	int ini = tiempo.tv_usec;

	int i;
	for(i = 0; i < 1000000; ++i);
	int hora2 = gettimeofday(&tiempo, NULL);
	int fin = tiempo.tv_usec;
	int res = fin - ini;
	printf("Se han tardado: %li milisegundos\n", res);
	return 0;
}

//Se verifica que el fichero tiene activado el bit setuid cuando usuario y usuario efectivo tienen el mismo id.