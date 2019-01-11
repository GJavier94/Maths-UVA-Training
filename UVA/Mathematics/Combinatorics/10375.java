import java.util.*;
import java.math.*;

class Main{

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int p,q,r,s; 
		BigInteger r1 = BigInteger.ONE, r2 = BigInteger.ONE;		
		while(sc.hasNext()){
			p = sc.nextInt();
			q = sc.nextInt();
			r = sc.nextInt();
			s = sc.nextInt();
			for(int i = 0; i < q; i++){ r1 = r1.multiply(BigInteger.valueOf( p  - i)); r1 = r1.divide(BigInteger.valueOf(i + 1));}
			for(int i = 0; i < s; i++){ r2 = r2.multiply(BigInteger.valueOf( r  - i)); r2 = r2.divide(BigInteger.valueOf(i + 1));}
			BigDecimal b1, b2, res;
			b1 = new BigDecimal(r1);
			b2 = new BigDecimal(r2);			
			//res = b1.divide(b2);					
			System.out.println( b1 );
			System.out.println( b2 );
			//System.out.println( res );
		}
	}
}
