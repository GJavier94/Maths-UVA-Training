#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

ll _sieve_size;
bitset<10000010> bs;
vi primes;

void sieve(ll upperbound){
	_sieve_size = upperbound +1;
	bs.set(); bs[0] = bs[1] = 0;
	for(ll i = 2 ; i <= _sieve_size; i++)if(bs[i]){
		for(ll j = i*i; j <= _sieve_size; j+=i) bs[j] = 0;
		primes.push_back((int)i);
	}
}
vi primesFactors(ll N){
	vi factors;
	ll idx = 0, PF = primes[idx];

	while( PF * PF <= N){
		while(N % PF == 0 ){N /= PF; factors.push_back(PF);}
		PF = primes[++idx];
	}
	if(N != 1) factors.push_back(N);
	return factors;
}
int main(){
	sieve(100000);
	int n;
	while( cin >> n && n){		
		bool flag = false;
		if( n < 0) flag = true ,n = abs(n);
		vi r = primesFactors(n);
		if(flag) printf("-");		
		printf("%d = ",n);
		int i = 0;
		if(flag)printf("-1");
		else printf("%d",r[0]),i++;				
		for(;i < r.size();i++)
			printf(" x %d",r[i] );	
		printf("\n");
	}
}



