/*
Solicita simplificar fracciones

SE hace uso del gcd pues dado a / b  = >>>>  a/gcd(a,b)   / b/gcd(a,b)

N = Numero  de casos = 20 
1 <= p, q <=  10 ^ 30 Por ese motivo utilizamos java BigInteger
*/
import java.util.*;
import java.math.*;
class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();
		BigInteger p,q, gcd;
		while(cases-- > 0 ){
			p = sc.nextBigInteger();
			sc.next(); // lee el caracter de  division / (la diagonal)
			q = sc.nextBigInteger();
			gcd = p.gcd(q); // Obtiene el gcd de  dos numeros
			System.out.println( p.divide(gcd) + " / " +  q.divide(gcd));			
		}
	}
}