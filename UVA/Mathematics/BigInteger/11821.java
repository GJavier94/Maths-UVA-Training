/*
	BigDecimal ahondar mas a fondo despues 

	2 metodo revisados
	stripTraillinZeros() remueve los ceros de la derecha
	pero puede dejarlo en notacion exponencial

	toPlainString() pasa cualquier numero con exponent a plano con decimales

*/
import java.util.*;
import java.math.*;

class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		int cases = sc.nextInt();
		while(cases-- > 0 ){
			BigDecimal sum,b1;
			sum = BigDecimal.ZERO;
			while(true){
				String n = sc.next();
				if(n.equals("0")) break;
				b1 = new BigDecimal(n);
				sum = sum.add(b1);				
			}
			sum = sum.s		
			sb.append(sum.toPlainString() + "\n");
		}
		System.out.print(sb);
	}
}