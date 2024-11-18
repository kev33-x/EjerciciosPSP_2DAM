#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> //al importar esto me libro del warning que me da al compilar por el wait ademas de que pid_t ya no me da error

void main()
{
    pid_t pid1, pid2, pid_hijo;

    pid1 = fork();

    if(pid1 == 0)
    {
        sleep(10);
        printf("Despierto \n");
    }
    //este else es muy importante onerlo ya que si hago el fork afuera del else lo que estaria pasando que tanto el proceso padre P1 como el primer hijo P2 estarian ejecutando el fork y yo solo quiero que lo ejecute el padre P1
    else 
    {
        //espero a que el primero hjo p2 termine
        wait(NULL);

        pid2 = fork();

        if(pid2 == 0)
        {

            printf("Soy el proceso P3, mi pid es %d y el de mi padre es %d \n", getpid(), getppid());
        }
        else
        {
            //espero a que el proceso hijo p3 termine
            wait(NULL);
        }
        
    }
}