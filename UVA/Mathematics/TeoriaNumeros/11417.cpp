#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b){return a*(b/ lcm(a,b));}

int main(){

	int n, G;
	while( cin >> n  && n ){
		G = 0;
		for(int i = 1; i < n; i++)
			for(int j = i + 1; j <= n; j++ )
				G += gcd(i,j);
		printf("%d\n",G);

	}
}