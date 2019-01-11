import java.util.*;
import java.math.*;

class Main{
	static int SIZE = 301;
	static BigInteger fac[] = new BigInteger[SIZE];
	static BigInteger cat[] = new BigInteger[SIZE];
	static void precalcFac(){
		fac[0] = BigInteger.ONE;
		fac[1] = BigInteger.ONE;
		for(int i = 2; i < SIZE; i++) fac[i] = fac[i-1].multiply(BigInteger.valueOf(i));
	}
	static void precalcCat(){
		cat[0] = BigInteger.ONE;
		for(int i = 1; i < SIZE ; i++ ){
			cat[i] = cat[i - 1].multiply( BigInteger.valueOf(4*i - 2));
			cat[i] = cat[i].divide(BigInteger.valueOf(i + 1));
		}
	}
	public static void main(String[] args) {
		precalcFac();
		precalcCat();
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		while(true){
			int n = sc.nextInt();
			if( n == 0 ) break;
			sb.append(fac[n].multiply(cat[n]) + "\n");
		}
		System.out.print(sb);
	}
}