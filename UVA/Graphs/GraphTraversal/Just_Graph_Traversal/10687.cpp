#include <bits/stdc++.h>

using namespace std;

typedef vector<int> List;

typedef pair<int,int> Cor;

struct Graph
{
	vector<List> edges;
	vector<int> seen;
	int n;
	bool bi;

	Graph(int N, bool Bi = true):
	n(N), bi(Bi), edges(N,List()), seen(N,0)
	{}

	void addEdge(int u, int v){
		if(bi) edges[v].push_back(u);
		edges[u].push_back(v);
	}

	void dfs(int u){
		seen[u] = 1;
		for(int v:  edges[u])
			if(!seen[v])
				dfs(v);
	}
};


double distance(int x1, int y1, int x2, int y2){
	double result = 0;
	result = sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) );
	return result;
}


int main(){
	int n; 

	while( cin >> n && n != 0){
		Graph *g = new Graph(n,false);

		map<int,Cor > a;
		map<Cor, int> b;
		int x,y;

		for( int i = 0; i < n ; i++){
			cin >> x >> y, b[Cor(x,y)] = i, a[i] = Cor(x,y);
		}
		if( n <= 2){cout <<"All stations are reachable."<< endl; continue;}


		for( int i = 0; i < n; i++){
			priority_queue < pair<double, Cor > >Q; // distance, x , y 
			double d;
			int x1, x2, y1, y2;
			x1 = a[i].first; y1 = a[i].second;

			for(int j = 0; j < n ; j++){				
				if(i == j) continue;
				x2 = a[j].first;y2 = a[j].second;
				d = distance(x1,y1,x2,y2);
				//cout << x1 << " " << y1 << " " << x2 << " " << y2 << " D:" << d << endl;

				Q.push( make_pair( (-1)*d, Cor((-1)*x2, (-1)*y2 ) ) ) ;					
				
			}
			int v1x,v1y,v2x,v2y;
			v1x = (-1)*Q.top().second.first;
			v1y = (-1)*Q.top().second.second;
			Q.pop();

			v2x = (-1)*Q.top().second.first;
			v2y = (-1)*Q.top().second.second;
			Q.pop();

			int v1 = b[Cor(v1x,v1y)];
			int v2 = b[Cor(v2x,v2y)];
			int u = b[ Cor(x1,y1) ];
			g->addEdge(u,v1);
			g->addEdge(u,v2);

		}

		g->dfs(0);
		
		if( count(g->seen.begin(), g->seen.end(), 0) )
			cout << "There are stations that are unreachable." << endl;
		else 
			cout <<"All stations are reachable."<< endl;

		delete g;
	}
	return 0;
}