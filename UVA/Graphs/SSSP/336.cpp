#include <bits/stdc++.h>

using namespace std;
#define INF 1<< 30
typedef pair<int,int> pii;

int var;

bool operator<(pii a, pii b){
	return a.second > b.second;
}

int bfs(int s, int d, vector<vector<int> > &v){

	vector<int> aux(var), distan(var, INF);

	priority_queue<pii> q;

	q.push(pii(s, 0));
	distan[s] = 0;

	while(!q.empty()){
		pii temp = q.top();
		q.pop();

		int u = temp.first, dis = temp.second;

		for(int i = 0; i <v[u].size(); i++){
			int V = v[u][i];

			if(dis + 1 <= d && dis+1 < distan[V]){
				//cout << V << '\n';
				aux[V] = 1;
				distan[V] = dis+1;
				q.push(pii(V, dis+1));
			}
		} 
	}

	int cont = 0;
	for(int i = 0; i <aux.size(); i++){
		if(!aux[i]){
			cont++;
		}
	}

	return --cont;
}

int main(){

	int m, a, b, z = 1;

	while(cin >> m && m){
		vector<vector<int> > v(30, vector<int>());
		map<int,int> idx;

		var = 0;

		while(m--){
			cin >> a >> b;

			if(idx.find(a)==idx.end()) idx[a] = var++;
			if(idx.find(b) == idx.end()) idx[b] = var++;

			v[idx[a]].push_back(idx[b]);
			v[idx[b]].push_back(idx[a]);
		}

		while(cin >> a >> b && a){
			cout << "Case " << z << ": " << bfs(idx[a], b, v)<<" nodes not reachable from node "<< a<< " with TTL = "<< b << ".\n";
			z++;
		}
	}


}