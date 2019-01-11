#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,k,sum;
	k = 3;
	while( cin >> n ){
		sum = n;
		n++;
		while(n >= k){
			sum += n/k;			
				n = n/k + n%k;			
		}
		cout << sum << endl;	
	}
	
}