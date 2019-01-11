#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

vi primes;
bitset<10000010> bs;
ll sieve_size;

void sieve(ll upperbound ){
	sieve_size = upperbound + 1;
	bs.set(); bs[0] = bs[1] = 0;
	for(ll i = 2 ; i <= sieve_size ; i++)if(bs[i]){
		for(ll j = i*i; j <= sieve_size; j += i ) bs[j] = 0;
		primes.push_back((int)i);
	}
}

ll solve(ll n ){
	ll idx = 0, PF = primes[idx], ans = 1;
	while( PF * PF <= n){
		ll power = 0;
		while( n % PF == 0 ){ n /= PF; power++;}
		ans *= (power + 1);
		PF = primes[++idx];
	}
	if( n != 1) ans *= 2; // el ultimo divisor primo ( esta elevado a la i = 1 -> = i + 1 = 2) 
	return ans;
}

int main(){
	sieve(1000000);
	int cases; scanf("%d", &cases);
	ll l,u;
	while( cases--){
		scanf("%lld %lld", &l, &u);
		ll p = l, d = 0, numDiv;
		for(ll i = l;  i <= u; i++){
			numDiv = solve(i);
			if(numDiv > d ) d = numDiv, p = i;			
		}		
		printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n", l, u, p , d);
	}
}