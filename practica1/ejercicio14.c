#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <time.h>


int main(){
	time_t t = time(NULL);
	struct tm *tiempo = localtime(&t);
	int ano = tiempo->tm_year;
	printf("Estamos en el año: %i\n", 1900+ano);
	return 0;
}

//Se verifica que el fichero tiene activado el bit setuid cuando usuario y usuario efectivo tienen el mismo id.