#include <bits/stdc++.h>

using namespace std;

int main (){
	int T, n;
	cin >> T;

	for( int i = 1; i <= T; i++){
		cin >> n ;

		long long res = (long long)n* (n-1);
		printf("Case %d: ", i);
		if( res % 4 == 0 ) printf("%lld\n", res / 4 );
		else printf("%lld/2\n", res/2 );
	}
}