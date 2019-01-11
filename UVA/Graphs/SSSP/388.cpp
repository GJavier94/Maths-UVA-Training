#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int> > vii;
typedef vector<int> vi;
typedef vector<double> vd;

const int INF = 1 << 30;

double eleva(double num, int  pot){
	double result = num;
	for( int i = 0 ; i < pot-1 ; i++)result *= num;	
	if(pot == 0) return 1.0;
	return result;
}

int main(){
	int n;
	while(cin >> n ){

		vii edges(n + 1);
		vd precios(n + 1);
		map<char, int > m;
		map<int, char > am;
		m['*'] = 0;
		//am[0] = '*';
		precios[0] = 0.0;

		int index = 1;

		for(int i = 1; i < n + 1; i++){

			char c,d; cin >> c;			
			if( m.find(c) == m.end()){am[index] = c;m[c] = index;index++;} // 

			cin >> precios[index];

			string nodos; cin >> nodos;

			// for( int i = 0; i < nodos.size(); i++){
			// 	char d = nodos[i];
			// 	if( m.find(d) == m.end()){m[d] = index; am[index] = d; index++;}
			// 	if(d == '*'){
			// 		edges[m[c]].push_back(m[d]);
			// 		edges[m[d]].push_back(m[c]);
			// 	}else{
			// 		edges[m[c]].push_back(m[d]);
			// 	}
			// }			
		}
		// cout << index << endl;
		// for( int i = 0; i < edges.size(); i++){
		// 	cout << am[i];
		// 	for( int j = 0; j < edges[i].size(); j++){
		// 		cout << " " <<  am[edges[i][j]] ;
		// 	}	
		// 	cout << endl;
		// }

		// cout << "Impresion del grafo " << endl;
		// for( int i = 0; i < edges.size(); i++){
		// 		cout << am[i];
		// 	for( int j = 0; j < edges[i].size(); j++){
		// 		cout << " " <<  am[ edges[i][j] ] ;
		// 	}	
		// 	cout << endl;
		// }
		// cout << "fin del grafo " << endl;						

		queue<int> q;
		vi dis(n+1, INF);
		dis[0] = 0;
		q.push(0);

		while(!q.empty()){
			int u = q.front(); q.pop();
			for(int i = 0; i < edges[u].size(); i++){
				int v = edges[u][i];
				if(dis[u] + 1 < dis[v]){
					dis[v] = dis[u] + 1;
					q.push(v);
				}
			}
		}
		vector<double> result(n+1);
		for( int i = 1; i < n + 1; i++){
			double base = 0.95, potencia = dis[i] - 1;
			result[i]  = precios[i]*eleva(base, potencia);
			cout << m[i] << " " << result[i] << endl;
		}
	}
}

