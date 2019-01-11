/*
c puede ir hasta 10^18
si lo multiplico por 10.0 se truncaba 
deber ser por 10.0L
*/


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll c, n ; 
	while(cin >> c && c){
		n = (10.0L*c)/9.0;
		bool flag = true;
		for(ll i = n - 10 ;  i <= n + 10; i++ ){
			if(c == i - (ll)(i/10)){
				if(flag){flag = false; printf("%lld",i );}
				else printf(" %lld",i );
			}
		}
		printf("\n");
	}
}