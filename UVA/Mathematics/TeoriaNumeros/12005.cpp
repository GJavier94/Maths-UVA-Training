#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vll;

vi primes;
bitset<30000000> bs;
ll sieve_size;

void sieve(ll upperbound){
	sieve_size = upperbound + 1;
	bs.set(); bs[0] = bs[1] = 0;
	for(ll i = 2; i <= sieve_size ; i++)if(bs[i]){
		for(ll j = i*i; j <= sieve_size; j += i ) bs[j] = 0;
		primes.push_back((int)i);
	}
}
ll numDiv(ll n ){	
	ll idx = 0, PF = primes[idx], ans = 1;	
	while( PF * PF <= n){
		ll power = 0;
		while(n % PF == 0 ){n /= PF; power++;}
		ans *= (power + 1);
		PF = primes[++idx];
	}
	if(n != 1 ) ans *= 2;
	return ans;
}

int main(){
	sieve(30000000);
	ll n;
	while(cin >> n && n ){
		ll result = 4*n - 3;
		printf("%lld %lld\n",n , numDiv(result) );
	}
}