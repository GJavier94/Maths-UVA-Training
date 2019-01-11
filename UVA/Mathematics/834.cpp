#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int m, n;
	while(cin >> m >> n ){
		cout << '[';		
		if( m < n ) cout << "0", swap(m,n);
		else{
			cout << m/n;
			m = m%n;
			swap(m,n);
		} 
		if(n == 0 ){cout << ']' <<  endl; continue;	} 
		else cout << ';';

		bool flag = true;

		while( n != 0 ){
			if(!flag) cout << ',';
			else flag = false;
			cout << m/n;
			m = m%n;
			swap(m,n);
		}
		cout << ']' << endl;
		
	}
}