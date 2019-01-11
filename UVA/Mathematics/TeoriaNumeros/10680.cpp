#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

vi primes;
bitset<10000010> bs;
ll sieve_size;

void sieve(ll upperbound ){
	sieve_size = upperbound +1;
	bs.set(); bs[0] = bs[1] = 0;

	for(ll i = 2; i <= sieve_size; i++)if(bs[i]){
		for(ll j = i*i; j <= sieve_size; j += i ) bs[j] = 0;
		primes.push_back((int)i);
	}
}

int main(){
	sieve(1000000);
	ll n;
	while( cin >> n && n ){
		int result = 1;
		for(int i = 0; primes[i] <= n; i++){
			ll PF = primes[i], PK;
			for(ll Pk = PF; Pk <= n; Pk *= PF )PK = Pk;
			result = (result*PK);
         while(result % 10 == 0)
            result /= 10;
         result %= 10000000;
         
		}
		printf("%d\n",result%10 );
	}

}