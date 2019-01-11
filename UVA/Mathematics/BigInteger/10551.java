/*
Existe un constructor de la clase biginteger
	recibe dos argumentos -> numero (usamos metodo next() para recibirlo como cadena ) y la base del numer como  entero
	crea el objeto BigInteger a partir de estos argumentos.

Existe un metodo mod b1.mod(b2)

luego el metodo toString puede recibir como parametro un entero 
-> dicho entero indica la base en la que se va a imprimir el numero 

*/

import java.util.*;
import java.math.*;

class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int b;
		while(true){
			b = sc.nextInt();
			if(b == 0 ) break;
			BigInteger p = new BigInteger(sc.next(), b);
			BigInteger m = new BigInteger(sc.next(), b);
			BigInteger res = p.mod(m);
			System.out.println(res.toString(b));
		}
	}
}	