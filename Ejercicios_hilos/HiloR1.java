//Clase implementa interfaz Runnable.
// La interfaz Runnable añade la funcionalidad de Hilos a una clase con solo implementarla
// Runnable proporciona un único método "run"
public class HiloR1 implements Runnable {

    //método run -> funcionalidad del hilo, como implemento la interfaz nunable tengo que poner este metodo si o si
	public void run() {
		System.out.println("Hola desde el Hilo: " +  Thread.currentThread().getId());
	}
}
