#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>


void manejador(int numero_senal)
{
    
    time_t hora;
    struct tm*hora_local;  
    

    time(&hora);
    hora_local = localtime(&hora);

    int horas = hora_local ->tm_hour;
    int minutos = hora_local ->tm_min;
    int segundos = hora_local ->tm_sec;

    printf("Señal de alarma recibida a las %02d : %02d : %02d\n", horas, minutos, segundos);
}


int main()
{
    int veces_repetir, segundos_repetir, i=0;

    printf("¿Cuantas veces sonara la alarma?: ");
    scanf("%d", &veces_repetir);

    printf("¿Cada cuantos segundos se repetira la alarma?: ");
    scanf("%d", &segundos_repetir);


    signal(SIGALRM, manejador);
    printf("Alarma activada \n");

    while (i<=veces_repetir)
    {
        alarm(segundos_repetir);
        pause();
        i++;
    }

    printf("Alarma desativada \n");

    return(0);
}