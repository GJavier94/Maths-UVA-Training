#include <bits/stdc++.h>
using namespace std;

int main(){
	long n;

	while(cin >> n  && n ){
		cout << "f91(" << n << ") = ";
		if( n <= 101) cout << "91";
		else cout << n - 10;
		printf("\n");
	}
}