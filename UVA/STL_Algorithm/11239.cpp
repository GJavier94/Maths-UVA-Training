#include <bits/stdc++.h>

using namespace std;

#define ENDPROGRAMA "0"
#define ENDCASE "1"

int main(){
	string input;

	map<string, string > m; 
	map<string, string >:: iterator it;
	string grupo,student;

	map<string, int > listaGrupos;
	map<string, int >  :: iterator itg;
	vector<string> listaNegra;
	while( getline(cin , input) && input != ENDPROGRAMA){

		if( input != ENDCASE){			
			
			if(input[0] >= 'A' && input[0] <= 'Z'){
				grupo = input;
				listaGrupos[grupo] = 0;				
			}else{
				student = input;				
				it = m.find(student);
				if( it == m.end() ){					
					if( listaNegra.size ()    != 0){
						if( find(listaNegra.begin(), listaNegra.end(), student ) == listaNegra.end() ) {
							m[student]  = grupo;
						}						
					}else{
						m[student]  = grupo;
					}

				}  
				else {
					if( grupo != it->second ){m.erase(it); listaNegra.push_back(student); }					
					else m[student] = grupo;
				}
			}			
		}else{
			
			for( it = m.begin(); it != m.end();it++){				
				listaGrupos[it->second]++;				
			}
			map<int , map<string, int > ,std::greater<int> > listaOrdenada;
			map<int , map<string, int > > :: iterator itlo ;
			for( itg = listaGrupos.begin(); itg  != listaGrupos.end(); itg++){					
			 	listaOrdenada[itg->second][itg->first] = 1 ;			 	
			}

			for( itlo = listaOrdenada.begin(); itlo  != listaOrdenada.end(); itlo++){					
				for ( itg = itlo->second.begin() ; itg != itlo->second.end(); itg++ ){
					cout << itg->first  << " " << itlo->first << endl;
				}
			 
			}							
			m.clear();	
			listaGrupos.clear();
			listaNegra.clear();
			
		}
	}
}







