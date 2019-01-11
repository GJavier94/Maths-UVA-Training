#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll sieve_size;
vi primes;
bitset<10000010> bs;

void sieve(ll upperbound){
	sieve_size = upperbound + 1;
	bs.set(); bs[0] = bs[1] = 0;
	for(ll i = 2; i <= sieve_size; i++)if(bs[i]){
		for(ll j = i*i; j <= sieve_size; j += i ) bs[j] = 0;
		primes.push_back((int)i);
	}	
}

ll solve(ll a, ll n){
	if(n % a  != 0 ) return 0;
	ll PF, PFi, b = 1 ;
	int pot;
	for(int i = 0; i < primes.size(); i++){
		PF = primes[i]; pot = 0;		
		while(n % PF == 0 ){ n /= PF; pot++;}
		if(pot){
			PFi = pow(PF, pot);
			if(a % PFi != 0) b *= PFi;
		}
		if( n == 1) break;
	}
	return b;
}
int main(){
	sieve(1000000);
	ll a,b,c;
	int cases;
	scanf("%d",&cases);
	while(cases--){
		scanf("%lld %lld", &a, &c);
		ll sol;
		if(sol = solve(a,c))
			printf("%lld\n",sol);
		else
			printf("NO SOLUTION\n");
	}
}