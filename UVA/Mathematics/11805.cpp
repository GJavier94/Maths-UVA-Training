#include <bits/stdc++.h>

using namespace std;
#define FOR(i,a,b) for( int i = a; i < b ;i++)
int main(){
	int cases,n,k,p;
	cin >> cases;

	FOR(i,1,cases+1){
		cin >> n >> k >> p;		
		cout << "Case " << i << ": " << ((k + (p-1))%n)+1 << endl;
	}
}