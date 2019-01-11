#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

ll sieve_size;
vi primes;

bitset<10000010> bs;

#define MAX 1000000 
vi factors(MAX + 1);

void sieve(ll upperbound){
	sieve_size = upperbound + 1;
	bs.set(); bs[0] = bs[1] = 0;
	for(ll i = 2; i <= sieve_size; i++)if(bs[i]){
		for(ll j = i*i; j <= sieve_size; j+=i) bs[j] = 0;
		primes.push_back((int)i);
	}
}

void solve(){
	int sum = 0;
	for(int i = 2; i <= MAX; i++ ){
		
		int n = i, idx = 0, PF = primes[idx], ans = 0 ;
		while( PF * PF <= n){
			while(n % PF == 0 ){ n /= PF; ans++;}
			PF = primes[++idx];
		}
		if(n != 1) ans++;
		sum += ans;
		factors[i] = sum;		
	}
}

int main(){
	sieve(1000000);	
	solve();	
	int n;
	while(scanf("%d", &n) == 1){
		printf("%d\n", factors[n] );
	}
}