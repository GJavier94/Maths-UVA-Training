/*
Varios WA's
El problema eleva un numero al cuadro 
Se usa biginteger par alograr elevarlo se obtiene la cadena 
Se comparan cadenas n1 y n2(n1^2)
se revisa que la n1 este contenida en n2 y hasta que diigito 

*** Problemas porque podian haber inputs asi 0000011
*/


import java.util.*;
import java.math.*;

class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String n1, n2;
		while(sc.hasNext()){
			n1 = sc.nextLine();
			
			BigInteger b1 = new BigInteger(n1);
			n2 = b1.pow(2).toString();

			int cont = 0, i = n1.length() -1 , j = n2.length() - 1;
			while(n1.charAt(i) ==  n2.charAt(j)){
				cont++; i--;j--;
				if(i < 0 || j < 0 ) break;
			}			
			if(i < 0 )
				System.out.println("Automorphic number of "+ cont + "-digit.");
			else 
				System.out.println("Not an Automorphic number.");
		}		
	}
}