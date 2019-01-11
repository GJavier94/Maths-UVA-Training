#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

ll sieve_size;
vi primes;
bitset<10000010> bs;

void sieve(ll upperbound ){
	sieve_size = upperbound + 1;
	bs.set(); bs[0] = bs[1] = 0;
	for(ll i = 2; i <= sieve_size; i++)if(bs[i]){
		for(ll j = i*i; j <= sieve_size; j += i ) bs[j] = 0;
		primes.push_back((int)i);
	}
}

int numPF(int n ){
	int idx = 0, PF = primes[idx], ans = 0;
	while( PF * PF <= n ){
		while(n % PF == 0 ){n /= PF; ans++;}		
		if(ans > 2) return 0;
		PF = primes[++idx];
	}

	if(n != 1 ) ans++;
	return  ans;
}

int main(){
	sieve(1000000);
	int n;
	while(cin >> n ){
		int numero, cont = 0;
		for(int i = 0; i < n ; i++){cin >> numero;if(numPF(numero) == 2) cont++;}
		printf("%d\n", cont);
	}
}