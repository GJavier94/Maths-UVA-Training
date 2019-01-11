/*
	No olvidar equals = es solo para saber si son defirentes
				compareTo = es para saber su relación.
	Aprendizaje
	 cuando no conozco el tamaño uso Vector o ArrayList
	 	*add agrega elementos
	 	*get(i) recupera el elemento
	 	*Iterar hasta cierto numero
		 	int i = 1;
			do{ i++;
				f.add(f.get(i-1).add(f.get(i-2)));			
			}while(f.get(i).compareTo(tam) != 1);
		*compareTo -1 0 1 < = >

*/
import java.util.*;
import java.math.*;
class Main{
	static Vector<BigInteger> f = new Vector<BigInteger>();
	static void precalc(){
		BigInteger tam = (new BigInteger("10")).pow(100);
		f.add(BigInteger.ONE);
		f.add(new BigInteger("2"));
		int i = 1;
		do{ i++;
			f.add(f.get(i-1).add(f.get(i-2)));			
		}while(f.get(i).compareTo(tam) != 1);
	}
	public static void main(String[] args) {
		precalc();
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		BigInteger a, b;
		while(true){
			a = new BigInteger(sc.next());
			b = new BigInteger(sc.next());
			if(a.equals(new BigInteger("0")) && b.equals(new BigInteger("0"))) break;
			int i = 0; // posicionamiento
			// si es -1 quiere decir que f[i] < a  y es lo que queremeos cuando f[i] >=  es cuando se detien pues el intervalo es [a, b]
			while(f.get(i).compareTo(a) == -1 )i++;
			int cont = 0;
			while(f.get(i).compareTo(b) != 1 ){i++;cont++}
			sb.append(cont + "\n");
		}
		System.out.print(sb);
	}
}