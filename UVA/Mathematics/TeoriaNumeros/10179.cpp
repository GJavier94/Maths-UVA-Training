#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

vi primes;
bitset<10000010> bs;
ll sieve_size;

void sieve(ll upperbound){
	sieve_size = upperbound + 1;
	bs.set(); bs[0] = bs[1] = 0;
	for(ll i = 2; i <= sieve_size; i++)if(bs[i]){
		for(ll j = i*i; j <= sieve_size; j += i ) bs[j] = 0;
		primes.push_back((int)i);
	}
}

ll EulerPhi( ll n){
	ll idx = 0, PF = primes[idx], ans = n;

	while(PF * PF <=  n){
		cout << ans << endl;
		if(n % PF  == 0 ) ans -= ans / PF; 
		while( n % PF == 0 ){ n /= PF; }
		PF = primes[++idx];
	}
	if( n != 1) ans -= ans / n;
	return ans;
}

int main(){
	sieve(1000000);
	ll n;
	while(scanf("%lld", &n) && n){
		printf("%lld\n", EulerPhi(n));	
	}
}