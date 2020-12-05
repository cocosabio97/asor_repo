#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

int main(){
	int resultado;
	resultado = setuid(0);
	if( resultado == -1){
		printf("Error: ", errno, strerror(errno));
		perror("Motivo: ");
	}else
		printf("Todo ha ido bien");

	return 0;
}
