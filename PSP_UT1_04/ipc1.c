#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <time.h>
#include <string.h> //este es importante para usar el strlen()

void main(){

     int fd[2]; 
     char buffer[30];
     pid_t pid;
     
     // Creamos el pipe
     pipe(fd); 
     
     //Se crea un proceso hijo
     pid = fork();
     
     if (pid==0)
     
     {
        close(fd[1]); // Cierra el descriptor de escritura
        printf("Soy el proceso hijo con pid %d \n", getpid());
        read(fd[0], buffer, sizeof(buffer) - 1);   //Aqui intenta leer pero como no hay nada entonces baja hacia el otro proceso donde el padre escribe

        printf("\t Fecha/hora: %s \n", buffer);  //la \t sirve para poner el mensaje centrado
     }
     else
     {
     		time_t hora;
     		char*fecha;
     
     		time(&hora);
     		fecha=ctime(&hora);
     
        close(fd[0]); // Cierra el descriptor de lectura
        write(fd[1], fecha  , strlen(fecha) + 1);  //escribe para que el hijo pueda leer
        wait(NULL);    
     }
     
   exit(0);   
}

// ****** En estos ejercicios con pipes es importante usar strlen(lo que quiera poner) para sacar la longitus de bytes
//de lo que yo quiera escribir ya que si no tendria que contarlos manualmente, en esto siempre debo poner
// strlen(x) + 1 ya que hay que tener en cuenta un caracter que es \0 el cual cierra el char

//Tambien sucede lo mismo al leer con sizeof(buffer) - 1, ahi se tiene en cuenta ese caracter
