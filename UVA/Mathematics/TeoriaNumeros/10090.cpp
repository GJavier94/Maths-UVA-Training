
/*
extendido de euclides da 
ax + by = gcd(a,b)
ecuacion diofantica
ax + by = c
donde c = k*gcd es un multiplo del gcd si es que hay solucion

n1*m1 + n2 *m2 = n 
costo = c1*m1 + c2*m2  tal que el costo sea el minimo 

entonces 
con extendido de euclides

n1*m1 + n2*m2 = gcd(n1,n2)
luego gcd*k = n -> k = n /gcd

multiplicamos todo por k
[  n1*m1 + n2*m2 = gcd(n1,n2) ] * k 
   n1*k*m1 + n2*k*m2 = n
   (n1)*m1 + (n2)*k*m2 = n

   ahora  sabemos que las infinitas soluciones son 
   m1 = m1 + t*n2/gcd
   m2 = m2 - t*n1/gcd 
   variando t se obtienen todas las posibles soluciones

	quiero minimizar    
	costo = c1*(m1 + t*n2/gcd) + c2*( m2 - t*n1/gcd )
-> 	costo = c1*(m1 + t*n2/gcd) + c2*( m2 - t*n1/gcd )
-> 	costo = c1*m1 + c2*m2   + t*( n2/gcd - n1/gcd )

Queremos el minimo tal que m1 y m2 >= 0 entonces 
m1 = m1 + t*n2/gcd >= 0  -> t >= -m1*gcd/n2 -> ceil
m2 = m2 - t*n1/gcd >= 0  -> t <= m2*gcd/n1 -> floor

checar que el ceil sea menor que el floor si no la solucion no existe

luego la que minimice mas se escoge como soluciones 

ll cost = c1*n2 - c2*n1;
	if( cost * c  < cost * f)
	con t = c o t = f 

	FIN
*/



#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll x, y, d;
ll m1, m2, c1, c2, n1, n2, n, k;

void ex_eu(ll a, ll b ){
	if(b == 0 ){x = 1;  y = 0; d = a; return;}
	ex_eu(b , a % b );
	ll x1 = y;
	ll y1 = x - (a / b)*y;
	x = x1;
	y = y1;
}

bool solve(){
	ex_eu(n1, n2);	
	if(n % d !=  0 ) return false;
	m1 = x, m2 = y;	

	m1 *= n / d, m2 *= n / d;
	n1 /= d; n2 /= d;
	ll c,f;
	c = ceil(-(double)m1 / n2 );
	f = floor((double)m2 / n1 );
	if(c > f) return false;
	ll cost = c1*n2 - c2*n1;
	if( cost * c  < cost * f)
		x = m1 + n2*c, y = m2 - n1*c;
	else
		x = m1 + n2*f, y = m2 - n1*f;
	return true;
}

int main(){
	while( cin >> n  && n ){
		cin >> c1 >> n1 >> c2 >> n2;
		if(solve()) printf("%lld %lld\n", x, y );
		else printf("failed\n");
	}
}