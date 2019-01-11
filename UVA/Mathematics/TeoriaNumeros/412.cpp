#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){ return b == 0 ? a: gcd(b, a%b); }
int lcm(int a, int b){ return a*(b/gcd(a,b));}

typedef vector<int> vi;

int main(){
	int n; 
	while(cin >> n && n ){
		vi num(n);
		for(int i = 0; i < n; i++) cin >> num[i];

		int m = 0, p = 0;		
		for( int i = 0; i < n  ;i++)
			for(int j = i + 1; j < n ; j++){
			p++;
				if( gcd(num[i],num[j]) == 1 ){				
					m++;
				}
				
			}

		if( m == 0 ) printf("No estimate for this data set.\n");
		else{
			double pi = sqrt((6*p)/(m*1.0));
			printf("%.6f\n", pi );			
		}
	}
}