#include <bits/stdc++.h>

using namespace std;

int main (){
	int t;
	cin >> t;
	cin.ignore();		
	while(t--){
		string title;
		getline(cin,title);
		int m,n,b;
		cin >> m >> n >> b; // b  = presupuesto 		
		cin.ignore();
		map<string,int> ma;
		map<int,map<string,int> > recipes; // costo y nombre de la receta
		map<int,map<string,int> > :: iterator it;
		map<string,int> rec;
		map<string,int> :: iterator itm;
		while(m--){
			string ingrediente;
			int costo;
			cin >> ingrediente >> costo;
			cin.ignore();			
			ma.insert(pair<string,int>(ingrediente,costo));			
		}
		while(n--){
			int k;
			string nrecipe;	
			getline(cin,nrecipe);			
			cin >> k;
			
			int costoRecipe = 0;			
			while(k--){
				string ingrediente;
				int unidades;
				cin >> ingrediente >> unidades;	
				cin.ignore();
				costoRecipe += ma[ingrediente]*unidades;
			}
			if( costoRecipe <= b){
				recipes[costoRecipe][nrecipe] = 1 ;				
			}			
		}
		for(int i = 0; i < title.size(); i++ ){
			if(title[i] >= 'a' && title[i] <='z'){
				title[i] -= 'a'-'A';
			}
			printf("%c", title[i]);
		}
		cout << endl;

		if( recipes.size()){
			for(it = recipes.begin(); it != recipes.end();it++){
				for(itm = (it->second ).begin(); itm != (it->second ).end(); itm++){
					cout << itm->first << endl;
				}
			}
		}else{
			cout << "Too expensive!" << endl;
		}
		
		cout << endl;
	}
}