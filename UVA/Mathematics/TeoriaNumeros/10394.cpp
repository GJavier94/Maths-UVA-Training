#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
ll _sieve_size;
bitset<20000000> bs;
vector<ii> v;
void sieve(ll upperbound){
	_sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] =  0;
	int lastPrime = 2;
	for(ll i = 2 ; i <= _sieve_size; i++)if(bs[i]){
		for(ll j = i*i; j <= _sieve_size; j += i ) bs[j] = 0;
		if( abs(lastPrime -  i ) == 2) v.push_back( ii(lastPrime, i) );		
		lastPrime = i;
	}	
}
int main(){
	sieve(20000000); 
	int n;
	while( cin >> n ){
		ii  par = (v[n - 1]);
		printf("(%d, %d)\n",par.first, par.second );
	}
}
