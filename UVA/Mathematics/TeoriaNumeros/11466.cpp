/*
ll 2^64 = 1.8 X 10^19 > 10^19
int 2^32 = 10^9

El codigo de la criba con va hasta 10^7

El codigo de factores primos
tiene la condicion de 
PF * PF <= N
10^7 * 10^7 <= N
10^14 = N
por eso se usa el maximo del a criba para esta ocacion
pues problema
va 
10^13.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int > vi;
typedef vector<ll> vll;

ll sieve_size;
bitset<10000010> bs;
vi primes;

void sieve(ll upperbound){
	sieve_size = upperbound + 1;
	bs.set(); bs[0] = bs[1] = 0;

	for( ll i = 2; i <= sieve_size; i++)if(bs[i]){
		for(ll j = i*i; j <= sieve_size; j+= i) bs[j] = 0;
		primes.push_back((int)i);
	}
}

vll primesFactors(ll N){
	vll factors;
	ll idx = 0, PF = primes[idx];
	while(PF * PF <= N){
		int i = 1;		
		while(N % PF == 0){N /= PF; if(i) factors.push_back(PF),i--;}
		PF = primes[++idx];
	}

	if(N != 1) factors.push_back(N);
	return factors;
}


int main(){
	sieve(10000000);
	ll n;
	while( cin >> n && n ){
		n = abs(n);
		if(n == 1){printf("-1\n");continue;}
		vll r = primesFactors(n);

		if( r.size() == 1 ){
			printf("-1\n");
		}else{
			ll maxi = *max_element(r.begin(), r.end());
			printf("%lld\n",maxi );			
		}
	}

}
	