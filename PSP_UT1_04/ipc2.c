#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <time.h> //Este nos sirve para generar los numeros aleatorios 
#include <string.h> //este es importante para usar el strlen()


//padre escribe, hiijo lee y escribe segun lo que le pasa el padre. 0 leer, 1 escribir
int main()
{
    int fd[2];

    pid_t pid;
    pipe (fd);

    pid = fork();
    if (pid == 0)
    {
        int numero1, numero2, numero3, suma;
        char letra;

        close(fd[1]); //cierro la escritura

        read(fd[0], &numero1, sizeof(numero1));
        printf("Numero a sumar: %d \n", numero1);

        read(fd[0], &numero2, sizeof(numero2));
        printf("Numero a sumar: %d \n", numero2);

        read(fd[0], &numero3, sizeof(numero3));
        printf("Numero a sumar: %d \n", numero3);

        read(fd[0], &letra, sizeof(letra));
       
        if (letra == '+')
        {
            printf("Recibido caracter: %c \n", letra);

            suma = numero1 + numero2 + numero3;
            printf("La suma total es %d \n", suma);
        }
    }
    else
    {
        close(fd[0]); //ciero la lectura

        int numero1 =25 , numero2 = 18, numero3= 67;
        char letra = '+';

        write(fd[1], &numero1, sizeof(numero1));
        write(fd[1], &numero2, sizeof(numero2));
        write(fd[1], &numero3, sizeof(numero3));
        write(fd[1], &letra, sizeof(letra));

        wait(NULL);
    }
    return(0);
}