#include <bits/stdc++.h>

using namespace std;
int gcd(int a, int b){ return b == 0  ? a: gcd(b, a%b);}
int lcm(int a, int b){ return a*( b / gcd(a,b));}

int main(){

	int cases; cin >> cases;
	int a,b,g,l;

	while(cases--){
		cin >> g >> l;
		a = gcd(g,l);
		b = lcm(g,l);
		if(a != g || b != l) printf("-1\n");
		else printf("%d %d\n", g, l );
	}
}