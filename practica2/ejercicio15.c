#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char ** argv) {


  if (argc < 2) {
     printf("Introduce la ruta de datos.\n");
     return -1;
  }

  int fd = open(argv[1], O_CREAT | O_RDWR, 00777);
  if (fd == -1) {
    printf("No se ha podido abrir/crear el fichero.\n");
    return -1;
  }

  struct flock lock;

  lock.l_type = F_UNLCK;
  lock.l_whence = SEEK_SET;
  lock.l_start = 0;
  lock.l_len = 0;
  lock.l_pid = getpid();


  int status = fcntl(fd, F_GETLK, &lock);

  if (lock.l_type == F_UNLCK) {
    printf("Cerrojo desbloqueado.\n");
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();

    if (fcntl(fd, F_GETLK, &lock) == -1) {
      printf("No se ha podido crear el cerrojo.\n");
      close(fd);
      return 1;
    } else {
      printf("Creado cerrojo de escritura\n");

      //Write Date
      time_t tim = time(NULL);

      struct tm *tm = localtime(&tim);

      char buffer[1024];

      sprintf (buffer, "Hora: %d:%d\n", tm->tm_hour, tm->tm_min);

      write(fd, &buffer, strlen(buffer));


      sleep(30);

      lock.l_type = F_WRLCK;
      lock.l_whence = SEEK_SET;
      lock.l_start = 0;
      lock.l_len = 0;
      lock.l_pid = getpid();
      
      if (fcntl(fd, F_GETLK, &lock) == -1) {
        printf("No se ha podido crear el cerrojo.\n");
        close(fd);
        return 1;
      } else
      close(fd);
    }

  } else {
    printf("Cerrojo bloqueado.\n");
    close(fd);
    return 1;
  }

  close(fd);


}
