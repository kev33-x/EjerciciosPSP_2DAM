//Usamoos runanble porque me permite heredar de varias clases, threads solo me permite de una
public class HiloContador implements Runnable {
 
    //Atributos
    private int contador;
    private String nombre;
    private int limite;
 
    //Constructor
    public HiloContador(String nombre, int limite) {
        this.contador = 0;
        this.nombre = nombre;
        this.limite = limite;
    }
 
    //Da igual si uso Thread o Runnable, run siempre tiene que estar para hacer la funcionaludad del hilo
    public void run() {
 
        //Recorremos los numeros
        while (contador <= limite) {
            System.out.println("Hilo " + nombre + ": " + contador);
            contador++;
        }
 
        //fin de hilo
        System.out.println("Hilo " + nombre + " finalizado"); 
    }
    
    
    public static void main(String[] args) {

        //Basicamente en lo que se diferencia este de Runnable es que tengo que crear dos veces, la primera como un objeto y luego ese objeto como un new thread
 
        //Creamos los objetos
        HiloContador c1 = new HiloContador("Contador 1", 40);
        HiloContador c2 = new HiloContador("Contador 2", 50);
        HiloContador c3 = new HiloContador("Contador 3", 20);
        HiloContador c4 = new HiloContador("Contador 4", 70);
 
        //Creamos los hilos
        Thread t1 = new Thread(c1);
        Thread t2 = new Thread(c2);
        Thread t3 = new Thread(c3);
        Thread t4 = new Thread(c4);
 
        //Iniciamos los hilos
        t1.start();
        t2.start();
        t3.start();
        t4.start();

        try
        {
            //El join espera a que termine el hilo y hasta que no se termine no realiza la siguiente accion, es por esto que ahora el mensaje del
            //fin del programa ahora si se pone a lo ultimo

            //El join tambien puede esperar un tiempo ene milisegundos, es decir si pongo 1000 ms seran 1 segundo
            t1.join();
            t2.join();
            t3.join();
            t4.join();
        }
        catch(Exception ex)
        {
            System.out.println("Error, ocurrio una excepcion "+ex.getMessage());
        }
	       
        //Fin
        System.out.println("Fin del programa");
    }
 
}
