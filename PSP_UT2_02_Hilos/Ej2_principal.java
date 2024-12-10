public class Ej2_principal {

    public static void main (String[]args)
    {
        Ej2_cola cola = new Ej2_cola();

        Ej2_productor prod1 = new Ej2_productor(cola);
        Ej2_consumidor cons1 = new Ej2_consumidor(cola, 1);
        Ej2_consumidor cons2 = new Ej2_consumidor(cola, 2);

        prod1.start();
        cons1.start();
        cons2.start();

    }
    
}