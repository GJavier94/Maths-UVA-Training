#include <bits/stdc++.h>

using namespace std;
map<string, string> personas;
map<string, string> :: iterator itPersonas ;

map<string, vector<string> > parientes;
map<string, vector<string> > :: iterator itParientes;

void recorrePadres(string hijo, string papa1, string papa2 ){
	if ( personas.find(papa1) == personas.end() )
		recorrePadres(papa1, parientes[papa1][0], parientes[papa1][1]);
	if( personas.find(papa2)  == personas.end())
		recorrePadres(papa2, parientes[papa2][0], parientes[papa2][1]);

	bool gen = false;

	if( personas[papa1] != "non-existent" && personas[papa2] != "non-existent"){
		gen = true;
	}else if( personas[papa1] == "dominant"  || personas[papa2] == "dominant"){
		gen = true;
	}

	if( gen ){
		if( personas[papa1] == "dominant" && personas[papa2] == "dominant"){
			personas[hijo] = "dominant";
		}else if( personas[papa1] == "dominant" && personas[papa2] == "recessive"){
			personas[hijo] = "dominant";
		}else if ( personas[papa1] == "recessive" && personas[papa2] == "dominant"){
			personas[hijo] = "dominant";
		}else{
			personas[hijo] = "recessive";
		}
	}else{
		personas[hijo] = "non-existent";
	}
}

int main ( ){


	int n; cin >> n;	
	string  c1, c2;
	

	while(n--){ 
		cin >> c1 >> c2;

		if( c2 == "dominant" || c2 == "recessive" || c2 == "non-existent"){
			personas[c1] = c2;
		}else{
			parientes[c2].push_back(c1);
		}		
	}
	// cout << "personas" << endl;
	// for( itPersonas = personas.begin(); itPersonas != personas.end(); itPersonas++){
	// 	cout << itPersonas->first << " " << itPersonas->second << endl;
	// }cout << "parientes" << endl;
	// for( itParientes = parientes.begin(); itParientes != parientes.end(); itParientes++){
	// 	cout << itParientes->first << " " << (itParientes->second)[0] << " " << (itParientes->second)[0] << endl;
	// }

	for( itParientes = parientes.begin();  itParientes != parientes.end(); itParientes++){
		// le mandamos el hijo y sus dos papas
		recorrePadres(itParientes-> first, (itParientes->second)[0],(itParientes->second)[1]);
	}



	for( itPersonas = personas.begin() ; itPersonas != personas.end() ; itPersonas++){
		cout << itPersonas-> first << " " << itPersonas->second << endl;

	}
}


