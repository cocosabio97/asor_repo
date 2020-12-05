#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <sys/utsname.h>

int main(){
	int ok;
	struct utsname uts;
	ok = uname(&uts);
	if(ok == 0){
		printf("Nombre del sistema operativo: %s\n", uts.sysname);
		printf("Nombre del nodo: %s\n", uts.nodename);
		printf("Fecha sistema operativo: %s\n", uts.release);
		printf("Version del sistema operativo: %s\n", uts.version);
		printf("Identificador de maquina; %s\n", uts.machine);
	}else
		printf("Error: %s\n", errno, strerror(errno));
	return 0;
}