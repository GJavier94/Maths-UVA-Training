/*
	  en 2^32 -1  solo hay hasta el catalan de 19  por eso hay que usar  BigInteger -> java 
		
		problema: dado un numero de vertices decir cuantos arboles binarios se pueden generar cone sosvertices
		Solucion: dados n vertices se pueden generar cat(n) arboles binarios

	  Aprendizaje: 
	  Me pedia hasta el 1000-esimo catalan eso no caben en nigun tipo de dato primitov 
	  a  fuerza es BigInteger


*/

import java.util.*;
import java.math.*;

class Main{
	static int SIZE = 10001;
	static BigInteger cat[] = new BigInteger[SIZE];
	static void precalc(){
		cat[0] = BigInteger.ONE;
		for(int i = 1; i < SIZE; i++){
			cat[i] = cat[i -1 ].multiply( BigInteger.valueOf( 4*i - 2));
			cat[i] = cat[i].divide(BigInteger.valueOf(i + 1));
		}
	}
	public static void main(String[] args) {
		precalc();
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		int n;
		while(sc.hasNext()){
			n = sc.nextInt();
			System.out.println(cat[n]);
		}
	}
}
