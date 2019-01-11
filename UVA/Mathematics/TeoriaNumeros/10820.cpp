#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

ll sieve_size;
vi primes;
bitset<10000010> bs;

#define SIZE 50001
vi nums(SIZE + 1 );

void sieve(ll upperbound){
	sieve_size = upperbound + 1;
	bs.set(); bs[0] = bs[1] = 0;
	for(ll i = 2; i <= sieve_size; i++)if(bs[i]){
		for(ll j = i*i; j <= sieve_size; j += i ) bs[j] = 0;
		primes.push_back((int)i);	
	}
}

int EulerPhi(int n){
	int idx = 0, PF = primes[idx], ans = n;
	while( PF * PF <= n ){
		if(n % PF == 0 ) ans -= ans / PF;
		while(n % PF == 0 ) n /= PF;
		PF = primes[++idx];
	}
	if(n != 1) ans -= ans / n;
	return ans;
}

void precalc(){	
	nums[1] = 1;
	for(int i = 2; i <= SIZE; i++)
		nums[i] = nums[i - 1] + (2*EulerPhi(i));
	
}

int main(){
	sieve(1000000);
	precalc();
	int n;	
	while(cin >> n && n){
		printf("%d\n", nums[n]);
	}
} 