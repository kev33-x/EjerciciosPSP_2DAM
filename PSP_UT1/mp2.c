/* Mostrar el pid y el ppid de un proceso */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> //al importar esto me libro del warning que me da al compilar por el wait ademas de que pid_t ya no me da error

void main()
{
   pid_t pid1, pid2, pid_hijo;
   
   pid1 = fork();
   
   if (pid1 == 0)
   {
    	
    	pid2 = fork();
      if (pid2 == 0)
      {
         printf("Soy el proceso P3, mi pid es %d y el de mi padre es %d \n", getpid(),getppid());
      }
      else
      {
         
         //El proceso espera a que su hijo termine con wait(NULL)
         wait(NULL);
         
         //este else es importante ya que en este caso el proceso p2 tiene que esperar a que su hijo termine primero el codigo ya que si no el proceso p3 se queda huerfano, basicamente es como el proceso p1 y p2
         printf("Soy el proceso P2, mi pid es %d y el de mi padre es %d \n", getpid(),getppid());
      }
   }
   else
   {
   	pid_hijo = pid1;
   	wait(NULL);
   	printf("Soy el proceso P1, mi pid es %d y el de mi proceso hijo es %d\n", getpid(), pid_hijo);
   }
}
