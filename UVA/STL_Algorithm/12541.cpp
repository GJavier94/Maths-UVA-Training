#include <bits/stdc++.h>

using namespace std;

struct Persona
{
	string name;
	int dia, mes, anio;
	void init(){
		name = "";
		dia = mes = anio = 0;
	}
};

bool myfn( Persona p1, Persona  p2){
	if( p1.anio != p2.anio ) return p1.anio < p2.anio;
	if( p1.mes  != p2.mes)   return p1.mes < p2.mes;

	return p1.dia < p2.dia;
}
int main ( ){
	int n;
	cin >> n;
	vector<Persona> ps;
	while( n-- ){		
		Persona p; p.init(); 
		cin >> p.name >> p.dia >> p.mes >> p.anio;				
		ps.push_back(p);
	}

	sort(ps.begin(), ps.end(), myfn);	
	cout << ps[ps.size()-1].name << endl;
	cout << ps[0].name << endl;	
} 