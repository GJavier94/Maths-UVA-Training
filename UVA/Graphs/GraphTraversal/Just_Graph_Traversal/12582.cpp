#include <bits/stdc++.h>

using namespace std;

int main(){

	int t; cin >> t;
	cin.ignore();
	string cad;
	for(int k = 1 ; k <= t; k++){
		getline(cin, cad);		
		vector<char> v;
		v.push_back(cad[0]);
		int i = 1;
		map<char,int > ma;
		map<char,int > :: iterator it ;
		while(v.size()){
			//cout << v[v.size() - 1] << " "<<  cad[i]<< endl;
			if(v[v.size() - 1]  != cad[i])
				ma[v[v.size() - 1]]++,ma[cad[i]]++, v.push_back(cad[i]);
			else v.pop_back();
			i++;
		}



		cout << "Case " << k << endl; 
		for( it = ma.begin(); it != ma.end(); it++){
			cout << (*it).first << " = " << (*it).second << endl;
		}
	}
}