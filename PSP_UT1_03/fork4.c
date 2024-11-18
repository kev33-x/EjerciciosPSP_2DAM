#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 


void main()
{
    pid_t pid_padre, pid_p2, pid_p3, pid_p4, pid_p5;
    int acumulado = getpid();
    printf("El valor inicial de acumulado es el valor del proceso padre, osea %d \n",acumulado);

    pid_p2 = fork();
    if (pid_p2 == 0)
    {
        pid_p5 = fork();
        if(pid_p5 == 0)
        {
            //p5 será el primero en hacer algo
            if(getpid() %2 == 0)
            {
                acumulado = acumulado + 10;
                printf("P5: soy par y el valor de acumulado es %d \n",acumulado);
            }
            else
            {
                acumulado = acumulado - 100;
                printf("P5: soy impar y el valor de acumulado es %d \n",acumulado);
            }
        }
        else
        {
            //p2 espera a que su hijo p5 termine, p2 sera el segundo en hacer algo
            wait(NULL);

            if(getpid() %2 == 0)
            {
                acumulado = acumulado + 10;
                printf("P2: soy par y el valor de acumulado es %d \n",acumulado);
            }
            else
            {
                acumulado = acumulado - 100;
                printf("P2: soy impar y el valor de acumulado es %d \n",acumulado);
            }
        }
    }
    else
    {
        //espera a que su hijo p2 termine
        wait(NULL);

        pid_p3 = fork();
        if (pid_p3 == 0)
        {
            
            pid_p4 = fork();
            if(pid_p4 == 0)
            {
                //p4 sera el tercero en hacer algo
                if(getpid() %2 == 0)
                {
                    acumulado = acumulado + 10;
                    printf("P4: soy par y el valor de acumulado es %d \n",acumulado);
                }
                else
                {
                    acumulado = acumulado - 100;
                    printf("P4: soy impar y el valor de acumulado es %d \n",acumulado);
                }
            }
            else
            {
                wait(NULL);

                //p3 sera el cuarto en hacer algo
                if(getpid() %2 == 0)
                {
                    acumulado = acumulado + 10;
                    printf("P3: soy par y el valor de acumulado es %d \n",acumulado);
                }
                else
                {
                    acumulado = acumulado - 100;
                    printf("P3: soy impar y el valor de acumulado es %d \n",acumulado);
                }
            }
        }
        else
        {
            //el proceso padre espera a que p3 termine (es su otro hijo), p1 sera el ultimo que haga algo
            wait(NULL);
            printf("soy p1 \n");
        }
    }
    exit(0);
}