import java.util.Scanner;
import java.math.BigInteger;
class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int k = 0, N, F;
		while(true){
			N = sc.nextInt(); F = sc.nextInt();
			if(N == 0 && F == 0) break;
			BigInteger sum =  BigInteger.ZERO;
			for(int i = 0; i < N; i++){
				BigInteger v = sc.nextBigInteger();
				sum = sum.add( v) ;
			}
				
			System.out.println("Bill #" + (++k) + " costs "+ sum +": each friend should pay "+
				sum.divide( BigInteger.valueOf(F)));
			System.out.println();			
		}
	}
} 