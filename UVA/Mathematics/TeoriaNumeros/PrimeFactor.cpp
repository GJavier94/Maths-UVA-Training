#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

typedef vector<ll> vll;
ll _sieve_size;
vi primes;
bitset<10000010> bs;


void sieve(ll upperbound ){
	_sieve_size  = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for(ll i = 2; i <= _sieve_size; i++)if(bs[i]){
		for(ll j = i*i; j <= _sieve_size; j+= i )bs[j] = 0;
		primes.push_back((int)i);
	}
}
bool isprime(ll N){
	if(N <= _sieve_size ) return bs[N];
	for( int i = 0; i < primes.size(); i++)
		if(N % i == 0 ) return false;
	return true;
}

vll primeFactors(ll N){
	vll factors;
	ll PF_idx = 0, PF = primes[PF_idx];

	while(PF * PF <= N){
		while(N % PF == 0 ){N /= PF; factors.push_back(PF);}
		PF = primes[++PF_idx];
	}

	//if N is prime 
	if(N != 1) factors.push_back(N);
	return factors;
}


int main(){
	sieve(1000000);
	ll n;cin >> n;
	vll r = primeFactors(n);
	// for(vll:: iterator i = r.begin(); i != r.end(); i++ )
	// 	printf("> %lld\n", *i);
	for(int i = 0 ; i < r.size(); i++)
		printf("> %lld\n",r[i] );


}