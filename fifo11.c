//Proceso que escribe en PIPE FIFO
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h> 


int main()
{
  int fp;
  char saludo[] = "Un saludo!!!\n";
  //utiliza el pipe que he creado en el archivo _lee
  
  //el 1 es el modo en el que abro el fichero, 1 es para ecritura y 0 para lectura
  fp = open("FIFO2", 1);
 
  
  printf("Mandando información al pipe FIFO...\n");
  write(fp,saludo, strlen(saludo));
  close(fp);   
  return 0; 
}