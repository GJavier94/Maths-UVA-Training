#include <bits/stdc++.h>

using namespace std;

bool myfn( int a, int b){
	return a < b ;
}
int main (){
	int cases;
	cin >> cases;
	while(cases--){
		int s, a, n;
		cin >> s >> a >> n;
		vector<int> coorx;
		vector<int> coory;
		for( int i = 0 ; i < n; i++){
			int x, y ;
			cin >> x >> y;
			coorx.push_back(x);
			coory.push_back(y);
		}

		sort(coorx.begin(), coorx.end());
		sort(coory.begin(), coory.end(), myfn );

		if(n % 2){ // impares
			cout << "(Street: " << coorx[(coorx.size()/2.0)] << ", Avenue: " << coory[(coory.size()/2.0)] << ")" <<  endl;
		}else{ // pares 
			cout << "(Street: " << coorx[(coorx.size()/2.0) - 1] << ", Avenue: " << coory[(coory.size()/2.0) -1] << ")" << endl;
		}

		
	}
}
      