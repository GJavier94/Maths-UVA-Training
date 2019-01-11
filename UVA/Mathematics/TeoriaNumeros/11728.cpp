#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef map<ll, ll> ma;

vi primes;
bitset<10000010> bs;
ll sieve_size;

void sieve(ll upperbound){
	sieve_size = upperbound + 1;
	bs.set(); bs[0] = bs[1] = 0;
	for(ll i = 2; i <= sieve_size ; i++)if(bs[i]){
		for(ll j = i*i; j <= sieve_size ; j+= i )bs[j] = 0;
		primes.push_back((int)i);
	}
}

ll sumDiv( ll n){
	ll idx = 0, PF = primes[idx], ans = 1;
	while( PF * PF <= n){
		ll power = 0;
		while(n % PF == 0){ n /= PF; power++;}
		ans *= ((ll) pow((double) PF, power + 1.0) - 1)/ (PF - 1);
		PF = primes[++idx];
	}
	if(n != 1 ) ans *= ((ll)pow((double)n, 2.0) -1 ) / (n - 1);
	return ans;
}

int main(){
	sieve(1000000);
	ma mapa;
	for(ll i = 1; i <= 1000; i++){
		mapa[sumDiv(i)] =  i;
	}

	int k = 0; 
	ll n;
	ma :: iterator it;
	while(scanf("%lld",&n) && n ){
		printf("Case %d: ", ++k);
		if( (it = mapa.find(n) ) != mapa.end() ) printf("%lld\n", it->second );
		else printf("-1\n");
	}
}