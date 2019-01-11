#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int> > vii;

const int INF = 1 << 30;
int n;

void printPath( int s, int dest, vector<int>& p){
	if( s == dest) {cout << s + 1; return; }
	printPath(s, p[dest], p );
	cout << " " << dest + 1 ;
}

void bfs(vii& edges, int s, int dest){

	queue<int> q;
	vector<int> dis(n,INF);
	dis[s] = 0;
	q.push(s);
	vector<int> p(n);
	

	while(!q.empty()){
		int u  = q.front(); q.pop();

		for( int i = 0; i < edges[u].size(); i++){
			int v = edges[u][i];
			if( dis[u] + 1  < dis[v]){
				dis[v] = dis[u] + 1;
				q.push(v);
				p[v] = u;
			}
		}
	}
	
	if( dis[dest] == INF) cout << "connection impossible" << endl;
	else printPath(s, dest, p), cout << endl;
}

int convertToInt(string input){
	string:: size_type sz;
	int res = stoi(input, &sz);
	return res;
}

int main (){

	while(cin >> n){		
		vii edges(n);
		cin.ignore();
		string line;

		for(int i = 0; i < n; i++){
			int u, v;			
			getline(cin, line);			
			if(line.size() == 2) continue;		
			line += ',';

			int k = 2;
			string input = "";						
			while( k < line.size() ){
				if(line[k] == ',' ){
					v = convertToInt(input);										
					edges[i].push_back(--v);		
					input = "";
				}else{
					input += line[k];
				}
				k++;
			}			
		}
		// cout << "Hola" << endl;
		// for( int i = 0; i < edges.size(); i++){
		// 	cout << i << " ";
		// 	for( int j = 0; j < edges[i].size(); j++){
		// 	 	cout << edges[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		int queries; cin >> queries;		
		int s, dest;
		cout << "-----" << endl;
		for( int i = 0; i < queries; i++){
			cin >> s >> dest;

			bfs(edges, --s ,--dest);

		}	

	}
}