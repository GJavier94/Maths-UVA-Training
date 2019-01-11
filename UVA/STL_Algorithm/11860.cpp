#include <bits/stdc++.h>

using namespace std;

int main ( ){
	int t ;
	cin >> t;
	cin.ignore();	
	for( int k = 1; k <= t ; k++){		
		string texto = "" ,aux = "";
		while( getline(cin ,aux)  && aux.compare("END")){
			texto += aux + " ";
		}
		
		string input = "";
		map<string,int > words;
		vector<string> v;
		for( int i  = 0; i < texto.size(); i++){
			if( texto[i] >= 'a' && texto[i] <= 'z'){
				input += texto[i];
			}else{
				if( input.size()){		
					words[input] = 1;
					v.push_back(input);					
				}
				input = "";
			}
		}		


		if( words.size() == 1){
			cout << "Document "  << k << ": 1 1"  << endl;
			continue;
		}
		
		// barrido sobre  el vector
		map<string,int> result;
		map<int, map<int,int> > indices; // tam, i ,j 
		int i = 0, j = 0;
		result[v[0]]++;

		while( j != v.size()){
			if( result.size() != words.size()){	
				j++;
				if ( j == v.size() ) break;

				result[ v[j] ]++;
			}else{
				result[v[i]]--;
				if( result[v[i]] == 0  ) result.erase( v[i] );
				
				indices[ (j-i) + 1 ][i+1] = j+1;								
				i++;
			}
		}

		cout <<"Document " << k << ": " << ((indices.begin())->second).begin()->first << " " <<  ((indices.begin())->second).begin()->second << endl;
	}
}






