/*
sieve modified me dice 
cuantos factores diferentes hay (solo eso )

utiilizo el vector numDiffj para ir multiplicando los factores
solo en el caso de que sea  square free numdiff[i] sera igual a i;
por eejmplo 3*2 = 6 como son facotres unicos al hacer las multiplicaciones
se alcanza el numero.

uso numPF  para identificar cuantods divisores diferentes hay
*/


#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1000001

int numDiff[MAX_N];
int numPF[MAX_N];
int MU[MAX_N];

void sieve(){
	memset(numDiff, 0, sizeof(numDiff));
	memset(numPF, 0, sizeof(numPF));
	memset(MU, 0, sizeof(MU));	
	for(int i = 2; i < MAX_N; i++)
		if(numPF[i] == 0)
			for(int j = i; j < MAX_N; j += i){
				numPF[j]++;
				if(!numDiff[j]) numDiff[j] = 1;
				numDiff[j] *= i;
			}
}

void solve(){	
	numDiff[1] = 1;
	MU[1] = 1;
	
	for(int i = 2; i < MAX_N ; i++){		
		if( numDiff[i] != i ) numDiff[i] = 0;
		else{ //is square free			
			if(numPF[i]&1) numDiff[i] = -1;
			else numDiff[i] = 1;
		}		
		MU[i] = MU[i - 1] + numDiff[i];
	}
}
int main(){
	sieve();
	solve();
	int n;
	while(cin >> n && n){
		printf("%8d%8d%8d\n",n , numDiff[n], MU[n]);
	}
}
