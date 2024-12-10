public class Prod_cons2 {
    public static void main(String[] args) {  
      
      Cola2 cola = new Cola2();
      
      Productor2 prod = new Productor2(cola);	
      Consumidor2 cons = new Consumidor2(cola, 1);
      
      prod.start();
      cons.start();
      
  
    }
  }