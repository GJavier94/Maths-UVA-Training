/*
el programa pide todos los que gcd(i,n) != 1 & gcd(i,n) != i

#s1 phi de n te da los coprimos osea  gcd(i,n) != 1
#s2 numdDiv te da los que gcd(i,n) != i ya que son los divisiores

"1" entra en ambos conjuntos por eso se resta 1

#s1 + #s2 - 1 te da todos los que cumplen el contrario del problema
n - (#s1 + #s2 - 1) te da el complemento, "ES LA SOLUCION"
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll sieve_size;
vi primes;
bitset<10000010> bs;

void sieve(ll upperbound){
	sieve_size = upperbound + 1;
	bs.set(); bs[0] = bs[1] = 0;
	for(ll i = 2; i <= sieve_size; i++)if(bs[i]){
		for(ll j = i*i; j <= sieve_size; j += i) bs[j] = 0;
		primes.push_back((int)i);
	}
}

ll numDiv(ll n ){
	ll idx = 0, PF = primes[idx], ans = 1;
	while( PF * PF <= n ){
		ll power = 0;
		while(n % PF == 0 ){n /= PF; power++;}
		ans *= (power + 1);
		PF = primes[++idx];
	}
	if(n != 1 ) ans *= 2;
	return ans;
}
ll EulerPhi(ll n){
	ll idx = 0, PF = primes[idx], ans = n;

	while( PF * PF <=  n ){
		if(n % PF == 0 ) ans -= ans / PF;
		while(n %  PF == 0) n /= PF;
		PF = primes[++idx];
	}

	if(n != 1) ans -= ans / n; 
	return ans;
}
int main(){
	sieve(1000000);
	ll n;
	while(cin >> n ){
		ll result = n -  (EulerPhi(n) + numDiv(n) - 1);
		printf("%lld\n", result);
	}
}