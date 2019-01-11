/*
	problema 
	implemetnar un algoritmo que altera uan variable si la varaible supera un limite break

	aunt tengo problemas para ver cuando detener ciclos

	nota: me daaba wa porque el limite era el entero pero como lo comparo con algo mas quue  el entero debia usar ll 
	
*/


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main(){
	ll a,l;
	ll k = 1;
	while(cin >> a >> l && (a > 0 && l > 0 )){
		ll ap = a;
		ll count = 1;
		while(a != 1){
			if(a&1) a = 3*a + 1;
			else a = a/2;
			if(a > l ){break;} 
			count++;
		}			
		printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n", k++, ap, l , count);
	}
}