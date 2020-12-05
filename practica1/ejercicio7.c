#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <sys/utsname.h>

int main(){
	long maxEnlaces = sysconf(_PC_LINK_MAX);
	long maxRuta = sysconf(_PC_PATH_MAX);
	long maxNombre = sysconf(_PC_NAME_MAX);
	prinft("Numero maximo de enlaces: %li\n", maxEnlaces);
	prinft("Tamaño maximo de una ruta: %li\n", maxRuta);
	prinft("Tamaño maximo de nombre de un fichero: %li\n", maxNombre);
	return 0;
}