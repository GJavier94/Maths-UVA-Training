/*
AC
 uso de modPow para x^y mod n -> x.modPow(y,n).toString()
*/

import java.util.*;
import java.math.*;

class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		int cases = sc.nextInt();
		BigInteger x,y,n;
		while(cases-- > 0 ){
			x = new BigInteger(sc.next());
			y = new BigInteger(sc.next());
			n = new BigInteger(sc.next());
			sb.append(x.modPow(y,n).toString()+ "\n");
		}
		sc.next();
		System.out.print(sb);
	}
}