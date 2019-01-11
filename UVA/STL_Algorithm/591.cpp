#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	int i = 1;

	while( cin >> n && n != 0 ){
		vector<int> v(n);
		int numberBr = 0 ;
		for (int i = 0; i < n; i++){
			cin >> v[i];
			numberBr += v[i];			
		}
		int size =(int) (numberBr/(double)n);
		int moves = 0 ;
		for (int i = 0; i < n; i++){
			if( v[i] < size){
				moves += size - v[i];
			}
		}
		cout << "Set #" << i << endl;
		cout << "The minimum number of moves is " << moves << "." <<endl << endl;;

		i++;
	}
	
}