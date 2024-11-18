#include <stdio.h>
//este de signal es nuevo, hay que incluirlo
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>


/* Función para gestión de señales*/
void manejador()
{
  time_t hora;
  struct tm*hora_local;  
  

  time(&hora);
  hora_local = localtime(&hora);

  printf("Fin del proceso %d  %02d/%02d/%04d   %02d:%02d:%02d\n", getpid(), hora_local->tm_mday, hora_local->tm_mon + 1, hora_local->tm_year + 1900, 
  hora_local->tm_hour, hora_local->tm_min, hora_local->tm_sec);
 
}

int main()
{

  time_t hora;
  struct tm*hora_local;  
 
  time(&hora);
  //ahora le doy el formato que quiero
  hora_local = localtime(&hora);
  printf("Inicio del proceso   %d  %02d/%02d/%04d   %02d:%02d:%02d\n",  getpid(), hora_local->tm_mday, hora_local->tm_mon + 1, hora_local->tm_year + 1900, 
  hora_local->tm_hour, hora_local->tm_min, hora_local->tm_sec);

  signal(SIGINT, manejador);
  pause();
  
  
  return(0);
}
