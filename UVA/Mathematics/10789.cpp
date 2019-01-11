#include <bits/stdc++.h>

using namespace std;
#define FOR(i,a,b) for( int i = a; i < b; i++)
int main(){
	
	int T; cin >> T;

	FOR(casos,1, T + 1){
		int n; cin >> n;
		int inv;
		int k = 0;

		printf("Case #%d: %d",casos,n);

		for(int i = 2; i < n/2 && k < 2; i++){
			if(!(n%i)){
				inv = n/i;k++; 
				printf(" = %d * %d",i, inv);
			}
		}
		cout << endl;

	}
}