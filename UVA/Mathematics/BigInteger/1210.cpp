/*
PRoblema pide en cuantas formas puedes expresea un numero n 
como suma de primos consecutivos.
Se debe hacer un recorrido

**** Si el numero es primo puede decirse que se expresa que ese numero se expresa com su misma suma jaja 
tamaño 1

wa's
1.- olvide el detallde  arriba 
	obtuve primos del 2 al 5000 y luego algoortimo revisaba las posibles sumas de ells
	alterando un vector de 1 a 10000 ++
	Error: hay primos entre el 5000 y el 10000 y se debe considerar como una posbile suma 
	Solucion incremente los rangos hasta 10 asi el algoritmo tambien los revisaba 
  	=)	

*/


#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vi primes;
bitset<10010> bs;
int sieve_size;

#define SIZE 10000
vi nums(SIZE + 1);

void sieve(int upperbound){
	sieve_size = upperbound + 1;
	bs.set(); bs[0] = bs[1] = 0;	
	for(int i = 2; i <= sieve_size; i++)if(bs[i]){
		for(int j = i*i; j <= sieve_size; j += i) bs[j] = 0;
		primes.push_back(i);
	}
}
void precalc(){
	for(int i = 0; i < primes.size(); i++){
		int sum = 0;
		for(int j = i ; j < primes.size(); j++){
			sum += primes[j];
			if(sum <= SIZE) nums[ sum ]++;
		}
	}
}

int main(){
	sieve(10000);	
	precalc();
	int n;	
	while(cin >> n  && n ){
		cout << nums[n] <<"\n";
	}
}	

