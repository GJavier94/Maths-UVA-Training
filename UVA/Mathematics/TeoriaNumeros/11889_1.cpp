#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

bitset<10000010> bs;
vi primes;
ll sieve_size;

void sieve(ll upperbound ){
	sieve_size = upperbound + 1;
	bs.set(); bs[0] = bs[1] = 0;
	for(ll i = 2; i <= sieve_size; i++)if(bs[i]){
		for(ll j = i*i; j <= sieve_size; j += i )bs[j] = 0;
		primes.push_back((int)i);
	}
}

void solve( ll n){	
	ll pot, idx = 0, PF = primes[idx];

	while(PF * PF <= n){
		pot = 0;
		while(n % PF == 0){ n /= PF; pot++;}
		if(pot){
			cout << PF << " " <<  pot << endl;
		}
		PF = primes[++idx];
	}
	if(n != 1) cout << n << "      " << 1 << endl;
}
int main(){
	sieve(1000000);
	ll n; cin >> n ;
	solve(n);
}