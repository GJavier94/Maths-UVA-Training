#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll _sieve_size;
bitset< 1000000> bs;
vi primes;
void sieve(ll upperbound){
	_sieve_size = upperbound + 1;
	bs.set(); bs[0] = bs[1] = 0;

	for(ll i = 2 ; i <= _sieve_size; i++) if(bs[i]) {
		for(ll j = i*i; j <= _sieve_size; j += i) bs[j] = 0; 
		primes.push_back((int)i);
	}
}
bool isprime(ll N){
	if(N <= _sieve_size) return bs[N];
	for(int i = 0; i < primes.size(); i++)
		if(N % primes[i] == 0 ) return false;
	return true;
}
int main(){
	sieve(1000000);
	int L, U;
    while(scanf("%d %d", &L, &U) == 2) {
        long long i;
        int last = -1, p1, p2, p3, p4;
        int flag = 0;
        int close = 2147483647, dist = -close;
        for(i = L; i <= U; i++) {
            if(isprime(i)) {
                if(last == -1)
                    last = i;
                else {
                    if(i-last < close) {
                        close = i-last;
                        p1 = last, p2 = i;
                    }
                    if(i-last > dist) {
                        dist = i-last;
                        p3 = last, p4 = i;
                    }
                    last = i;
                    flag = 1;
                }
            }
        }
        if(flag == 0)
            puts("There are no adjacent primes.");
        else {
            printf("%d,%d are closest, %d,%d are most distant.\n", p1, p2, p3, p4);
        }
    }
}