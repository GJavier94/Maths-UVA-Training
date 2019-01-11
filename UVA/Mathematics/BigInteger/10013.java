/*
Usar biginteger de esta manera me da tle
Opto por hacerlo en c++ con arrays

*/


import java.util.*;
import java.math.*;

class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();
		boolean flag = true;
		while(cases-- > 0 ){
			if(flag)flag = false;
			else System.out.println();
			String n1 = "", n2 = "";
			int m = sc.nextInt();
			int d1,d2;
			for(int i = 0; i < m; i++){
				d1 = sc.nextInt(); n1 += d1;
				d2 = sc.nextInt(); n2 += d2;
			}
			BigInteger b1,b2;
			b1 = new BigInteger(n1);
			b2 = new BigInteger(n2);
		
			System.out.println(b1.add(b2));
		}
	}
}