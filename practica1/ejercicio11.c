#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <pwd.h>


int main(){
	struc passwd *estru;
	estru = getpwuid(getuid());
	printf("Usuario: %i\n", getuid());
	printf("Usuario efectivo: %i\n", geteuid());
	printf("Nombre del usuario: %s\n", estru->pw_name);
	printf("Directorio home %s\n", estru->pw_dir);
	printf("Descripcion de usuario: %s\n", estru->pw_gecos);
	return 0;
}

//Se verifica que el fichero tiene activado el bit setuid cuando usuario y usuario efectivo tienen el mismo id.
