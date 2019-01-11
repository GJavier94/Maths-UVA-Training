/*
Problema dada una cadena de max 255 caracteres encontrar el primo mas grande
****los primos pueden ir de 2 a 100,000
WA
	1.- toma substrings de longitud arbitraria obviamente me da primos enormes
	2.- tomaba substring de hasta longitd 6 
		maaaal solo el 100,000 es de longitud 6 y ni siquiera es primo
AC
	1.-Tomar substrings de hasta longitud 6 y checar que fueran menores o iguales que 100,000
	si eran mayores que 100, no los tomaba en cuenta 
		if(maxPrime < b1.intValue() && b1.intValue() <= 100000 ) maxPrime = b1.intValue();
	2.-
Metodos aprendidos  convertir El BigInteger a int
b1.intValue() =D!!

*/
import java.util.*;
import java.math.*;
class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		String n;
		while(true){
			n = sc.next();
			if(n.equals("0")) break;
			int maxPrime = 0;
			for(int i = 0; i < n.length(); i++){
				for(int j = i; j < i + 5 && j < n.length(); j++ ){ // como jalo desde 0 hasta un n - 1 si quiero 5  tengo que jala desde cero hasta 4 osea hasta j < 0 + 5  -> j = i hasta j < i + 5
					//&& j < n.length()-> por la posibilidad de desborde
					String sub = n.substring(i, j + 1); // pinche funcion es [ )  osea inclusiva exclusiva por  eso del + 1..
					BigInteger b1 = new BigInteger(sub);
					if(b1.isProbablePrime(10)){
						if(maxPrime < b1.intValue()) maxPrime = b1.intValue();
					}
				}
			}
			sb.append(maxPrime + "\n");
		}
		System.out.print(sb);
	}
}