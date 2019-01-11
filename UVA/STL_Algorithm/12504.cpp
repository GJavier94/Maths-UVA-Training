#include <bits/stdc++.h>

using namespace std;
void imprimirMapa(map<string,string>& m){
	map<string,string> :: iterator it;
	if( m.size() == 1) cout << m.begin()->first;
	else{
		it = m.begin();
		cout << it->first;
		it++;
		for(;it != m.end();it++){
			cout << "," << it->first;
		}
	}
	cout << endl;

}
map<string,string> mapea(string cad){
	string input,key,value;
	map<string,string> m;
	for( int i = 1; i <  cad.size(); i++){
		if(cad[i] == ':'){
			key = input;
			input = "";
		}
		else if( cad[i] == ',' || cad[i] == '}'){
			value = input;			
			if( key.size() != 0 && value.size() != 0)
			m[key] = value;
			key = "";
			input = "";
		}
		else{
			input += cad[i];
		}
	}
	return m;
}

int main ( ){
	int cases;
	cin >> cases;
	cin.ignore();
	while(cases--){
		string d1,d2;
		getline(cin, d1);		
		getline(cin, d2);		
		map<string,string> m1;
		map<string,string> m2;
		
		m1 = mapea(d1);
		m2 = mapea(d2);		

		if( !(m1.size() || m2.size()) ) {// diccionarios vacios
			cout << "No changes" << endl << endl;continue;			
		}else if(!m1.size()){// m1 vacio
			cout << "+";
			imprimirMapa(m2);			
			cout << endl;continue;
		}else if(!m2.size()){// m2 vacio
			cout << "-";
			imprimirMapa(m1);
			cout << endl;continue;
		}
		map<string,string> :: iterator it;
		map<string,string> add;
		map<string,string> sub;
		map<string,string> mod;

		for( it = m2.begin(); it != m2.end(); it++){
			if( m1[it->first] =="" ){ // add
				add[it->first] = "1";
			}
			else if (m1[it->first].compare(it->second) ){ //
				mod[it->first] = "1";
			}
		}
		for( it = m1.begin(); it != m1.end(); it++){
			if( m2[it->first] =="" ){ // sub
				sub[it->first] = "1";
			}
		}

		if( add.size() == 0 && sub.size() == 0 && mod.size() == 0){
			cout << "No changes" << endl;
		}
		if( add.size()!=0){cout << "+";imprimirMapa(add);}
		if( sub.size()!=0){cout << "-";imprimirMapa(sub);}
		if( mod.size()!=0){cout << "*";imprimirMapa(mod);}
		cout << endl;
	}
}






