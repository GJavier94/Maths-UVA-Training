/*
1 version ac pero con time 1.6sec too slow
*/

// import java.util.*;
// import java.math.*;

// class Main{
// 	static BigInteger fib(BigInteger n ){
// 		if(n.equals( BigInteger.ZERO)) return BigInteger.ZERO;	
// 		if(n.equals(BigInteger.ONE)) return BigInteger.ONE;

// 		BigInteger f0 = BigInteger.ZERO, f1 = BigInteger.ONE, fi = f0;

// 		for(int i = 2; i <= n.intValue() ; i++){
// 			fi = f0.add(f1);
// 			f0 = f1;
// 			f1 = fi;
// 		}
// 		return fi;
// 	}
// 	public static void main(String[] args) {		
// 		Scanner sc = new Scanner(System.in);
// 		StringBuilder sb = new StringBuilder();

// 		while(sc.hasNext()){
// 			BigInteger n  = new BigInteger(sc.next());
// 			sb.append("The Fibonacci number for " + n + " is " + fib(n) + "\n");
// 		}
// 		System.out.print(sb);
// 	}
// }



/*
	2 version precalculo de los n = 5000 elementos de la serie de fibonacci
	-> uso de variables  y metodos staticos
	BUENA solucion -> time 0.540

	Aprendizaje 
		*como generar n elementos de la serie 
		*uso de un arreglo BigInteger Clase nombre[] = new Clase[tam];

*/
import java.util.*;
import java.math.*;

class Main{
	static BigInteger f[] = new BigInteger[50001];
	static void precalc(){
		f[0] = BigInteger.valueOf(0);f[1] = BigInteger.valueOf(1);
		for(int i = 2; i < 5001; i++) f[i] = f[i - 2].add(f[i - 1 ]) ;		
	}
	public static void main(String[] args) {
		precalc();
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		while(sc.hasNext()){
			int n = sc.nextInt();
			sb.append("The Fibonacci number for " + n + " is " + f[n].toString() + "\n");
		}
		System.out.print(sb);
	}
}