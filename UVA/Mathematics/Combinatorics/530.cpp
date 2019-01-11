/*
 Para obetner c_nk de  manera eficiente se  toma c_nk = n! / (n-k)!k! = n(n-1)...(n-k+1) / 1.2.3-...k primero se multiplica y luego se divide
 1- TLE no tome en cuenta la identidad de simetria
 2. WA
 *Tome en cuenta simetria donde c_nk = c_n(n-k) "propiedad de Stiffel"
  Por ese motivo if(k > n - k  ) k = n - k ;
  * use int   c_nk si cabe en int pero los productos es posible que no 
  usare long long 
  3.AC
  	Use long long las operaciones intermedias no caben en int.  	
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	int n, k;
	while(cin >> n >> k &&  ( n || k) ) {
		if(k > n - k ) k = n - k;
		ll c_nk = 1;
		for(int i = 0; i < k ; i++){c_nk *= (n - i); c_nk /= (i + 1);} 
		printf("%lld\n",c_nk );
	}
}