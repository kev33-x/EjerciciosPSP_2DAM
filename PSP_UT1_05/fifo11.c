//Proceso que escribe en PIPE FIFO
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h> 
#include <time.h>



int main()
{

  int fd;

  //Primero calculamos el numero aleatorio entre 0 y 10
  //codigo para generar aleatorio
  time_t t;
  int numero1;
  srand((unsigned) time(&t));
  //Generamos numero aleatorio entre 1 y 10
  numero1=rand() % 10;

  //Creamos el fifo
  mkfifo("FIFO1", 0666);
  fd = open("FIFO1", O_WRONLY); //lo ponemos en modo escritura
  write(fd, &numero1, sizeof(numero1)); //escribimos en el fifo
  close(fd); //lo cerramos


  //Ahora leemos del FIFO2
  int fd2, resultado_factorial;

  fd2 = open("FIFO2", O_RDONLY);
  read(fd2, &resultado_factorial, sizeof(resultado_factorial));
  close(fd2);

  printf("El resultado del factoria de %d es %d \n", numero1, resultado_factorial);

  remove("FIFO1");
  remove("FIFO2");

  return(0);
}
