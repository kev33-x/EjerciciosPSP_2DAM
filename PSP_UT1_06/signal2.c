#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

int contador = 0;


//int(signo) porque al ejecutarse una señal, esta devuelve su numero de señal, entonces puedo recojerlo
//para usarlo por ejemplo para escribir algo como "se ha ejecutado la señal 10"
void manejador(int numero_senal) 
{
    //Al entrar en manejador hace esto
    contador = contador + 5;  
    printf("Han transcurrido %d segundos\n", contador);

    //pero como aqui defino otra alarma, basicamente entra dentro de un bucle de manejadores
    alarm(5);  
}

int main() 
{
    //importante saber que signal solo le define que tiene que hacer una determinada señal
    //basicamente el primer argumento es el nombre y el segundo lo que tiene que hacer
    signal(SIGALRM, manejador); 

    //Ahora como alarm tiene que hacer un manejador, inicio una
    alarm(5);


    // pause() lo que hace es esperar a que le llegue una señal, mientras esto pausa el programa, en este 
    /// caso cada vez que se ejecuta un alarm, pause lo recoje pero como es un bucle esto ocurre de forma indefinida
    //Luego al yo hacer un control + c fuerzo a que el programa termine, es como si hiciera un break basicamente
    while (1) 
    {
       pause(); 
    }

    return 0;
}
