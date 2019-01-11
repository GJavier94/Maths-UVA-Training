/*
WA!!
La funcion fib crece de manera de drastica para un valor dado n 
no cabe en long long es necesario usar BigInteger

*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll fib(ll n ){
	if(!n) return 0;
	if(n == 1) return 1;
	ll f0 = 0, f1 = 1, fi;

	for(ll i = 2; i <= n ; i++){
		fi = f0 + f1;
		f0 = f1;
		f1 = fi;
	}
	return fi;
}
int main(){
	ll n;
	while(cin >> n){
		printf("The Fibonacci number for %lld is %lld\n",n , fib(n));
	}
}