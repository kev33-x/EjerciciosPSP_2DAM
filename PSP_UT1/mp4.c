#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 

void main()
{

 printf("CCC \n");
 if (fork()!=0)
 {
    //wait perteneciente a la respuesta del literar c), no estaba antes de responderlo
    wait(NULL);
    printf("AAA \n");
 } 
 else
 {
    printf("BBB \n");
 } 

 exit(0);

}

//Respuestas -----

//a)  P1 (1000)-----> P2 (10001)

//b) pueden producirse hasta 3 salidas distintas, al inicio del programa simepre se ejcutara para que salga "CCC" 
//puesto a que lo hace el programa padre, luego dentro del if sigue siendo el padre ya que comprueba si el pid 
//es distinto de 0, entonces puede ser que primero ejecute el padre y luego el hijo. Quedando la salida 
//como "CCC AAA BBB" o bien que se ejecute solo el padre y se termine el programa ya que no tiene ningun wait(NULL)
//provocando que la salida quede como "CCC AAA"
//Por ultimo puede que se ejecute primero el padre antes de cerar el fork y luego el hijo se ejecute primero en el else
//quedando una salida como "CCC BBB AAA"
//En definitiva las combinaciones posibles son "CCC AAA BBB", "CCC AAA", "CCC BBB AAA"


//c) para que la salida del codigo qued como "CCC BBB AAA" debemos esperar a que primero termine de ejcutar el hijo
//entonces simplemtne ponemos un wait(null) en el codigo que solo ejecuta el padre (dentro del if)
