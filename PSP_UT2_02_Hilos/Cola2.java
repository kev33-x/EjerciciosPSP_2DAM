import java.util.concurrent.ArrayBlockingQueue;

public class Cola2 {
	private static final int capacidad = 5;
	private final ArrayBlockingQueue<Integer> cola_array = new ArrayBlockingQueue<>(capacidad);
    
    public synchronized int get() throws InterruptedException{

         // Queda a la espera hasta que la cola se llene ("mientras cola vacía espero en wait()")
    	  while(cola_array.isEmpty())
		  {
				System.out.println("La cola esta vacia, el consumidor tiene que esperar \n");
				wait();
		  }
		  //poll devuelve el valor y lo elimina de esa posicion
		  int numero = cola_array.poll();
		  System.out.println("Consumidor consume: "+numero);

    	  notifyAll();

		  return numero;
    	}


    public synchronized void put(int valor) throws InterruptedException {
     // Queda a la espera hasta que la cola se vacíe ("mientras haya datos en la cola espero en wait()")
    	  while (cola_array.size() == capacidad )
		  {
    	    System.out.println("La cola esta llena, el productor tiene que esperar \n");
			wait();
    	  }
		  cola_array.add(valor);
		  System.out.println("El productor produce: "+ valor);
    	  notifyAll();
    	}
}