#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> vii;
typedef vector<int> vi;
typedef vector<double> vd;

const int  SIZE = 27;
const int INF = 1 << 30 ;

double eleva(double num, int  pot){
	double result = num;
	for( int i = 0 ; i < pot-1 ; i++)result *= num;	
	if(pot == 0) return 1.0;
	return result;
}
int main (){

	int n;
	while( cin >> n ){
		vii edges(SIZE);
		vd prices(SIZE);

		char c;
		double precio;
		string nodos;
		for( int i = 0; i < n ; i++){
			cin >> c;
			int u  = c - 'A';
			cin >> prices[u] >> nodos;
			for( int j = 0; j < nodos.size(); j++){
				int v;
				if( nodos[j] == '*') v = 26;
				else v = nodos[j] -'A';
				if( v == 26){					
					edges[v].push_back(u);
				}else{
					edges[u].push_back(v);
					edges[v].push_back(u);
				}
			}

		}
		queue<int> q;
		vi dis(SIZE, INF);
		dis[26] = 0;
		q.push(26);

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
		
		vector<double> result(SIZE);
		double max = 0;
		char mejorNodo = 'A';
		for( int i = 0; i < SIZE; i++){
			if(dis[i] != INF){
				double base = 0.95, potencia = dis[i] - 1;
				result[i]  = prices[i]*eleva(base, potencia);				
				if( max < result[i]){
					max = result[i];			
					mejorNodo = (char)( i + 'A');
				}
			}
			
		}
		cout << "Import from "  << mejorNodo << endl;;

	}
}