#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
//store x,y and d as global bariables
ll x, y, d;

void extendedEuclid(ll a, ll b){
	if(b == 0 ){x = 1; y = 0; d = a; return;}
	extendedEuclid(b, a % b);
	ll x1 = y;
	ll y1 = x -(a/b)*y;
	x = x1;
	y = y1;
}

int main(){
	ll a, b;
	while(cin >> a >> b){
		extendedEuclid(a,b);
		printf("%lld %lld %lld\n",x,y,d );
	}
}