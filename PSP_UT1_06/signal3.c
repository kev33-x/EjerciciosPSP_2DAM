#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>


void manejador(int num_senal)
{

    time_t hora;
    struct tm*hora_local;  
    

    time(&hora);
    hora_local = localtime(&hora);

    int horas = hora_local ->tm_hour;
    int minutos = hora_local ->tm_min;
    int segundos = hora_local ->tm_sec;


    //printf("La hora es %02d:%02d:%02d \n", horas, minutos, segundos);

    //esto me crea un archivo 
    FILE *archivo = fopen("salidas.txt", "a");

    // Escribir la línea en el archivo
    fprintf(archivo, "Señal SIGINT recibida a las %02d : %02d : %02d\n", horas, minutos, segundos);

    // Cerrar el archivo
    fclose(archivo);
}


int main()
{

    signal(SIGINT, manejador);
    while(1)
    {
        pause();
    }
    return(0);
}