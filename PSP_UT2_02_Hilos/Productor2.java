import java.util.Random;

public class Productor2 extends Thread {

    private Cola2 cola;

    public Productor2(Cola2 c) {
        cola = c;
    }

    public void run() {
        
        Random numero_random = new Random();
        try 
        {
            for (int i = 0; i < 10; i++) 
            {
                int numero = numero_random.nextInt(100);
                cola.put(numero);
                Thread.sleep(500);
            }

        } catch (Exception e) 
        {
            System.out.println("Ocurrio un error....\n");
        }
    }
    
}
