#include <bits/stdc++.h>

using namespace std;

int main ( ){
	int ns ;
	cin >> ns;

	map<string,string> m;
	string s1,s2;
	cin.ignore(100,'\n');
	while(ns--){		
		getline(cin,s1);
		getline(cin,s2);				
		m.insert(pair<string,string>(s1,s2));		
	}
	int k;
	cin >> k;	
	cin.ignore(100,'\n');
	while(k--){
		getline(cin ,s1);

		cout << m[s1] << endl;
	}
}