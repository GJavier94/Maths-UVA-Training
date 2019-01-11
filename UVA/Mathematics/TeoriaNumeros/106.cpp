#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main(){

	int n; 
	while( cin >> n){
		vi v(n + 1, 0);
		v[0] = 1;

		int a,b,c;
		int a1,b1,c1;

		int m1 = 2, n1 = 1;
		int conTernas = 0;
		while( m1*m1 + n1*n1 <= n){
			a = m1*m1 - n1*n1;
			b = 2*m1*n1;
			c = m1*m1 + n1*n1;			
			if(gcd(a,gcd(b,c)) == 1 ){
				conTernas++;
				cout << a << " " << b << " " << c << endl;
				int a1 = a, b1 = b, c1 = c;
				while(c1 <= n  ){				
					v[a1] = v[b1] = v[c1] = 1;
					a1 += a, b1 += b, c1 += c;
				}
			}
			n1++;
			if( n1 == m1){m1++;n1 = 1;}
		}			
		int num = count(v.begin(), v.end(), 0);
		printf("%d %d\n",conTernas, num );
	}
}