#include <bits/stdc++.h>

using namespace std;

struct Contestant{
	int number,psolves, pentime;
	
	void init(){
		number = psolves = pentime = 0;		
	}
};

map<int,problem> :: iterator ite;
int main ( ){
	int cases; cin >> cases;
	cin.ignore();
	string cad;
	getline( cin , cad);
	while( cases--)	{
		vector<Contestant> cns;
		vector<Contestant> :: iterator it;
		while( getline(cin , cad) && cad.size() != 0 ){
			stringstream ss(cad);
			int numberC, numPro, tiempo;
			char statusProblem;
			cin >> numberC >> numPro >> tiempo >> statusProblem;
			bool estaConcursante = false;
			int pos = 0;
			for( int i = 0; i < cns.size(); i++){
					if ( cns[i].number == numberC ){   esta = true;  pos = i;}
			}
			if(estaConcursante){
				bool estaProblema = false;
				ite = (cns[pos].problems).find(numPro);
				if( ite != (cns[pos].problems).end())
			}else{

			}

			

		}
}
	}