#include <bits/stdc++.h>

using namespace std;

int main ( ){
	int tam; 
	while(cin >> tam){
		vector<int> v(tam);
		for (int i = 0; i < v.size(); i++){
			cin >> v[i];
		}
		map<int,int> m;
		for (int i = 0; i < v.size()-1; i++){
			int value  = abs( v[i+1] - v[i]);
			if( value >= 1  && value <= v.size()-1){
				m[abs( v[i+1] - v[i])] = 1;				
			}
		}
		if( m.size() == v.size() - 1 ){
			cout << "Jolly" << endl;
		}else{
			cout << "Not jolly" << endl;
		}
	}
}