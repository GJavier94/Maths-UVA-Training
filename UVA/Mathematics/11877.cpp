#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,c,k,sum;	

	while(cin >> n && n){		
		k = 3;
		n++;
		sum = 0;
		while(n >= k){
			sum += n/k;			
			n = n/k + n%k;			
		}
		cout << sum << endl;	
	}
}