public class SumNumHilos_solucion extends Thread{

    //Variable acumula la suma 
    private static long totalSum = 0;
	private final int start;
    private final int end;
	
	// Constructor de la clase
	SumNumHilos_solucion(int start, int end) 
	{
        this.start = start;
        this.end = end;	
    } 

	//synchronized lo que hace es proteger la variable totalSum hasta que un hilo termine de modificarla
	public static synchronized void suma(int i)
	{
		totalSum = totalSum + i;
	}
							
	// metodo run -> funcionalidad del hilo
	public void run() 
	{
	
		for (int i = start; i < end; i++)
		{
			suma(i);
		}
	}
						

    public static void main(String[] args) 
	{
      		SumNumHilos hilo1=new SumNumHilos(1,10000);
			SumNumHilos hilo2=new SumNumHilos(10001,20000);
			SumNumHilos hilo3=new SumNumHilos(20001,30000);
			   
		    hilo1.start();
		    hilo2.start();
			hilo3.start();

			try
			{
				hilo1.join();
				hilo2.join();
				hilo3.join();
			}
			catch(Exception ex)
			{
				System.out.println("Error");
			}
			   
        	System.out.println("La suma total es: " + totalSum);
    }
}
