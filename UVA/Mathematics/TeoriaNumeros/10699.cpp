/*
Codigo de la criba modificada 
se obtiene los diferentes  prims de un numero
haciendo uso de la criba se recorren los multiplos
y se incrementa el valor de los elementos de 
numDiffPF[i] 
*/
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1000001
int numDiffPF[MAX_N];

void sieve(){
	memset(numDiffPF,0 , sizeof(numDiffPF));
	for(int i = 2; i < MAX_N; i++)
		if(numDiffPF[i] == 0 ) // i is a prime number
			for(int j = i ; j < MAX_N; j += i)
				numDiffPF[j]++; // increase the value of multiples of i			
	numDiffPF[1] = 1;
}
int main(){
	sieve();	
	int n; 
	while(cin >> n  && n ){
	 	printf("%d : %d\n", n , numDiffPF[n] );
	}
}