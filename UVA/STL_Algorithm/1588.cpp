#include <bits/stdc++.h>

using namespace std;



bool myfn ( int e1 , int e2){
	return e1 >  e2;
}
int main(){

	int cases;
	cin >> cases;

	for(int i = 1; i <= cases; i++){
		int r,c,m,n ;
		cin >> r >> c >> m >> n;
		cin.ignore();
		map<char, int > m1;
		map<char, int > :: iterator it;
		
		for( int i = 0; i < r ; i++){
			string cad;
			getline(cin, cad);
			for (int j = 0; j < c; j++){
				m1[ cad[j] ]++; 
			}	

		}

		vector<int> v;
		for( it = m1.begin(); it != m1.end(); it++) v.push_back(it->second);		
		
		sort( v.begin(), v.end(), myfn);

		int max = v[0];
		int size = 0 ;
		for( int i = 0 ; i < v.size(); i++){
			if(v[i]  == max) size += m * v[i];
			else size += n * v[i];
		}
		cout << "Case " << i << ": " << size << endl;
	}
}






