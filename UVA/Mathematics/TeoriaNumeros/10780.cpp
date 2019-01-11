#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

ll sieve_size;
vi primes;
bitset<10000010> bs;
const int  MAX = 1 << 30;

void sieve(ll upperbound ){
	sieve_size =  upperbound + 1;
	bs.set(); bs[0] = bs[1] = 0;
	for(ll i = 2; i <= sieve_size; i++)if(bs[i]){
		for(ll j = i*i; j <= sieve_size; j += i ) bs[j] = 0;
		primes.push_back((int)i);
	}
}

ll get_powers(ll n, ll p){
    ll res = 0;    
    for (ll power = p ; power <= n ; power *= p) res += n/power;
    return res;
}

ll  solve(ll m, ll n ){
	ll pot, potN, p = MAX ;
	for(int i = 0; i < primes.size(); i++){
		ll PF = primes[i]; pot = 0;		
		while(m % PF == 0 ){ m /= PF; pot++;}
		if(pot){
			potN = get_powers(n, PF);
			if(potN < pot ) return 0;
			else{				
				p = min( p, potN/pot );
			}
		}
		if(m == 1 )  break;
	}
	if(m != 1){ return get_powers(n,m);} //El numero es primo
	return p;

}

int main(){
	sieve(1000000);
	int cases;
	scanf("%d",&cases);
	ll m,n;	
	for(int k = 1; k <= cases; k++){
		scanf("%lld %lld", &m, &n);
		printf("Case %d:\n", k);
		ll sol;
		if(sol = solve(m,n)){
			printf("%lld\n", sol );
		}else{
			printf("Impossible to divide\n");
		}
	}
}