/*
	multinomio es una generalizacion del binomio de newton 
	para obtener los coeficientes multinomiales de un termino
	dado (x1 + x2 + ... + x_k)^n 

	el coeficiente  m_ = (n! / n1!.n2!....nk!) donde n1 + n2 +...+ nk = n;
	tanto k y n < 13
	precalculo todos los factoriales de 0 a 12
	luego recibo  las entrdas  obtengo n! y obtengo cada uno de los factoirales
	lo voy almacenando en d que es  el divisor d*= nuevoFactor;

*/
// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// #define SIZE 13
// ll a[SIZE];
// void precalc(){
// 	a[0] = 1;
// 	a[1] = 1;
// 	for(int i = 2; i <= SIZE; i++) a[i] = a[i-1] * i;
// }
// int main(){
// 	precalc();
// 	int n,k;
// 	while(cin >> n >> k){
// 		ll d = 1, ans;
// 		for(int i = 1; i <= k;i++){
// 			int aux; cin >> aux;
// 			d *= a[aux];
// 		}
// 		ans = a[n] / d;
// 		cout << ans << "\n";
// 	}
// }

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define SIZE 13
ll a[SIZE];
void precalc(){
	a[0] = 1;a[1] = 1;
	for(int i = 2; i < SIZE; i++) a[i] = a[i - 1] * i;
}
int main(){
	precalc();
	int n,k;
	while(cin >> n >> k ){
		ll d = 1;
		while(k--){
			int aux; cin >> aux;
			d *= a[aux];
		}		
		cout << (a[n]/d) << "\n";
	}
}