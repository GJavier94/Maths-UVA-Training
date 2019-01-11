/*
primer wa- puse int a sq
debí haberlo puesto como ll puesto que la sqrt(2^64) = 2^32 y no cabe en int 
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ll n;
	while(cin >> n && n){
		ll sq = sqrt(n);		
		if(sq*sq == n )cout <<"yes" << endl;
		else cout << "no"<< endl;
	}
}