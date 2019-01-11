#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


ll exp_bin_mod(ll b, ll p, ll m ){
	if(p == 0 ) return 1;
	if(p == 1) return b%m;
	if(p&1) return (b%m * exp_bin_mod( ((b%m)*(b%m))%m, (p-1) / 2, m)%m ) %m;
	else return (exp_bin_mod( ((b%m)*(b%m))%m , p / 2 , m))%m;
}


int main(){
	int n;
	while(cin >> n){
		bool flag = true;
		int i = 0;
		ll num = 0;
		while(flag){
			num =  (num + (1 *exp_bin_mod(10,i,n) )) %n;
			if(!num){flag = false; printf("%d\n",i + 1);}
			i++;
		}
	}
}