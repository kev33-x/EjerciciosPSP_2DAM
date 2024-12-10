public class Ej2_consumidor extends Thread{

    private Ej2_cola cola;
    private int id;

    public Ej2_consumidor(Ej2_cola cola, int id) {
        this.cola = cola;
        this.id = id;
    }


    @Override
    public void run() {
        int sumaTotal = 0;
        int producto_total = 1;
        try 
        {
            if (this.id %2 == 0)
            {
                for (int i = 0; i < 10; i++) 
                {
                    int numero = cola.get(id);
                    producto_total = producto_total * numero;
                    System.out.println("Consumidor "+id+" producto total: " + producto_total);
                    Thread.sleep(500); // Simula el tiempo de consumo
                }
            }
            else
            {
                for (int i = 0; i < 10; i++) 
                {
                    int numero = cola.get(id);
                    sumaTotal += numero;
                    System.out.println("Consumidor "+id+" suma total: " + sumaTotal);
                    Thread.sleep(500); // Simula el tiempo de consumo
                }
            }
        } 
        catch (InterruptedException e) 
        {
            System.out.println("Ocurrio un error...\n");
        }
    }
    
}