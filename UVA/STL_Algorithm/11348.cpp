#include <bits/stdc++.h>

using namespace std;

int main ( ){
	int cases;
	cin >> cases;
	for( int i = 1 ; i <= cases; i++){
		int n;cin >> n ;
		map<int, map<int,int> > mapaCartak; // carta, persona, cuantas tiene de esa
		map<int, map<int,int> >:: iterator it1; 
		for( int j = 0 ; j < n; j++){
			int m;
			cin >> m;
			while(m--){
				int cartaValor;
				cin >> cartaValor;
				mapaCartak[cartaValor][j]++; // j-esima persona con m[j] igual al valor de la carta							
			}	
		}
		vector<int> jugadores(n); //jugador, cartas unicas
		map<int,int>:: iterator it2;		

		int contCU = 0;
		for( it1 = mapaCartak.begin(); it1 != mapaCartak.end();it1++){
			if( ( it1->second).size() == 1 ){				 				
				 jugadores[((it1->second).begin())->first] ++;//= ((it1->second).begin())->second;
				 contCU++;
			}
		}		
		cout << "Case " << i << ":";
		cout << fixed;
		cout << setprecision(6);
		for( int i = 0; i < jugadores.size();i++){
			cout << " " << (jugadores[i]/(double)contCU)*100.0 <<"%";
		}
		cout << endl;


	}
}