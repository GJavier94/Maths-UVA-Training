#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
vi primes;
bitset<10000010> bs;
ll sieve_size;

void sieve(ll upperbound){
	sieve_size = upperbound + 1;
	bs.set(); bs[0] = bs[1] = 0;

	for( ll i = 2; i <= sieve_size; i++)if(bs[i]){
		for( ll j = i*i; j <= sieve_size; j += i) bs[j] = 0;
		primes.push_back((int)i);
	}
}
void isprime(ll N){
	if(N <= sieve_size) return bs[i];
	for(int i = 0; i < primes.size(); i++)
		if(N % i == 0 ) return false;
	return true;
}
int main(){
	sieve(1000000);
}