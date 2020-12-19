#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){


	if (argc < 2) {
		 printf("ERROR: Se debe especeficar la ruta del archivo en los parámetros del programa.\n");
		 return -1;
	}

	struct stat buff;

	int statint = stat(argv[1], &buff);

	if (statint == -1) {
		printf("ERROR: No existe el directorio.\n");
		return -1;
	}

	printf("Major: %li\n", (long) minor(buff.st_dev));
	printf("Minor: %li\n", (long) major(buff.st_dev));
	printf("i-nodo: %li\n",buff.st_ino);
	printf("Tipo de archivo: %i\n",buff.st_mode);
		mode_t mode = buff.st_mode;
	if (S_ISLNK(mode)){
		printf("%s es un enlace simbólico.\n", argv[1]);
	} else if (S_ISREG(mode)) {
		printf("%s es un archivo ordinario.\n", argv[1]);
	} else if (S_ISDIR(mode)) {
		printf("%s es un directorio.\n", argv[1]);
	}
	time_t t = buff.st_atime;
	struct tm *tm1= localtime(&t);
	printf("Último acceso (A): %d:%d\n", tm1->tm_hour, tm1->tm_min);
	time_t t2 = buff.st_mtime;
	struct tm *tm2= localtime(&t2);
	printf("Último acceso (M): %d:%d\n", tm2->tm_hour, tm2->tm_min);
	time_t t3 = buff.st_ctime;
	struct tm *tm3= localtime(&t3);
	printf("Último acceso (C): %d:%d\n", tm3->tm_hour, tm3->tm_min);

	return 0;
}