#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll _sieve_size;
vi primes;
bitset<10000010> bs;

void sieve(ll upperbound){
	_sieve_size = upperbound + 1;
	bs.set(); bs[0] = bs[1] = 0;

	for(ll i = 2; i <= _sieve_size; i++)if(bs[i]){
		for(ll j = i*i; j <= _sieve_size; j += i )bs[j] = 0;
		primes.push_back((int)i);					
	}
}
bool isprime(ll N){
	if( N <= _sieve_size) return bs[N];
	for(int i = 0; i < primes.size(); i++)
		if( N % primes[i] == 0 ) return false;
	return true;
}
int main(){
	sieve(1000000);	
	int T; cin >> T;
	int l, u;

	while(T--){
		cin >> l >> u;
		vi champs(1000000);
		vi:: iterator it1, aux,it2, it, p1, p2;
		it1 = lower_bound(primes.begin(), primes.end(), l);	
		it2 = lower_bound(primes.begin(), primes.end(), u);
		it2--,aux = it2;
		if(*(++aux) ==  l) it2++;				

		for(it = ++it1; it != it2; it++){
			p1 = it;
			aux = p1;
			p2 = ++aux;			
			champs[ abs( *p1 - *p2) ]++ ;
		}
		it = max_element(champs.begin(), champs.end());		
		int pos = it - champs.begin();
		int element = *it;
		int occurrences = count(champs.begin(), champs.end(), element);
		if(occurrences != 1 ) cout << "No jumping champion\n";
		else printf("The jumping champion is %d\n", pos);
		
	}
}

