#include <bits/stdc++.h>

using namespace std;

int main ( ){
	vector<long> v;
	long n ;
	while(cin >> n){
		v.push_back(n);
		long n1, n2 ;
		nth_element ( v.begin(), v.begin() + v.size()/2, v.end());

		n1 = *(v.begin() + v.size() / 2);

		if (v.size() % 2 == 0) {
			nth_element(v.begin(), v.begin() + v.size() / 2 - 1, v.end());
			n2 = *(v.begin() + v.size() / 2 - 1);
			n1 = (n1 + n2) / 2;
		}

		cout << n1 << endl;
		
	}
}