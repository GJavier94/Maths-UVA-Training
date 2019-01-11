#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

vi primes;
bitset<10000010> bs;
ll sieve_size;

#define SIZE 2000000

vi nums(SIZE + 1);
vi inde(SIZE + 1);

bool myfunction(int i, int j){
	if(nums[i] == nums[j]) return i < j;
	return nums[i] < nums [j];
}

void sieve(ll upperbound){
	sieve_size = upperbound + 1;
	bs.set(); bs[0] = bs[1] = 0;
	for(ll i = 2; i <= sieve_size; i++)if(bs[i]){
		for(ll j = i*i; j <= sieve_size; j += i ) bs[j] = 0;
		primes.push_back((int)i);
	}
}

int numPF(int n ){
	int idx = 0, PF = primes[idx], ans = 0;
	while( PF * PF <= n){
		while(n % PF == 0){n /= PF; ans++;}
		PF = primes[++idx];
	}
	if(n != 1) ans++;
	return ans;
}

void solve(){
	nums[0] = 0;
	
	for(int i = 1; i <= SIZE; i++ ){
		nums[i] = numPF(i);
		inde[i] = i;
	}
	sort(inde.begin(), inde.end(), myfunction);
}

int main(){
	sieve(1000000);
	solve();
	int n, k = 0;
	while(cin >> n  && n ){
		printf("Case %d: %d\n",++k, inde[n]);
	}
}