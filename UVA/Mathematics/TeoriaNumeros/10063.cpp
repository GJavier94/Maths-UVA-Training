/*
Solucion 
el problema se modelaba de la siguiente manera

x = p*floor(x/k) + q*ceil(x /k)
habia que usar ambas funciones 


con ayuda del extendido de euclides 
se obtiene 
p*floor(x/k) + q*ceil(x /k) = gcd( floor(x/k), ceil(x /k) )

luego ya que x = h . gcd para encontrar el h = x /gcd 

asi ; 
h[   p*floor(x/k) + q*ceil(x /k)] = x  y listo se obtienen las soluciones
*/



#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll p, q ,d;
void ex_eu(ll a, ll b){
	if(b == 0 ){ p = 1, q = 0, d = a; return;}
	ex_eu(b, a % b);
	ll p1 = q; 
	ll q1 = p - (a / b) * q;
	p = p1;
	q = q1;	
}

int main(){
	int cases;cin >> cases;
	ll x,k,c,f;
	while(cases--){
		cin >> x >> k;
		f = floor((double) x / k);
		c = ceil((double) x / k);
		ex_eu(f,c);		
		p *= x / d, q *= x / d;
		printf("%lld %lld\n", p , q);

	}
}