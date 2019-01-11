#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

vi primes;
bitset<10000010> bs;
ll sieve_size;


#define MAX 100001

ll nDiv[MAX];
ll sDiv[MAX];

void sieve(ll upperbound){
	sieve_size = upperbound + 1;
	bs.set(); bs[0] = bs[1] = 0;
	for(ll i = 2; i <= sieve_size; i++)if(bs[i]){
		for(ll j = i*i; j <= sieve_size; j += i ) bs[j] = 0;
		primes.push_back((int)i);
	}
}

ll numDiv(int n){
	ll idx = 0, PF = primes[idx], ans = 1;
	while(PF * PF <= n ){
		ll power = 0;
		while(n % PF == 0 ){n /= PF; power++;}
		ans *= (power + 1);
		PF = primes[++idx];
	}
	if(n != 1) ans *= 2;
	return ans;
}
ll sumDiv(int n){
	ll idx = 0, PF = primes[idx], ans = 1;
	while(PF * PF <= n ){
		ll power = 0;
		while(n % PF == 0 ){n /= PF; power++;}
		ans *=  (ll) (pow((double)PF, power + 1.0) - 1) / (PF - 1);
		PF = primes[++idx];
	}
	if(n != 1) ans *=  (ll) (pow((double)n, 2.0) - 1) / (n - 1);
	return ans;
}

void solve(){
	nDiv[1] = 1;
	sDiv[1] = 1;
	for(int i = 2; i < MAX; i++){
		nDiv[i] = numDiv(i);
		sDiv[i] = sumDiv(i);
		//if(i < 20)cout << i << "  " << nDiv[i] << " " << sDiv[i] << endl;
	}
}

int main(){
	sieve(1000000);	
	solve();	
	ll a,b,k,cases;
	cin >> cases;
	while(cases--){
		cin >> a >> b >> k;
		ll s1 = 0, s2 = 0;
		for(ll i = a ; i <= b; i++){
			if(i % k == 0 ){				
				s1 += nDiv[i];
				s2 += sDiv[i];
			}
		}
		printf("%lld %lld\n",s1 , s2 );	
	}
}