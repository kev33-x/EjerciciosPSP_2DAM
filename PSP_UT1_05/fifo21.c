//Proceso que escribe en PIPE FIFO
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h> 
#include <time.h>



//Este es lo mismo que el fifo11 de escribir solo que en este ejercicio se reutiliza el mismo fifo y no se crean 2
int main()
{

  int fd;

  //Primero calculamos el numero aleatorio entre 0 y 10
  //codigo para generar aleatorio
  time_t t;
  int numero_aleatorio;
  srand((unsigned) time(&t));
  //Generamos numero aleatorio entre 1 y 10
  numero_aleatorio=rand() % 10;

  //Creamos el fifo
  mkfifo("PIPE02", 0666);
  fd = open("PIPE02", O_WRONLY); //lo ponemos en modo escritura
  write(fd, &numero_aleatorio, sizeof(numero_aleatorio)); //escribimos en el fifo
  close(fd); //lo cerramos


  //Ahora leemos del mismo fifo pero actualado porque fifo22 me paso un resultado
  int resultado_factorial;

  fd = open("PIPE02", O_RDONLY);
  read(fd, &resultado_factorial, sizeof(resultado_factorial));
  close(fd);
  
  printf("El resultado del factorial de %d es %d \n", numero_aleatorio, resultado_factorial);

  remove("PIPE02");

  return(0);
}
