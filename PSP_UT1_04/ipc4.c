#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <time.h>
#include <string.h> //este es importante para usar el strlen()

//0 lectura, 1 escritura

//P1 genera u numero aleatorio y lo escrib en pipe1
//p2 le de pipe1, hace el factorial y lo escrib en pipe2
//p1 lee de pipe2 y muestra el resultado
int main()
{

    int fd[2];
    int fd_2[2];

    pid_t pid;
    pipe(fd);
    pipe(fd_2);


    pid = fork();
    if(pid == 0)
    {

        int numero1, resultado = 1;

        close(fd[1]);
        read(fd[0], &numero1, sizeof(numero1));
        close(fd[0]);

        //Calcular factorial
        for (int i = numero1; i > 0; i--)
        {
            resultado = resultado * i;
        }
        
        //Ahora escribo el resultado en el pipe2
        close(fd_2[0]);
        write(fd_2[1], &resultado, sizeof(resultado));
        close(fd_2[1]);
        
    }
    else
    {
        //codigo para generar aleatorio
        time_t t;
        int numero1, numero2, resultado;
        srand((unsigned) time(&t));
        //Generamos numero aleatorio entre 1 y 10
        numero1=rand() % 10; 

        close(fd[0]);
        write(fd[1], &numero1, sizeof(numero1));
        close(fd[1]);

        //Ahora leo del pipe2
        close(fd_2[1]);
        read(fd_2[0], &resultado, sizeof(resultado));
        close(fd_2[0]);

        printf("El factorial calculado por el proceso hijo: %d != %d \n", numero1, resultado);

        wait(NULL);
    }
    return(0);
}