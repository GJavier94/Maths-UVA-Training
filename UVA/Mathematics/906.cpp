#include <bits/stdc++.h>

using namespace std;

int main(){

	long long a,b,c,d;
	int n;
	double eps;

	while( cin >> a >> b){
		cin >> eps;
		long double t1 = (long double)a/b, t2;
		d = 1;
		while(true){
			c = (long long) (t1*d);
			while(a*d >= b*c) c++;
			t2 = (long double)c/d;
			if( t2 - t1 <= eps){
				printf("%lld %lld\n", c, d);
				break;
			}			
			d++;
		}		
	}

}