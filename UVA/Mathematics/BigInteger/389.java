/*
Para el primer codigo utilize printf
muuuy tardado 2.6 segundos 

*/ 


// import java.util.*;
// import java.math.*;

// class Main{
// 	public static void main(String[] args) {
// 		Scanner sc = new Scanner(System.in);
// 		String n1; int ba1, ba2;
// 		while(sc.hasNext()){
// 			n1 = sc.next();
// 			ba1 = sc.nextInt();
// 			ba2 = sc.nextInt();
// 			BigInteger b1 = new BigInteger(n1, ba1);
// 			n1 = b1.toString(ba2);

// 			if(n1.length() > 7 )
// 					System.out.printf("  ERROR\n");
// 			else
// 				System.out.printf("%7S\n", n1);
// 		}
// 	}
// }


/*
Para este segundo codigo
utilizaré StringBuilder ahi creo el output y al final lo imprimo

LECCION La impresion es muy costosa en java es mejor crear todo el output en una cadena y luego  imprimirla!!

usar StringBuilder sb = new StringBuilder();
luego el metodo sb.append("cadena");
*/


/*
import java.util.*;
import java.math.*;

class Main{
	public static void main(String[] args) {
		Scanner sc  = new Scanner(System.in);
		String n1; int ba1,ba2;	
		StringBuilder sb = new StringBuilder();
		while(sc.hasNext()){
			n1 = sc.next();
			ba1 = sc.nextInt();
			ba2 = sc.nextInt();
			BigInteger b1 = new BigInteger(n1, ba1);
			n1 = b1.toString(ba2);
			int len = n1.length();
			if(len > 7 ) sb.append("  ERROR");
			else{
				for(int i = len; i < 7; i++) sb.append(" ");
				sb.append(n1.toUpperCase());
			}
			sb.append("\n");
		}
		System.out.print(sb.toString());
	}
}*/



/*

Tercera opcion sugerida por el libro-

Utilizar  java Integer class tambien tiene un metodo de conversion de base para enteros de 
32 bits.

*/

import java.util.*;
import java.math.*;

class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		String n1;int ba1, ba2;
		while(sc.hasNext()){
			n1 = sc.next();
			ba1 = sc.nextInt();
			ba2 = sc.nextInt();
			Integer b1 = Integer.parseInt(n1, ba1);
			n1 = b1.toString(b1, ba2);
			int len = n1.length();
			if(len > 7 ) sb.append("  ERROR");
			else{
				for(int i = len ; i < 7 ; i++) sb.append(" ");
				sb.append(n1.toUpperCase());
			}
			sb.append("\n");
		}
		System.out.print(sb.toString());
	}
}