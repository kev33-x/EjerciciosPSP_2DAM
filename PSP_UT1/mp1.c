/* Mostrar el pid y el ppid de un proceso */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 

int main()
{
   pid_t pid, pid_hijo;
   
   pid = fork();
   
   if (pid == 0)
   {
    	printf("Soy el proceso hijo, el nombre del alumno es Kevin Sancan \n");
    	exit(0);
   }
   else
   {
   	pid_hijo = pid;
   	wait(NULL);
   	printf("Soy el proceso padre, mi pid es %d y el de mi proceso hijo es %d\n", getpid(), pid_hijo);
      //Esto funciona porque como estoy en el proceso padre (getpid) me devuelve el pid del proceso actual
      //asi que obtengo el mio (padre) y como antes ya me devuelve el pid del hijo al hacer fork, pues
      //simplemnte uso la variable (pid) que ya lo contiene 
   }
   return(0);

}
