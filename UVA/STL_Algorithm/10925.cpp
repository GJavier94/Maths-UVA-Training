#include <bits/stdc++.h>

using namespace std;

int main ( ){

	int m, n;
	cin >> m  >> n;	

	map<string, int> map;	

	string word;
	int value;
	while(m--){
		cin >> word >> value;
		map[word] = value;		
	}
	
	string line;
	while(n--){
		int monto = 0;
		while(getline( cin , line ) && line != "." ) {
			stringstream ss(line);		
			while(ss >> word){				
				monto += map[word];
			}
		}
		cout << monto << endl;
	}
}