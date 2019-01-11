#include <bits/stdc++.h>

using namespace std;

int main(){

	int cases; cin >> cases;
	int m,n, sum;
	while(cases--){
		cin >> m >> n ;
		sum = 0;

		if( m != n){
			sum = ceil(m/2.0) * ceil(n/2.0);
		}
		else{
			sum = ceil(n/2);
			sum  = (sum*(sum+1))/2;
		}
		
			

		cout << sum << endl;
	}
}