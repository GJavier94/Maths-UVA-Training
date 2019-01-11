#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll sieve_size;
vi primes;
bitset<10000010> bs;

#define SIZE 10000
vi nums(SIZE + 1);

void sieve(ll upperbound){
	sieve_size = upperbound + 1;
	bs.set(); bs[0] = bs[1] = 0;
	for(ll i = 2; i <= sieve_size; i++)if(bs[i]){
		for(ll j = i*i; j <= sieve_size; j += i ) bs[j] = 0;
		primes.push_back((int)i);
	}
}

int numDiv(int n){
	int idx = 0, PF = primes[idx], ans = 1;
	while(PF * PF <= n){
		ll power = 0;
		while(n % PF == 0 ){n /= PF; power++;}
		ans *= (power + 1);
		PF = primes[++idx];
	}
	if(n != 1) ans *= 2;
	return ans;
}

bool isPrime(ll n){
	if(n <= sieve_size) return bs[n];
	for(int i = 0; i <= primes.size(); i++)
		if(n % primes[i] == 0 )return false;
	
	return true;
}

void precalc(){
	nums[1] = 0;
	int res;
	for(int i = 2; i <= SIZE; i++ ){
		res = numDiv(i);
		if(isPrime(res)) nums[i] = 1;
	}
}

int main(){
	sieve(1000000);
	precalc();

	int cases;cin >> cases;
	int l,h;
	while(cases--){
		cin >> l >> h;
		bool flag = true;	
		for(int i = l; i <= h; i++){
			if(nums[i]){
				if(flag){printf("%d",i ); flag = false;} 
				else printf(" %d",i );	
			} 
		}
		if(flag) printf("-1");
		printf("\n");
	}
}
