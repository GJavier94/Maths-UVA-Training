#include <bits/stdc++.h>

using namespace std;

int main (){
	int p,g;

	cin >> p >> g;
	
	string partido;
	int porcentaje;
	map<string,int> m;
	while( p--){
		int n1, n2;
		char punto;
		cin >> partido >> n1 >> punto >> n2;	
		porcentaje = (n1*10)+n2;
		//cout << porcentaje<< endl;
		m[partido] = porcentaje;		
	}
	cin.ignore();
	for(int i = 1 ; i <=  g ; i++) {
		string guest,input;
		getline(cin,guest);

		stringstream ss(guest);

		int totalSupuesto = 0, total = 0;
		string comparador;
		while(ss >> input){

			if (!input.compare(">") ||
				!input.compare("<") ||
				!input.compare(">=") ||
				!input.compare("<=") ||
				!input.compare("=")
			){
				ss >> totalSupuesto;
				comparador = input;
			}else{
				if ( input.compare("+") ){
					total += m[input];
				}	
			} 
		}
		totalSupuesto *=10 ;
		
		cout << "Guess #" << i << " ";

		if(!comparador.compare("<")){
			if ( total < totalSupuesto){
				cout << "was correct." << endl;
			}else{
				cout << "was incorrect." << endl;
			}

		}else if(!comparador.compare(">")){
			if ( total > totalSupuesto){
				cout << "was correct." << endl;
			}else{
				cout << "was incorrect." << endl;
			}
		}
		else if(!comparador.compare("<=")){
			if ( total <= totalSupuesto){
				cout << "was correct." << endl;
			}else{
				cout << "was incorrect." << endl;
			}
		}
		else if(!comparador.compare(">=")){
			if ( total >= totalSupuesto){
				cout << "was correct." << endl;
			}else{
				cout << "was incorrect." << endl;
			}
		}
		else {
			if ( total == totalSupuesto){
				cout << "was correct." << endl;
			}else{
				cout << "was incorrect." << endl;
			}
		}

	}

}