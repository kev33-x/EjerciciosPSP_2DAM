#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <time.h>
#include <string.h> //este es importante para usar el strlen()

//0 leer 1 escribir

//p2 recibe los numeros por teclado, los escribe en el pipe1 y luego p1 lee desde pipe1 para
//calcular la letra del nie, luego escribe la letra en pipe 2 y por ultimo p2 lee desde pipe2 para mostrar el resultado
int main()
{

    int fd[2];
    int fd_2[2];
    pid_t pid;

    pipe(fd);
    pipe(fd_2);

    pid = fork();
    if( pid == 0 )
    {
        int numeros_del_nif;
        char letra_calculada;

        printf("Escribe los 8 numeros de tu NIF: ");
        /*** scanf() sirve para pedir datos por pantalla ***/
        scanf("%d", &numeros_del_nif);

        close(fd[0]);
        write(fd[1], &numeros_del_nif, sizeof(numeros_del_nif));
        close(fd[1]);


        //ahora leo desde pipe2 la letra calculada
        close(fd_2[1]);
        read(fd_2[0], &letra_calculada, sizeof(letra_calculada));
        close(fd_2[0]);

        printf("la letra del NIF es: %c \n", letra_calculada);
    }
    else
    {
        int numeros_del_nif;
        char letra_calculada;

        close(fd[1]);
        read(fd[0], &numeros_del_nif, sizeof(numeros_del_nif));
        close(fd[0]);

        //Calcular la letra de control del NIF
        int nif;
        char letra[] = "TRWAGMYFPDXBNJZSQVHLCKE";
        nif = numeros_del_nif % 23;
        
        letra_calculada = letra[nif];


        close(fd_2[0]);
        write(fd_2[1], &letra_calculada, sizeof(letra_calculada));
        close(fd_2[1]);

        wait(NULL);
    }
    return(0);
}