#include <bits/stdc++.h>
using namespace std;

int main(){

	int n ;
	vector<int> v;
	while(cin >> n  ){
		v.push_back(n);
		long n1 = 0, n2 = 0;
		nth_element(v.begin (), v.begin() + v.size() / 2 ,v.end() );

		n1 = v[ v.size()/2 ];

		if(!v.size()&1){ // es divisible entre dos 
			nth_element(v.begin(), v.begin() + v.size()/2,v.end() );

			n1 = (n1 +  v[ v.size()/2  ]) / 2;
		}

		cout << n1 << endl;
	}
}	