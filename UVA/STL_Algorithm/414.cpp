#include <bits/stdc++.h>

using namespace std;

int main ( ){

	int n ;

	while( cin >> n  && n != 0 ){
		vector<int> vec;
		cin.ignore();
		int max = 0;
		while( n--){
			string cad;
			getline(cin, cad);
			vector<int> v(2);					
			int cont = 0 ;
			for (int i = 0; i< 25; i++){			
				if( cad[i] == 'X'){					
					cont++;
				}else{
					break;
				}
			}		
			if( cont == cad.size()){v[0]= 25; v[1]=0;}
			else{
				v[0] = cont;
				cont++;
				while(cad[cont] != 'X') cont++;
				v[1]=25-cont;				
			}
			if ( max < v[0]+v[1]) max = v[0]+v[1];
			vec.push_back(v[0] + v[1]);		
		}
		
		int acum = 0;
		int size = 25 - max;
		for( int i = 0; i < vec.size() ; i++){
			acum += ( 25 - vec[i] - size);			
		}
		cout << acum << endl;

	}
}