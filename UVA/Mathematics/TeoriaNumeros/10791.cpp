#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

bitset<10000010> bs;
vi primes;
ll sieve_size;

void sieve(ll upperbound ){
	sieve_size = upperbound +1 ;
	bs.set(); bs[0 ] = bs[1] = 0;
	for( ll i  = 2; i <= sieve_size; i++)if(bs[i]){
		for( ll j = i*i; j <= sieve_size; j += i ) bs[j] = 0;
		primes.push_back((int)i);
	}	
}

ll solve(ll N ){	
	ll n = N;
	ll pt, sum = 0, numberP = 0;
	ll idx = 0, PF = primes[idx];
	while( PF * PF <= n){
		pt = 1;
		while(n % PF == 0 ){ n /= PF; pt *= PF; }
		if(pt > 1){
			numberP++;			
			sum += pt;
		}		
		PF = primes[++idx];
	}	
	if( n != 1 ) sum += n;
	if( numberP == 1 && n == 1) return sum + 1;
	if( n == N) return N + 1;
	else return sum;			
}
int main(){
	sieve(1000000);
	ll n;
	int k = 1;
	while(scanf("%lld",&n) && n ){
		printf("Case %d: %lld\n",k++,  solve(n) );
	}
}