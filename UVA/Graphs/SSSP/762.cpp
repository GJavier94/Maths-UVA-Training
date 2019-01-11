#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int> > vii;

typedef map<string, int> mapa;

typedef map<int, string> mapav;

typedef vector<int> vi;

int n;
const int INF = 1 << 30;

void printPath(int o, int d, vi& p, mapav& am){
	if( o == d ){ return;}
	printPath(o, p[d], p , am);
	cout <<  am[p[d]] <<" " << am[d] << endl;
}


void bfs(vii& edges, mapav& am, int s, int dest){

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
	
	if( dis[dest] == INF) cout << "No route" << endl;
	else printPath(s, dest, p, am);
}

int main(){	
	bool flag = false;
	while(cin >> n){
		if(flag){cout << endl;}
		else{flag = true;}
		vii edges(n);
		mapa ma;
		mapav am;
		int var = 0;
		string x,y;

		for(int i  = 0; i < n ; i++){
			cin >> x >> y;
			if(ma.find(x) == ma.end()){ma[x] = var; am[var] = x; var++;}
			if(ma.find(y) == ma.end()){ma[y] = var; am[var] = y; var++;}
			if( ma[x] >= edges.size() ){
				vi aux; aux.push_back(ma[y]);
				edges.push_back(aux);
			}else{
				edges[ma[x]].push_back(ma[y]);
			}
			if( ma[y] >= edges.size() ){
				vi aux; aux.push_back(ma[x]) ;
				edges.push_back(aux);
			}else{
				edges[ma[y]].push_back(ma[x]);	
			}			
		}
		n = edges.size();

		int s, dest; 
		cin >> x >> y;
		if( ma.find(x) == ma.end() || ma.find(y) == ma.end()){
			cout << "No route" << endl;
		}else{
			s = ma[x];
			dest = ma[y];
			bfs(edges,am,  s, dest);
						
		}		
	}
}