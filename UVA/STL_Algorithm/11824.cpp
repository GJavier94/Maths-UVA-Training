#include <bits/stdc++.h>

using namespace std;

bool myfn( long long a, long long b){
	return a > b;
}

int main(){
	int t; cin >> t;

	while( t--){
		int l;
		vector<long long> lands;
		while( cin >> l && l != 0 ){
			lands.push_back(l);
		}
		sort(lands.begin(), lands.end(), myfn);
		
		long long  suma = 0;
		int flag = 0 ;
		for( int i = 0; i < lands.size(); i++){
			suma += 2*( pow( lands[i], (i+1) ) ) ;
			if( suma  > 5000000 ) {  cout << "Too expensive" << endl; flag = 1; break; }
		}	
		if( flag == 0 )
 		cout << suma << endl;
		
	}
}