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
		for(ll j = i*i; j <= sieve_size; j += i ) bs[j] = 0;
		primes.push_back((int)i);
	}	
}
int solve(int a, int n) {
	if(n%a) return 0;

    int i, b = 1;
    int t1, t2;
    for(i = 0; i < primes.size() && primes[i]*primes[i] <= n; i++) {
        if(n%primes[i] == 0) {
            t1 = 1, t2 = 1;
            while(n%primes[i] == 0)
                n /= primes[i], t1 *= primes[i];
            while(a%primes[i] == 0)
                a /= primes[i], t2 *= primes[i];
            if(t1 > t2)
                b *= t1;
        }
    }
    if(n != 1 && a == 1)
        b *= n;
    return b;
}
int main(){
	sieve(1000000);
	ll a,b,c;
	int cases;
	scanf("%d",&cases);
	while(cases--){
		scanf("%lld %lld", &a, &c);
		ll sol;
		if(sol = solve(a,c))
			printf("%lld\n",sol);
		else
			printf("NO SOLUTION\n");
	}
}