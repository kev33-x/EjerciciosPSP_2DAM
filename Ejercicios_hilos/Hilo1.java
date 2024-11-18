//Clase Hilo1 extiende Thread
public class Hilo1 extends Thread {
	private int x;

    // Constructor de la clase
	Hilo1(int x) {
		this.x = x;
	}

    // metodo run -> funcionalidad del hilo, siempre aqui, la terea que hace el hilo siempre aqui
	public void run() {
		for (int i = 0; i < x; i++)
			System.out.println("Ejecutando dentro del Hilo... " + i);
	}

	//El hilo como tal lo declaro en la clase main
	public static void main(String[] args) {
		Hilo1 p = new Hilo1(10);
		p.start(); //start se encarga de usar el metodo run
	}// main

}//PrimerHilo
