#include <bits/stdc++.h>

using namespace std;

int main ( ){
	int N;
	cin >> N;	

	while( N--){
		int C;cin >> C;

		vector<string> v;
		map<string, string> keyCat;
		map<string, int > result;
		map<string,int> numberKeyWords;
		map<string, map<string,int> >  catKey;
		//lectura de categorias y kewords

		while(C--){
		
			string NameCategory; cin >> NameCategory;			
			v.push_back(NameCategory);
			int W,P;cin >> W >> P;						
			numberKeyWords[NameCategory] = P;
			while(W--){
				string keyword; cin >> keyword;				
				keyCat[ keyword ] = NameCategory;												
			}
		}
		string problem = "",aux = "";
		cin.ignore();
		while( getline(cin, aux) && aux.size() != 0 ){
			problem += aux + " ";			
		} 		
		
		string token = "";
		for ( int i = 0 ;  i < problem.size(); i++){
			if( (problem[i] >= 'A' && problem[i] <= 'Z') ||
			(problem[i] >= 'a' && problem[i] <= 'z') )
				token += problem[i];
			else{
				if(!token.size()) continue;				
				if(keyCat[token].size()){ // se encontro un token 

					string keyword, category; 
					keyword = token;
					category = keyCat[token];

					catKey[category][keyword] = 1;					

					if ( catKey[category].size() >= numberKeyWords[category] ){						
						result[category] = 1;
					}

				}								
				token = "";				
			}
		}

		if(!result.size()) cout << "SQF Problem" << endl;
		else{	
			if( result.size() == 1)	{
				cout << result.begin()->first<< endl;
			}else{
				int flag  = 0 ;
				for(int i = 0 ; i < v.size();i++){
					if(   result [ v[i] ] ){
						if( flag == 0){
							cout << v[i] << endl; flag = 1;	
						}else{
							cout << "," << v[i] << endl;
						}
						
					}
				}				
			}
		}

	}
}

