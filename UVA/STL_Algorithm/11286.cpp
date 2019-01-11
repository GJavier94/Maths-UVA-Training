#include <bits/stdc++.h>

using namespace std;

int main (){		
	int n; 
	while( cin >> n  && n !=  0 ){				
		map< map<int, int>, int > courses;
		map< map<int, int>, int > :: iterator it;
		while(n--){
			int m = 5;
			map<int, int> ma;			
			while(m--){
				int aux; cin >> aux; ma[aux] = 0;
			}			

			if( courses.find(ma ) == courses.end() ) courses[ma] = 1 ;
			else  courses[ma]++;				
		}

		int max = 0;
		for ( it = courses.begin(); it != courses.end(); it++){
			if( max <  it->second ) max = it->second;
		}		
		int acumulador = 0 ;
		for ( it = courses.begin(); it != courses.end(); it++){
			if ( it->second == max) acumulador+=max;
		}
		cout << acumulador << endl;
	}
}





