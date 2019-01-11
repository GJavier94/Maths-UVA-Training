#include <bits/stdc++.h>

using namespace std;

int main(){

	int n;

	while(cin >> n){
		vector<int> v(n);
		map<int,int > ma;
		for(int i = 0; i < n; i++){
			cin >> v[i];
			ma[ v[i] ]++;
		} 
		sort(v.begin(), v.end());
		int i,val;
		//if( n == 1){ cout << v[i] << " 1 1" << endl; }
		if( n & 1 ){
			i = (n/2);
			cout << v[i] << " " << ma[v[i]] << " 1" << endl;
		}else{
			i = (n/2) - 1;
			int cuenta;

			cuenta = v[i] != v[i+1] ?  ma[v[i]] + ma[v[i+1]]  : ma[v[i]];

			cout << v[i] << " " << cuenta<< " " << v[i+1] - v[i] + 1 << endl;
		}
	}
}