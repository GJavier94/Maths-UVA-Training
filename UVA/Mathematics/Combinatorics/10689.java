/*
	Ataque mal el problema 
	Solucion -> Pisano period

	encontré la formula
	1.- obtengo lo primeros 15,000 de fib, por que ?  porquesolocita a lo mas 4 digitos y cada 15,000 se reptine los ultimo 4 digitos
	2.- se cambian constantes a y b la formula es fo = a*f(n-1) + b*(n-1)
	3.- recibo los a,b, n, m
	4. m = ultimos digitos asociado a pisano period 
	5.- 


*/


// import java.util.*;
// import java.io.*;
// import java.math.*;

// class Main{
// 	static int SIZE = 15001;
// 	static Vector<BigInteger> f = new Vector<BigInteger>(SIZE);
// 	static void precalc(){
// 		f.add(new BigInteger("0"));f.add(new BigInteger("1"));		
// 		for(int i = 2; i < SIZE; i++) f.add( f.get(i - 1).add( f.get(i - 2) ) );
// 	}
// 	public static void main(String[] args) {
// 		precalc();	
// 		Scanner sc = new Scanner(System.in);
// 		StringBuilder sb = new StringBuilder();		
// 		BigInteger a,b, fn;
// 		int m,n, cases = sc.nextInt();
// 		int pisano[] = {0, 60, 300, 1500, 15000};
// 		while(cases-- >  0){
// 			a = new BigInteger(sc.next());
// 			b = new BigInteger(sc.next());
// 			n = sc.nextInt();
// 			m = sc.nextInt();
// 			n = n % pisano[m];
// 			if(n == 0 ) fn = a;
// 			else if(n == 1 ) fn = b;
// 			else fn = a.multiply(f.get(n - 1)).add( b.multiply(f.get(n)));
// 			String res = fn.toString();
// 			if(  res.length()  >= m ) res = res.substring(  res.length() - m );
// 			int res1 = Integer.parseInt(res);
// 			sb.append(res1 + "\n");
// 		}
// 		System.out.print(sb);
// 	}
// } 



/*
	Segunda solucion utilizando arreglo
*/

import java.util.*;
import java.math.*;

class Main{
	static int SIZE = 15001;
	static BigInteger[] f = new BigInteger[SIZE];
	static void precalc(){
		f[0] = new BigInteger("0");
		f[1] = new BigInteger("1");
		for(int i = 2; i < SIZE; i++) f[i] = f[i-1].add(f[i-2]);
	}
	public static void main(String[] args) {
		precalc();
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		BigInteger a,b,fn;
		int n,m, cases = sc.nextInt();
		int pisano[] = {0,60,300,1500,15000};
		while(cases -- > 0 ){
			a = new BigInteger(sc.next());
			b = new BigInteger(sc.next());
			n = sc.nextInt();
			m = sc.nextInt();
			n = n % pisano[m];
			if(n == 0 ) fn = a;
			else if(n == 1 ) fn = b;
			else fn = a.multiply(f[n-1]).add(b.multiply(f[n]));
			String res = fn.toString();
			if(res.length() >= m) res = res.substring( res.length() - m);
			int res1 = Integer.parseInt(res);
			sb.append(res1 + "\n");
		}
		System.out.print(sb);
	}
}





