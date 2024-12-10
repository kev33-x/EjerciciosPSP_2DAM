import java.util.concurrent.ArrayBlockingQueue;

public class Ej2_cola {

    private static final int CAPACIDAD = 5;
    private final ArrayBlockingQueue<Integer> cola = new ArrayBlockingQueue<>(CAPACIDAD);
    int vuelta = 0;

    public synchronized void put(int numero) throws InterruptedException{

        while (cola.size() == CAPACIDAD) {
            System.out.println("Productor espera, cola llena...");
            wait();
        }

        cola.add(numero);
        System.out.println("Productor produce: " + numero);
        notifyAll();

    }

    public synchronized int get() throws InterruptedException{

        vuelta = vuelta + 1;

        if (vuelta % 2 == 0) //si no es verdadero, es que esta en la primera vuelta
        {
            while (cola.isEmpty()) {
                System.out.println("Consumidor espera, cola vacía...\n");
                wait();
            }
            Thread.sleep(10);
            int numero = cola.poll();
            //System.out.println("Consumidor consume: " + numero);
            notifyAll();
            
            return numero;
        }
        else
        {

            while (cola.isEmpty()) {
                System.out.println("Consumidor espera, cola vacía...\n");
                wait();
            }
            int numero = cola.peek();
            //System.out.println("Consumidor consume: " + numero);
            notifyAll();

            return numero;
        }
    }
}