#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,k;

	while(cin >> n >> k ){
		int a = n;

		while(n >= k){
			a = a +(n/k);
			n = (n/k) + n%k;
		}
		cout << a << endl;
	}
}