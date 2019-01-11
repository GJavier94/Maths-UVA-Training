#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;
/*
la complejidad  de la exponenciacion binaria
es lg2 (y)
dado x^y
*/

/*
Modulares
*/
//modo recursivo 

int exp_bin(int n, int p, int m ){
	if( p == 0 ) return 1;
	if( p == 1 ) return n;
	if(p&1) return (n%m*exp_bin( ( (n%m)*(n%m))%m, (p-1) / 2)%m)%m;
	else return (exp_bin((n%m)*(n%m))%m, p / 2))%m;	
}

// modo iterativo
int  exp_bin_mod_v2(int b, int p, int  m ){
	int ans = 1;	
	while (p) {
		if (p & 1) ans = (ans * b) % m;
		b = (b * b) % m;
		p >>= 1;
	}
	return ans;
}


/*
Normales
*/
// modo recursivo

int exp_bin(int n, int p){
	if( p == 0 ) return 1;
	if( p == 1 ) return n;
	if(p&1) return n*exp_bin(n*n, (p-1) / 2);
	else return exp_bin(n*n, p / 2);	
}

//modo iterativo
int  exp_bin_v2(int b, int p){
	int ans = 1;	
	while (p) {
		if (p & 1) ans = (ans * b);
		b = (b * b);
		p >>= 1;
	}
	return ans;
}



int main(){
	int n, p;
	//cin >> n >> p;
	printf("%d\n", exp_bin(2,30) );
	printf("%d\n", exp_bin_v2(n,p) );
}


