
public class Hilo3Ejecutar {
	public static void main(String[] args) {
		Hilo3 h1 = new Hilo3("Hilo 1");
		Hilo3 h2 = new Hilo3("Hilo 2");
		Hilo3 h3 = new Hilo3("Hilo 3");
			
		h1.start();
		h2.start();
		h3.start();
		
		System.out.println("3 HILOS INICIADOS...");
	}
}//Hilo3Ejecutar

//Para ejecutar el ejercicio 3 primero tengo que compilar ambos y luego el que ejecuto es el de Ejecutar ya que el normal no tiene main
