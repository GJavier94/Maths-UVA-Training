/*
AC =)

Puntos:

Theorema de fermat para p primo y a > 1 a^p == a mod p
pseudoprimos : hay p's no primos que que secumple la propiedad para algún 

habia que checar que  no fuera primo y que si se cumpliera la propiedad =).
a1.modPow(p1, p1). .> todos son BigInteger a1^p1 mod p1

*/
import java.util.*;
import java.math.*;
class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		int p, a;
		while(true){
			p = sc.nextInt();
			a = sc.nextInt();
			if(p == 0 && a  == 0 ) break;
			BigInteger p1,a1;
			p1 = BigInteger.valueOf(p);
			a1 = BigInteger.valueOf(a);
			if(!p1.isProbablePrime(10) && a1.modPow(p1, p1).equals(a1))
				sb.append("yes");
			else sb.append("no");
			sb.append("\n");
		}
		System.out.print(sb);
	}
}