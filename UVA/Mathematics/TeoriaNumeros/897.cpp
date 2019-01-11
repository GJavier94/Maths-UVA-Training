#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

ll _sieve_size;
vi primes;
bitset<10000010> bs;

void sieve(ll upperbound){
	_sieve_size = upperbound + 1;
	bs.set(); 
	bs[0] = bs[1] = 0;
	for(ll i = 2; i <= _sieve_size; i++)if(bs[i]){
		for(ll j = i*i; j <= _sieve_size; j += i ) bs[j] = 0;
		primes.push_back((int)i);
	}
}

bool isprime(ll N){
	if( N <= _sieve_size) return bs[N];
	for(int i = 0; i < primes.size(); i++)
		if(N % primes[i] == 0 ) return false;
	return true;
}

int main(){
	sieve(10000000);
	ll n; 
	while(scanf("%lld", &n) && n){
		int dig = 0; ll n1;
		n1 = n;
		bool isflag = true;
		while(n1 !=0 ) n1 /= 10,dig++;				
		ll max  =  pow(10,dig );
		for( ll num = n + 1; num < max; num++ ){
			int aux = num;			
			if(!isprime(aux)) continue;
			bool flag = true;
			for(int i = 0; i < dig-1 && flag ; i++){
				int mod = aux%10;
				aux /=10;
				mod *=pow(10,dig-1);
				aux += mod;				
				if(!isprime(aux)) flag = false;
			}			
			if(flag){
				printf("%lld\n",num);
				isflag = false;
				break;
			}			
		}
		if(isflag) printf("0\n");
	}
}