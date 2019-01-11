/*
Varios wa's =( 

1.-  Estaba retornando una variable e la funcio que no eeraaaa!!


2.- utilice Integer no revise el maximo tamaño 
	puede recibir bases [2,,...16] acaracter hasa la z maximo 10 carac ---->         z*16^9....16^0
	donde z = 36  forzosamente tiene que ser BigInteger

3.- Error de formato tiene que se en mayuscculass!!!!!!!


*/


import java.util.*;
import java.math.*;

class Main{
	static int minBase(String n1){
		char maxChar = 0; int base;
		for(int i = 0; i < n1.length(); i++)if(maxChar < n1.charAt(i)) maxChar = n1.charAt(i);		
		if(Character.isDigit(maxChar)) base = (int)maxChar - '0';
		else base = (int)maxChar - 'A' + 10;
		return ++base;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		String n1,n2;
		int ba1, ba2;
		while(sc.hasNext()){
			ba1 = sc.nextInt();
			ba2 = sc.nextInt();
			n1 = sc.next();
			int m1 = minBase(n1);			
			if(ba1 < m1 ){ sb.append(n1 + " is an illegal base "+ ba1 + " number\n"); continue; }
			BigInteger num  = new BigInteger(n1, ba1);
			String res = num.toString(ba2).toUpperCase();
			sb.append( n1 + " base "+ ba1 + " = " + res + " base " + ba2 +"\n");			
		}	
		System.out.print(sb);
	}
}