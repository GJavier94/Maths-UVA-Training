
// Nivel 2 pero me parecio complicado  tuve que usar el debugger para ver un caso aparte
// se reciben dos numeros pued que sea con letras 
// hay que variarlos en todas las bases hasta que coincidan 

// minbase busca el maximo de ellos para saber su minirepresentacion
// 	hay que castear el char a int y luego hacer resta d ascis
// 	2 casos si el max es digito o si es letra manejarlos aparte
// 	la A vale diez por eso eformulita
// 	si el max es n -> n + 1 es la minima base ejemplo max 1 entonces base 2
// se obtiene  minima base para representar cada numero ( si no sale exception)

// se varia sobre todas las bses se usa el constructor 
// b1 = new BigInteger(n1, i); numero  y radix
// se comparan con equals si son iguales se sale de ls ciclos con la bandera
// si bander nunca cambia entonces no es posible  manda error

// **** CASO ESPECIAL cuando alguno de los dos vale "0" la minima base seria 1 pero eso no es posible se retorna 2


/*
Metodos aprendidos

Character.isDigit(maxChar) -> te dice si es digito 

*/


import java.util.*;
import java.math.*;

class Main{
	static int minBase(String n1){
		char maxChar = 0 ;
		int base = 0;
		for(int i = 0; i < n1.length(); i++) if(maxChar < n1.charAt(i)) maxChar = n1.charAt(i);
		if(Character.isDigit(maxChar))
			base =  (int)(maxChar) - '0';		
		else
			base =  (int)(maxChar) - 'A' + 10;
		if(base < 2 ) return 2;		
		return ++base;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			String n1, n2;
			n1 = sc.next();
			n2 = sc.next();			
			int m1 = minBase(n1);
			int m2 = minBase(n2);					
			boolean flag = true;
			for(int i = m1; i <= 36  && flag; i++){
				for(int j = m2; j <= 36 && flag; j++){
					BigInteger b1, b2;
					b1 = new BigInteger(n1, i);
					b2 = new BigInteger(n2, j);
					if(b1.equals(b2)){
						flag  = false;
						System.out.println(n1 + " (base "+ i + ") = " + n2 + " (base "+ j + ")");						
					}
				}
			}
			if(flag)
				System.out.println(n1+ " is not equal to "+ n2+" in any base 2..36" );
		}
	}
