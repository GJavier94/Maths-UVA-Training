#include <bits/stdc++.h>

using namespace std;

int main (){

	int n ; cin >> n;
	string specie;
	int flag = 0;

	while(n--){
		map<string, int> m;
		map<string, int> :: iterator it;
		int numArboles = 0;
		if(flag == 0){
			getline(cin ,specie);		
			getline(cin ,specie);
			flag = 1;			
		}	
		while( getline( cin, specie) && specie.size() != 0  ){				
			it = m.find(specie);
			if( it == m.end()) m[specie] = 1;
			else m[specie]++;		
			numArboles++;			
		}			
		cout << fixed;
		cout << setprecision(4);

		for( it = m.begin() ; it != m.end(); it++){
			cout << it->first << " " <<  it->second*100.0/numArboles << endl;
		}
		if ( n != 0 ) cout << endl;
	}
}


