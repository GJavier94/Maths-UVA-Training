#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b );}
ll lcm(ll a, ll b){return a*(b/gcd(a,b) ) ;}

typedef set<int> vi;


int main(){
	ll n;
	while(cin >> n && n  ){
		ll raiz = (ll)sqrt(n);
		vi di;
		for( ll i = 1; i <= raiz; i++){
			if(n % i  == 0  ){
				di.insert(i);
				di.insert(n/i);				
			}
		}
		vi :: iterator i,j;
		ll cont = 0;
		for( i = di.begin(); i != di.end(); i++ )
			for(j = i; j != di.end(); j++ )									
				if( lcm( *i, *j) == n ){					
					cont++;
				}
			
		printf("%lld %lld\n",n, cont);
	}
}