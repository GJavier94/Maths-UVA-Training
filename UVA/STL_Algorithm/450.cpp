#include <bits/stdc++.h>

using namespace std;
struct Reporte
{
	string depto, title, fn, ln, addr, homeph, workph,campus;
	void init(){
		title = fn = ln = addr = homeph = workph = campus = "";	
	}
	void print(){
		cout << "----------------------------------------" << endl;
		cout << title << " " << fn << " "  << ln << endl;
		cout << addr << endl;
		cout << "Department: " << depto  << endl;
		cout << "Home Phone: " << homeph << endl;
		cout << "Work Phone: " << workph << endl;
		cout << "Campus Box: " << campus << endl;
	}
};
bool myfn( Reporte r1,  Reporte r2){
	return  r1.ln < r2.ln;
}
int main(){

	int n;
	cin >> n;
	cin.ignore();
	vector<Reporte> reportes;
	while( n--){
		string depto;
		getline(cin, depto);
		string cad;
		while( getline(cin, cad) && cad != "" ){
			vector<string> v;
			for( int i = 0; i < cad.size(); i++){								
				string aux = "";
				int j = i;
				while(j < cad.size() && cad[j] != ',' ){aux += cad[j]; j++;}
				i = j;				
				v.push_back(aux);
			}
		
			Reporte r; r.init(); r.depto = depto; 
			r.title = v[0];
			r.fn = v[1];			
			r.ln = v[2];
			r.addr = v[3];
			r.homeph = v[4];
			r.workph = v[5];
			r.campus = v[6];
			reportes.push_back(r);
		}	
	}
	sort(reportes.begin(), reportes.end(), myfn);

	for( int i = 0 ; i < reportes.size(); i++){
		reportes[i].print();
	}
}
