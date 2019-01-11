#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

bitset<10000010> bs;
ll _sieve_size;
vi primes;

void sieve(ll upperbound){
	_sieve_size = upperbound + 1;
	 bs.set();
	 bs[0] = bs[1] = 0;
	 primes.push_back(1);
	 for( ll i = 2; i <= _sieve_size; i++) if( bs[i]){
	 	for(ll j  = i*i; j <= _sieve_size; j += i) bs[j] = 0;
	 	primes.push_back((int)i);
	 }
	 bs[1] = 1;
}
bool isPrimes(ll N){
	if( N <= _sieve_size ) return bs[N];
	for( int i = 0 ; i < (int)primes.size(); i++)
		if(N % primes[i] == 0 ) return false;
	return true;
}

int main(){
	sieve(10000);
	int n, c;
	bool flag = true;
	while(cin >> n >> c){
		// if(flag) flag = false;
		// else cout << endl<< endl;
		printf("%d %d:",n , c );
		int size = 0;
		while( primes[size] <= n)size++;
		if( 2*size <= c ){			
			for( int i = 0 ; i < size; i++){
				printf(" %d", primes[i]);	
			}
			printf("\n");
			printf("\n");
			continue;	
		}


		int tam, inicio;		
		if(size&1) inicio = size/2 - c + 1,  tam = 2*c - 1;
		else inicio = size/2 - c,  tam  = 2*c ;
		for(int i = inicio, j = 0; j < tam; i++,j++){
			printf(" %d", primes[i]);
		}
		printf("\n");
		printf("\n");
	}
}