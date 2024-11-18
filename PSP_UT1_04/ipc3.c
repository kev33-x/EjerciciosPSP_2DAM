#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <time.h>
#include <string.h> //este es importante para usar el strlen()


//El hijo tiene que escribir 2 numeros aleatorios y el padre tien que recibirlos para hacer operaciones matematicas
// 0 leer 1 escribir
int main()
{

    int fd[2];
    
    pid_t pid;
    pipe(fd);

    pid = fork();
    if (pid == 0)
    {
        close(fd[0]);

        time_t t;
        int numero1, numero2;
        srand((unsigned) time(&t));
        //Generamos numero aleatorio entre 1 y 50
        numero1=rand() % 50; 
        numero2=rand() % 50;

        write(fd[1], &numero1, sizeof(numero1));
        write(fd[1], &numero2, sizeof(numero2));
    }
    else
    {
        int numero1, numero2, resultado;

        close(fd[1]);

        read(fd[0], &numero1, sizeof(numero1));
        read(fd[0], &numero2, sizeof(numero2));

        //suma
        resultado = numero1 + numero2;
        printf(" %d + %d = %d \n", numero1, numero2, resultado);
        

        //resta
        resultado = numero1 - numero2;
        printf(" %d - %d = %d \n", numero1, numero2, resultado);
        

        //multiplicacion
        resultado = numero1 * numero2;
        printf(" %d * %d = %d \n", numero1, numero2, resultado);
        

        //division
        resultado = numero1 / numero2;
        printf(" %d / %d = %d \n", numero1, numero2, resultado);

    }
    return(0);
}