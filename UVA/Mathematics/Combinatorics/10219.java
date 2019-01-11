
// 1era solucion usando recursividad--- muy lento para la reconstruccion del arbol

// import java.util.*;
// import java.math.*;

// class Main{
// 	static BigInteger n,k;
// 	static BigInteger binomial(BigInteger n, BigInteger k){
// 		if(k.equals(BigInteger.ZERO) || k.equals(n)) return BigInteger.ONE;
// 		else{
// 			if(k.compareTo(BigInteger.ZERO) == 1 && n.compareTo(k) == 1 )
// 				return binomial(n.subtract(BigInteger.ONE), k.subtract(BigInteger.ONE)).add(binomial(n.subtract(BigInteger.ONE), k) ) ;
// 		}
// 		return BigInteger.ZERO;		
// 	}
// 	public static void main(String[] args) {
// 		Scanner sc = new Scanner(System.in);
// 		BigInteger n,k;
// 		while(sc.hasNext()){
// 			n = new BigInteger(sc.next());
// 			k = new BigInteger(sc.next());
// 			System.out.println( binomial(n,k).toString());

// 		}
// 	}
// }

// 2da solucion usando  tecnica java BigInteger

/*
Solucion da TLE =(
*/
// import java.util.*;
// import java.math.*;

// class Main{
// 	public static BigInteger getFactorial(int n){
// 		BigInteger fac = BigInteger.ONE;
// 		if(n == 0) return fac;
// 		for(int i = 2; i <= n; i++) fac = fac.multiply(BigInteger.valueOf(i));
// 		return fac;
// 	}	
// 	//we are assuming that n and k both are integers
// 	public static BigInteger c_nk(int n, int k){ 
// 		if(n > k ) k = n - k;// because c_nk = c_n(n-k)
// 		return getFactorial(n).divide( getFactorial(n-k).multiply(getFactorial(k)) );
// 	}

// 	public static void main(String[] args) {
// 		Scanner sc = new Scanner(System.in);
// 		StringBuilder sb = new StringBuilder();
// 		int n,k;
// 		while(sc.hasNext()){
// 			n = sc.nextInt();
// 			k = sc.nextInt();
// 			sb.append(( c_nk(n,k).toString().length()) + "\n") ;
// 		}
// 		System.out.print(sb);
// 	}
// }

// 3er solucion ac 

/*
	hay una manera mas eficiente de obtener c_nk 
	surge de que c_nk = n!  / (n-k)!k! 
	= 1.2.3.....(n-k)(n-k + 1)....n / (1.2.3 ... n -k).k!
	= (n-k + 1)... n / k!
	= (n-k + 1 )... n / 1.2.3. k
	Este codigo hace eso 
	for(int i = 1; i <= k; i++)
			res = res.multiply(BigInteger.valueOf(n - i + 1)).divide( BigInteger.valueOf(i));

*/	

import java.util.*;
import java.math.*;
class Main{
	public static BigInteger c_nk(int n, int k){
		// surge de que c_nk = n! / (n-k)!*k! es igual c_nk = n.(n-1)(n-2)..(n - k + 1) / 1.2....k;
		BigInteger res = BigInteger.ONE;		
		for(int i = 1; i <= k; i++)
			res = res.multiply(BigInteger.valueOf(n - i + 1)).divide( BigInteger.valueOf(i));
		return res;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		int n,k;
		while(sc.hasNext()){
			n = sc.nextInt();
			k = sc.nextInt();
			//System.out.println(c_nk(n,k).toString());
			sb.append(c_nk(n,k).toString().length() + "\n");
		}
		System.out.print(sb);
	}
}





/*


*/