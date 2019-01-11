/*
Nuevamente varios Wa's =(

1.  Errores en la logica se recibe con la base que bien luego se pasa a la otra base !!!!!
	String n1 = sc.next(); Integer num = Integer.parseInt(n1, 10); String res = num.toString(num, 16).toUpperCase()
	sb.append(res);

2.	Error de caracter de termino, crei que era con -1  pero en realidad se termina con un numero negativo!!!!!!
	Leer bien !!! 


*DEtalleeeee la clase Integer lee hexadecimales SIN 0x hay que uqitalor

*/


import java.util.*;
import java.math.*;

class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		String n1;
		while(true){
			n1 = sc.next();
			if(n1.charAt(0) == '-') break;
			boolean flag = true; // flag hex
			if(n1.length() < 3 ) flag = false;
			else if( n1.charAt(0) == '0' && n1.charAt(1) == 'x' ) flag = true;
			else flag = false;
			Integer num; String res;
			if(flag){
				num = Integer.parseInt(n1.substring(2), 16);
				res = num.toString(num, 10 );
				sb.append(res+"\n");
			} 
			else{
				num = Integer.parseInt(n1, 10);
				res = num.toString(num, 16);
				sb.append("0x"+ res.toUpperCase()	 +"\n");
			} 			
		}
		System.out.print(sb);
	}
}