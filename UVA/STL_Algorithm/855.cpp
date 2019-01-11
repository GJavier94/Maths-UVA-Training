#include <bits/stdc++.h>

using namespace std;

int main ( ){
	int cases;
	cin >> cases;

	while(cases--){
		int r,c,n;
		cin >> r >> c >> n;
		vector<int> coorx;
		vector<int> coory;

		for( int i = 0; i < n ; i++){
			int x,y; cin >> x >> y ;
			coorx.push_back(x);
			coory.push_back(y);
		}
		sort(coorx.begin(), coorx.end());
		sort(coory.begin(), coory.end());

		if(n % 2)// impares
			cout << "(Street: " << coorx[ (int)(n/2)  ] << ", Avenue: " << coory[ (int)(n/2)] << ")" << endl;
		else
			cout << "(Street: " << coorx[(int)(n/2) - 1   ] << ", Avenue: " << coory[ (int)(n/2) - 1] << ")" << endl;

	}
}