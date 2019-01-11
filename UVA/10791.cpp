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

ll solve(ll n ){	
	ll pot, sum = 0, numberP = 0;
	for(int i = 0; i < primes.size(); i++){
		ll PF = primes[i]; pot = 0;
		while(n % PF == 0 ){ n /= PF; pot++; }
		if(pot){
			numberP++;			
			sum += pow(PF, pot);
		}		
		if( n == 1 ) break;
	}	
	if(numberP == 1) return sum + 1 ;
	else return sum;
}
int main(){
	sieve(1000000);
	ll n;
	while(scanf("%lld",&n) && n ){
		printf("%lld\n",  solve(n) );
	}
}