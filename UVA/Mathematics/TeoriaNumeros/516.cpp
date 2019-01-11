#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int > vi;
typedef vector<ll> vll;
ll _sieve_size;
vi primes;
bitset<10000010> bs;

void sieve(ll upperbound ){
	_sieve_size = upperbound + 1;
	bs.set(); bs[0] = bs[1] = 0;
	for(ll i = 2; i <= _sieve_size; i++)if(bs[i]){
		for(ll j = i*i; j <= _sieve_size; j += i ) bs[j] = 0;
		primes.push_back((int)i);
	}
}

vi primeFactors(ll N){
	vi factors;
	ll idx = 0, PF  = primes[idx];
	while( PF  * PF <= N){
		while( N % PF == 0 ){ N /= PF; factors.push_back(PF);}
		PF = primes[++idx];
	}
	if(N != 1 ) factors.push_back(N);
	return factors;
}

int main(){
	sieve(100000);

	string line;
	while( getline(cin, line)  && line.size() != 1 ){
		stringstream ss(line);
		int p,e, result = 1;
		while( ss >> p >> e ) result *= pow(p,e);
		result--;
		vi r = primeFactors(result);
		if(r.size() == 1){ printf("%d 1\n", r[0]); continue;}		
		int pot = 1;
		bool flag = true;
		for(int i = r.size() - 2 ; i >= 0; i--){
			if(r[i] == r[i + 1]) pot++;
			else{
				if(flag) flag = false;
				else printf(" ");				
				printf("%d %d", r[i+1], pot); pot = 1;
			}
		}
		if(!flag) printf(" ");
		printf("%d %d\n",r[0], pot);
	}
}
