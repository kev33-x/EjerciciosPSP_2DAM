//Proceso que lee del PIPE FIFO
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h> 



int main(void)
{
  
  int fd, numero_aleatorio, resultado=1;

  //Leemos el numero y en este caso lo muestro por pantalla 
  fd = open("PIPE02", O_RDONLY);
  read(fd, &numero_aleatorio, sizeof(numero_aleatorio));
  printf("El numero aleatorio pasado por PIPE02 es %d \n", numero_aleatorio);
  close(fd);

  //Calcular factorial
  for (int i = numero_aleatorio; i > 0; i--)
  {
    resultado = resultado * i;
  }

  //Ahora con el resultado me tengo que crear un FIFO2 y escribir el resultado para que fifo11 lo lea

  fd = open("PIPE02", O_WRONLY);
  write(fd, &resultado, sizeof(resultado));
  close(fd);

  return(0);
}

