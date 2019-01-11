#include <bits/stdc++.h>

using namespace std;

int main ( ){

	string cad;
	while( getline(cin, cad) &&  cad.compare("****END_OF_INPUT****") ){
		string texto  = "";		
		while( cad.compare("****END_OF_TEXT****")){
			texto += cad + " ";			
			getline(cin, cad);
		}

		map<string, int > m;
		map<string, int > :: iterator it;

		string palabra  = "";

		int l = 0, n;
		int flag  = 0 ;
		for (int i = 0; i < texto.size(); i++){
			if( texto[i] >= 'A' && texto[i] <= 'Z' ) texto[i] += 'a' - 'A';

			if( texto[i] == ',' || texto[i] == '.' || texto[i] == ':' || 
			    texto[i] == ';' || texto[i] == '!' || texto[i] == '?' || 
			    texto[i] == '"' || texto[i] == '(' || texto[i] == ')' || 
			    texto[i] == ' ' || texto[i] == '\t'|| texto[i] == '\n' ){
				if( palabra.size() != 0){
					it = m.find( palabra );
					if( it != m.end( )) m[palabra]++;
					else m[palabra] = 1;				
					palabra = "";
					l++;			
				}
			}else{
				palabra += texto[i];
			}
		}		

		n = m.size();	
		double logL = log10(l);
		double et = 0.0, emax = 0.0;
		double erel = 0;
		for( it = m.begin(); it != m.end(); it++){
			et += (it->second) * (logL - log10(it->second));
		}
		et *= (1.0 / l);
		emax = logL;
		cout << l << " ";
		erel = ((et / emax)*100.0);
		int erelaux= (int)erel;
		erelaux = ((erel - erelaux) >= 0.5) ? erelaux + 1 : erelaux;

		cout << setprecision(1);
		cout << fixed;
		cout << et << " " << erelaux << endl;	
	}	
}



