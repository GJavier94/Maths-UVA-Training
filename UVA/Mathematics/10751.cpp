#include <bits/stdc++.h>

using namespace std;

int main(){

	int T; cin >> T;
	int n;

	while(T--){
		cin >> n;
		if( n == 1) printf("0.000\n");
		else if( n == 2) printf("4.000\n");
		else{
			
		int diag = 3*(n - 3) + 1;
		int norm = n*n - diag;
		double sum = norm + diag*(sqrt(2));
		printf("%.3f\n",sum );
		}
	}
}