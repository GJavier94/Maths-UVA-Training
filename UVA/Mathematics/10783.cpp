#include <bits/stdc++.h>

using namespace std;
#define FOR(i,a,b) for( int i = a; i < b; i++)
int main(){

	int T; cin >> T;
	int n1,n2;
	FOR(caso,1,T + 1){
		cin >> n1 >> n2;
		int sum = 0;
		for(int i = n1 ; i <= n2 ; i++){
			if(i&1) sum += i;
		}
		printf("Case %d: %d\n",caso, sum);
	}

}