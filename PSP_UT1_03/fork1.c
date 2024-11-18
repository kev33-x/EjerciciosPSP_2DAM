#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 

int main()
{
    pid_t pid_p2, pid_p3, pid_p4, pid_padre;

    //creo al primer hijo p2
    pid_p2 = fork();
    if (pid_p2 ==  0)
    {
        //proceso del primer hijo
        if (getpid() %2 == 0)
        {
            printf("Soy p2 mi pid es %d y el de mi padre es %d \n", getpid(), getppid());
        }
        else
        {
            printf("Soy p2 mi pid es %d \n", getpid());
        }
    }
    else //proceso padre de todos
    {
        
        wait(NULL); //espero a que termine el proceso hijo p2

        //creo a otro proceso hijo p3, p2 y p3 son hermanos
        pid_p3 = fork();
        if (pid_p3 == 0)
        {
            //Creo a p4 que será hijo de p3
            pid_p4 = fork();
            if (pid_p4 == 0)
            {
                if (getpid() %2 == 0)
                {
                    printf("Soy p4 mi pid es %d y el de mi padre es %d \n", getpid(), getppid());
                }
                else
                {
                    printf("Soy p4 mi pid es %d \n", getpid());
                }
            }
            else
            {
                // P3 que es el padre de P4 espera a que su hijo termine
                wait(NULL);
                if(getpid() %2 == 0)
                {
                    printf("Soy p3, mi pid es %d y el de mi padre es %d \n", getpid(), getppid());
                }
                else
                {
                    printf("Soy p3, mi pid es %d \n", getpid());
                }
            }
        }
        else //proceso padre de todos
        {
            //espero a que el hijo p3 termine 
            wait(NULL);

            pid_padre = getpid();
            if(pid_padre %2 == 0)
            {
                printf("Soy el proceso padre p1, mi pid es %d y el de mi padre es %d \n", pid_padre, getppid());
            }
            else
            {
                printf("Soy el proceso padre p1, mi pid es %d \n", pid_padre);
            }
        }
    }
    exit(0);
}

//a) en este programa la ejecucion siempre sera la misma ya que los padres
//siempre esperan a sus hijos
//El orden sera--- >  P2 --> P4 ---> P3 ---> P1 (padre de todos)