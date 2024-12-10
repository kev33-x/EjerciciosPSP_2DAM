public class Consumidor2 extends Thread {
    private Cola2 cola;
    private int suma=0;
    private int n;

    //Constructor recibe la cola y un id para el hilo consumidor
    public Consumidor2(Cola2 c, int n) {
        cola = c;
        this.n = n;
    }

    public void run() {
        int valor = 0;

        try 
        {
            for (int i = 0; i < 10; i++) {
                valor = cola.get(); //recoge el n�mero
                suma = suma + valor;
                System.out.println("Consumidor "+ this.n +" suma total: "+suma);
                Thread.sleep(1000);
            }

        } catch (Exception e) {
            System.out.println("Ocurrio algun error...\n");
        }
        
    }
}