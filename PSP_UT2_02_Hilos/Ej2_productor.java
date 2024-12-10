import java.util.Random;

public class Ej2_productor extends Thread{

    private Ej2_cola cola;

    public Ej2_productor(Ej2_cola cola) {
        this.cola = cola;
    }

    @Override
    public void run() {

        Random random = new Random();
        try 
        {
            for (int i = 0; i < 10; i++) 
            {
                int numero = random.nextInt(10);
                cola.put(numero);
                Thread.sleep(500); // Simula el tiempo de producción
            }
        } 
        catch (InterruptedException e) 
        {
            System.out.println("Ocurrio un error...\n");
        }
    }
    
}
