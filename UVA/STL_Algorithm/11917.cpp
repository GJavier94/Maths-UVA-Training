#include <bits/stdc++.h>

using namespace std;

map<string , int > tareas;

int main ( ){
	
	int cases;
	cin >> cases;

	for(int i = 1; i <= cases; i++){
		tareas.clear();
		int n; // numero de tareas 
		cin >> n ;
		while(n--){
			string nombre; int duracion;
			cin >> nombre >> duracion;
			tareas.insert(pair<string,int>(nombre,duracion) );			
		}
		int d;
		string subject;
		cin >> d >> subject;

		map<string,int > :: iterator it ;

		it  = tareas.find(subject);
		cout << "Case " << i << ": ";


		if( (it == tareas.end()) ||
			(it-> second > d + 5)
		 ){
			cout << "Do your own homework!" << endl;
		}else if ( it->second <= d){
			cout << "Yesss" << endl;
		}else if ( it->second <= d + 5){
			cout << "Late" << endl;
		}

	}
}