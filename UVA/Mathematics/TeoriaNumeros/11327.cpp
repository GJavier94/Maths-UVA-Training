#include <bits/stdc++.h>

using namespace std;

#define MAX 1000001

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

vll num( MAX );
vll :: iterator low;

ll gcd(ll a, ll b){return b == 0  ? a : gcd(b, a% b);}

void sieve(){
	for(int i = 0; i < MAX; i++) num[i] = i;
	for(int i = 2; i < MAX; i++)
		if(num[i] == i)
			for(int j = i; j < MAX; j += i )
				num[j] -= num[j] / i;
	num[1] = 2;
}
void solve(){
	for( int i = 1; i < MAX ;i++){
		num[i] += num[i - 1];		
	} 
}
int main(){
	sieve();
	solve();	
	ll n,a,b;
	while(cin >> n && n ){
		if(n == 1){ printf("0/1\n");continue;}
		if(n == 2){ printf("1/1\n"); continue;} 
  		low = lower_bound (num.begin(), num.end(), n);
	 	b = low -  num.begin();
	 	--low;
	 	ll k = n - *low;
	 	ll a = 1;	 	
	 	while(k != 0 ){
	 		if(gcd(a ,b ) == 1)k--;
	 		a++;
	 	}
	 	a--;
	 	printf("%lld/%lld\n",a,b );
	 	
	}
}











