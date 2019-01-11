#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

ll sieve_size;
vi primes;
bitset<10000010> bs;

void sieve(ll upperbound){
	sieve_size = upperbound +1 ;
	bs.set(); bs[0] = bs[1] = 0;
	for(ll i = 2; i <= sieve_size; i++)if(bs[i]){
		for(ll j = i*i; j <= sieve_size; j += i) bs[j] = 0;
		primes.push_back((int)i);
	}
}
// obtienes la potencia k de un primo en un numero n 
// power* , powerpower , powerpowerpower ...
// es sumatoria de dividir n enre p^k con k = n hasta log base p de n;
int get_powers(int n, int p){
    int res = 0;    
    for (int power = p ; power <= n ; power *= p) res += n/power;
    return res;
}
bool solve(ll m, ll n){
	ll idx = 0, PF = primes[idx];
	while(PF * PF <= n){
		int pot = 0;
		while(n % PF == 0 ){ n /= PF; pot++;}
		if(pot){			
			if(get_powers(m, PF) < pot) return false;
		}
		PF = primes[++idx];
	}
	if(n != 1){ if( m < n ) return false; }
	return true;
}
int main(){
	ll m,n;
	sieve(1000000);

	while(scanf("%lld %lld", &m, &n) == 2){		
		if (solve(m,n)) printf("%lld divides %lld!\n",n,m );
		else printf("%lld does not divide %lld!\n",n,m );
	}
}