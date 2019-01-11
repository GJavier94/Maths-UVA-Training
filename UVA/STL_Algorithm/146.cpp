#include <bits/stdc++.h>
using namespace std;
int main(){
	string cad;
	while( getline( cin , cad) && cad.compare("#") ) {
		char a[cad.size()];
		for( int i = 0; i < cad.size(); i++) 
			a[i] = cad[i];

		if( next_permutation(a, a + cad.size() )  ) 
			for( int i = 0; i < cad.size(); i++) cout << a[i];
		else cout << "No Successor";
		cout << endl;
	}
} 