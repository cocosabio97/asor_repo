#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv) {


	if (argc < 2) {
		 printf("Introduce la ruta de datos.\n");
		 return -1;
	}


  int fd = open(argv[1], O_CREAT | O_RDWR, 00777);
  if (fd == -1) {
    printf("No se ha podido abrir/crear el fichero.\n");
    return -1;
  }

  int fd2 = dup2(fd, 1);

  printf("El nuevo archivo se encuentra en:\n", argv[1]);

  dup2(fd2, fd)

  return 1;
}