#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,c,k,sum;	
	int cases; cin >> cases;

	while(cases--){
		cin >> n >> c >> k;
		n += c;		
		sum = 0;
		while(n >= k){
			sum += n/k;			
			n = n/k + n%k;
		}
		cout << sum << endl;	
	}
	
}