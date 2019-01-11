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
	 for( ll i = 2; i <= _sieve_size; i++) if( bs[i]){
	 	for(ll j  = i*i; j <= _sieve_size; j += i) bs[j] = 0;
	 	primes.push_back((int)i);
	 }
}
bool isPrimes(ll N){
	if( N <= _sieve_size ) return bs[N];
	for( int i = 0 ; i < (int)primes.size(); i++)
		if(N % primes[i] == 0 ) return false;
	return true;
}

int main(){
	sieve(1000000);
	int n; 
	while(cin >> n  && n ){
		int  aini = 0,bini = 0,a,b;
		int distance = -1; 		
		for(int i = 0; primes[i] <= n/2  ; i++){
			a =  primes[i];b = n - a;
			if(isPrimes(b)){
				if( distance < abs(a - b) ){				
					distance = abs(a - b);
					aini = a, bini = b;
				}
			}
		}		
		printf("%d = %d + %d\n",n, aini,bini);		
	}
}