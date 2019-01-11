#include <bits/stdc++.h>

using namespace std;

int main ( ){

	int  cases, n , snow ;
	cin >> cases;
	
	while( cases--){
		cin >> n;
		vector<int> vec;
			
		while( n--){cin >> snow;vec.push_back(snow);}

		if( vec.size() == 0 ) { cout << 0 << endl; continue;}		
		if( vec.size() == 1 ) { cout << 1 << endl; continue;}
		
		int maxi = 0;
		int i = 0,  j = 0;		
		map<int,int> m;
		int contador = 0;
		while ( j != vec.size() ){
			if(m[vec[j]] == 0 ){
				m[vec[j]] = 1;
				j++;
				contador++;
			}			
			else{
				maxi = max(maxi, contador);
				while( m[vec[j]] != 0  ){
					m[vec[i]] = 0; i++;					
					contador--;
				}								
				m[vec[j]] = 1; contador++;		
				j++;
			}
	
		}
		
		maxi = max(maxi, contador) ;
		cout << maxi << endl;	
	}
}





