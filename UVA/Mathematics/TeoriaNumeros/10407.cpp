/*
GCD  de las diferencias
porque si se tiene un diferencia entre n1 y n2 
quiere decir que se sumo  un n2 = n1 + d  
al aplicarles el mismo modul d se obtiene el mismo 
si se tiene otra diferencia con un n3 se podria considerar un gcd 
para saber que tdoso los n2 n3... nn son multiplos del gcd de todos 


*/
#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){return b == 0 ? a : gcd(b, a % b );}
int main(){
	int n1,n2;
	while(cin >> n1 && n1  ){
		int G = 0;
		while(cin >> n2  && n2 ){
			int dif = n1 - n2;			
			G = gcd(G, dif);			
		}
		G = abs(G);
		printf("%d\n", G);
	}
}