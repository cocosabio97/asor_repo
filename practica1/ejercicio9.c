#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>


int main(){
	printf("Usuario: %i\n", getuid());
	printf("Usuario efectivo: %i\n", geteuid());
	return 0;
}

//Se verifica que el fichero tiene activado el bit setuid cuando usuario y usuario efectivo tienen el mismo id.