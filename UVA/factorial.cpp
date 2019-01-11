#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll sieve_size;
vi primes;
bitset<10000010> bs;

void sieve(ll upperbound){
	sieve_size = upperbound + 1;
	bs.set(); bs[0] = bs[1] = 0;	
	for(ll i = 2; i <= sieve_size; i++)if(bs[i]){
		for(ll j = i*i; j <= sieve_size; j += i) bs[j] = 0;
		primes.push_back((int)i);
	}
}

int get_powers(int n, int p){
    int res = 0;    
    for (int power = p ; power <= n ; power *= p) res += n/power;
    return res;
}

void solve(ll nfac){	
	for(int i = 0;  primes[i] <= nfac ; i++){					
		cout << primes[i]  << " " << get_powers(nfac, primes[i]) << endl;		
	}
}

int main(){
	sieve(1000000);
	ll n;
	scanf("%lld", &n);

	solve(n);
}