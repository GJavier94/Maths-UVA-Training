#include <bits/stdc++.h>
using namespace std;
	
typedef vector<vector<int> > vii;
typedef vector<int>  vi;
typedef pair<double,double> Point;
typedef vector<Point>  vp;
typedef map<Point, int> mapa;
const int INF = 1 << 30;
const int n = 1000;

void bfs(vii& edges, int s, int dest, int  max){
	queue<int > q;
	vi dis(max, INF);
	q.push(s);
	dis[s] = 0;
	while(!q.empty()){
		int u = q.front(); q.pop();
		for( int i = 0; i < edges[u].size(); i++){
			int v = edges[u][i];
			if( dis[u] + 1 < dis[v] ){
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
	if(dis[dest] != INF) cout << "Yes, visiting " << dis[dest] - 1 << " other holes." << endl;
	else cout << "No."<< endl;
}

int main(){
	double v,t;
	while(cin >> v >> t && (v || t ) ) {
		double xs, ys, xt, yt,rad;
		rad = v*t*60;
		cin >> xs >> ys >> xt >> yt;cin.ignore();		
		mapa m; vp v(n);
		int id = 0;
		m[(Point){xs,ys}] = id; v[id] = (Point){xs,ys} ;   id++;
		m[(Point){xt,yt}] = id; v[id] = (Point){xt,yt} ;   id++;
		vii edges(n);
		if(sqrt( (xs-xt)*(xs-xt) + (ys-yt)*(ys-yt) )  < rad ){
			edges[0].push_back(1);
			edges[1].push_back(0);
		}
		string line;		
		double x,y;
		while( getline(cin, line) && line.size() != 0 ){
			stringstream ss(line);
			ss >> x >> y;	
			m[(Point){x,y}] = id; v[id] = (Point){x,y};		
			for( int u = 0; u < id; u++){
				double xi,yi, dist;				
				xi  = v[u].first;
				yi  = v[u].second;
				dist = sqrt( (xi-x)*(xi-x) + (yi-y)*(yi-y) );
				if( dist < rad ){
					edges[u].push_back(id);
					edges[id].push_back(u);
				}
			}
			id++;
		}
		bfs(edges, m[(Point){xs,ys}], m[(Point){xt,yt}], id);
	}
	return 0;
}