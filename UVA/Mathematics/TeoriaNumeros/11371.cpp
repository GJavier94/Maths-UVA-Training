/*
 daddo un numero 
 se busca su *mnima permutacion y maxima permutacion 


 * la minima podria tener ceros en un inicio
 usamos prev_permm. mientras no tenga ceeros al inicio
 osse ->>>>>>   }while(prev_permutation(num.begin(), num.end()) && num[0] != '0');
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll sTon(string cad){
	ll num = 0;
	for(int i = 0; i < cad.size(); i++){
		num = num*10 + ( cad[i] - '0');
	}
	return num;
}
int main(){
	string num;
	while(cin >> num){
		string min, max;
		do{
			min = num;						
		}while(prev_permutation(num.begin(), num.end()) && num[0] != '0');
		
		do{
			max = num;			
		}while(next_permutation(num.begin(), num.end()));
		ll MAX, MIN;
		MAX = sTon(max);
		MIN = sTon(min);
		printf("%lld - %lld = %lld = 9 * %lld\n", 
			MAX, MIN, (MAX- MIN),   (ll) ((MAX- MIN)/ 9) );
	}
	
}	