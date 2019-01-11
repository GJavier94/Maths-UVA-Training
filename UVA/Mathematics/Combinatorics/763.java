/*
	 SE me complico mucho 
	 Proeblema: Dado una cadena binaria sus elemtnos son fibonacis  sumar dos de estos y dar la suma en fibonacci
	 Solucion
	 1.-Generar los primeros 100 fib pues a lo mas la caneda tiene 100 digitos
	 2.-se va revisando la cadena y se hace la suma eso es el valor
	 	1. se hace para n1 y para n2
	 3. se hace la suma biginteger de ambos numeros
	 4.-se pasa de nuevo a binario ( esto fue lo que se me complico)
	 	algoritmo gredy se revisan todos los fi tales que sean menores que m se agarra al mas grande menor
		se actualiza n como n = n- fi;
		se repite el proceso
		Pasar esto a cadena binaria	 
			1. checo el indice del fibnoacci que forma parte de la solucion el primero me da el tamño
			2.- hago un array de puros '0'
			3.- cada que encuentre un lemento que sea solucion lo marco en el array como 1
			lo paso a string pero como lo pide alrreves por eso hago r[ r.length - j ] eso invierte los indices

*/


import java.util.*;
import java.math.*;

class Main{
	static BigInteger f[] = new BigInteger[105];
	static void precalc(){
		f[0] = BigInteger.ONE;f[1] = new BigInteger("2");
		for(int i = 2; i < 102; i++) f[i] = f[i-1].add(f[i-2]);
	}
	static BigInteger convierte(String n){
		BigInteger res = BigInteger.ZERO;
		n = new StringBuffer(n).reverse().toString();
		for(int i = 0; i < n.length(); i++)if(n.charAt(i) == '1'){
			res = res.add(f[i]);
		}
		return res;
	}
	static String fibnary(BigInteger n){		
		String res = "";	
		int j = 0, size = 0;
		boolean flag = true;
		char r[] = null;
		if(n.equals(BigInteger.ZERO)) return "0";
		while(!n.equals(BigInteger.ZERO)){
			int i = 0;j = i; while(f[i].compareTo(n) != 1 ){j = i; i++;}
			if(flag){flag = false; r = new char[j + 1]; for(int k = 0; k <= j; k++) r[k]  = '0';}
			r[r.length-1 - j] = '1';
			n = n.subtract(f[j]);
		}

		return new String(r) ;
	}

	public static void main(String[] args) {
		precalc();
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		BigInteger n1, n2, n3;
		boolean flag = true;
		while(sc.hasNext()){
			if(flag) flag = false;
			else sb.append("\n");
			n1 = convierte(sc.next());	
			n2 = convierte(sc.next());
			n3 = n1.add(n2);
			sb.append(fibnary(n3)+ "\n");
		}
		System.out.print(sb);	
	}	
}