#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <sys/utsname.h>

int main(){
	long maxA = sysconf(_SC_ARG_MAX);
	long maxHijos = sysconf(_SC_CHILD_MAX);
	long maxFicheros = sysconf(_SC_OPEN_MAX);
	prinft("Longitud maxima de argumentos: %li\n", maxA);
	prinft("Numero maximo de hijos: %li\n", maxHijos);
	prinft("Cantidad maxima de ficheros: %li\n", maxFicheros);
	return 0;
}