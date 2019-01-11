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

int EulerPhi(int n){
	if(n == 1 ) return 0;	
	int idx = 0, PF = primes[idx], ans = n;
	while( PF * PF <= n ){
		if(n % PF == 0 ) ans -= ans / PF;
		while(n % PF == 0 ) n /= PF;
		PF = primes[++idx];
	}
	if(n != 1 ) ans -= ans / n; // el ultimo primo
	return ans;
}
int main(){
	sieve(1000000);
	int n;
	while( cin >> n  && n ){
		printf("%d\n", EulerPhi(n) );
	}
}



void sive(ll upperbound ){
	sieve_size = upperbound +1;
	bs.set(); bs[0] = bs[1] = 0 ;
	for(ll i = 2; i <= sieve_size; i++)if(bs[i]){
		for( ll j =  i*i; j <= sieve_size; j+= i)bs[j] = 0;
		primes.push_back((int)i);
	}
}

int main(){
	int cases;
	cin >> cases;

	while(cases--){
		cout << cases;
	}
}





