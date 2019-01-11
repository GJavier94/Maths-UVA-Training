#include <bits/stdc++.h>

using namespace std;

int main(){
	
	long long int n;

	while( cin >> n  && n >= 0 ){
		if( n == 1 ) {printf("0%%\n"); continue;}
		cout << n*25 << '%' << '\n';
		
	}
}