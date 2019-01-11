#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cout << "PERFECTION OUTPUT\n";
	while( cin >> n  && n ){
		int sum = 0;
		for(int i = 1; i <= n/2; i++){
			if(!(n%i)){
				sum+=i;	
			}
		}
		printf("%5d  ",n);
		if( sum == n) printf("PERFECT\n");
		else if( sum < n) printf("DEFICIENT\n");
		else printf("ABUNDANT\n");
	}
	cout << "END OF OUTPUT\n";
}