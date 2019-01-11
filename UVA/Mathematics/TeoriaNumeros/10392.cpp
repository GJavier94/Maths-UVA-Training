// #include <bits/stdc++.h>

// using namespace std;

// typedef long long ll;
// typedef vector<int> vi;
// typedef vector<ll> vll;

// bitset<10000010> bs;
// vi primes;
// ll sieve_size;

// void sieve(ll upperbound ){	
// 	sieve_size = upperbound + 1;
// 	bs.set(); bs[0] = bs[1] = 0;
// 	for(ll i = 2; i <= sieve_size; i++)if(bs[i]){
// 		for(ll j = i*i; j <= sieve_size; j+= i) bs[j] = 0;
// 		primes.push_back((int)i);
// 	}
// }

// vll primeFactors(ll N){
// 	vll factors;
// 	ll idx = 0, PF = primes[idx];
// 	for( int i = 0; i < primes.size(); i++){
// 		PF = primes[i];
// 		while(N % PF == 0 ){ N /= PF; factors.push_back(PF); }		
// 		if(N == 1 ) break;
// 	}
// 	if(N != 1) factors.push_back(N); // si n es primo es este caso 
// 	return factors;	
// }

// int main(){
// 	sieve(1000000);
// 	ll n; 
// 	while(scanf("%lld", &n) && n != -1){	
// 		vll r = primeFactors(n);
// 		for(int i = 0;i < r.size(); i++)
// 			printf("    %lld\n", r[i] );
// 		printf("\n");
// 	}
// }

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

vi primes;
ll sieve_size;
bitset<10000010> bs;

void sieve(ll upperbound){
	sieve_size = upperbound + 1;
	bs.set(); bs[0] = bs[1] = 0;

	for(ll i = 2; i <= sieve_size ; i++) if(bs[i]){
		for(ll j = i*i; j <= sieve_size; j+=i) bs[j] = 0;
		primes.push_back((int)i);
	}
}

vll primeFactors(ll N){
	vll factors;
	ll PF ;
	for( int i = 0; i < primes.size(); i++){
		PF = primes[i];
		while(N % PF == 0 ){N /= PF; factors.push_back(PF);}
		if(N == 1 ) break;
	}
	if( N != 1) factors.push_back(N);
	return factors;
}

int main(){
	ll n;
	sieve(1000000);
	while(scanf("%lld", & n) &&  n != -1){
		vll r = primeFactors(n);
		for(int i = 0; i < r.size(); i++)
			printf("    %lld\n", r[i]);
		printf("\n");
	}
}