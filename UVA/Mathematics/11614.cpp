#include <bits/stdc++.h>
using namespace std;
/*
	n(n+1)/2 = sum
	hacemos piso y restamos uno 
*/
int main(){
	int t;

	long long n;
	cin >> t;

	while(t--){
		cin >> n;
		long long result = (long long)floor(sqrt( 2.0 * n + 0.25 ) + 0.5) - 1;
		printf("%lld\n", result);
	}
}