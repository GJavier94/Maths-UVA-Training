#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll exp_bin_mod_v2(ll b, ll p, ll m ){
	ll ans = 1;	
	while (p) {
		if (p & 1) ans = (ans * b) % m;
		b = (b * b) % m;
		p >>= 1;
	}
	return ans;
}




ll exp_bin_mod(ll b, ll p, ll m ){
	if(p == 0 ) return 1;
	if(p == 1) return b%m;
	if(p&1) return (b%m * exp_bin_mod( ((b%m)*(b%m))%m, (p-1) / 2, m)%m ) %m;
	else return (exp_bin_mod( ((b%m)*(b%m))%m , p / 2 , m))%m;
}

int main(){
	ll b,p,m;
	while(cin >> b >> p >> m ){
		//ll res = exp_bin_mod(b % m ,p,m);
		ll res = exp_bin_mod_v2(b % m ,p,m);
		printf("%lld\n", res);
	}
}