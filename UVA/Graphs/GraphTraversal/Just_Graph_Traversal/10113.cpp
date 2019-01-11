#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> nums;

typedef par<int, nums> edge;

typedef vector<edge> List;

struct Graph
{
    vector<List> edges;
    vector<int> seen;
    int n;
    bool bi;

    Graph(int N, bool Bi = true):
    n(N), bi(Bi), edges(N,List()), seen(N,0)
    {}

    void addEdge(int u, int v, nums n){
      if(bi) edges[v].push_back(edge(u,n));
      edges[u].push_back(edge(v,n));
    }
    void dfs(){

    }
};
int main(){

  char sim;
  int nodo = 0;
  map<string, nodo> ma;
  while(cin >> sim && sim != '.'){
    int 
    if(sim == '!'){
      int a,b,c;
      string x,y;
      cin >> a >> x >> c >> b >> y;
      ma[x] = nodo; nodo++;



    }
    else{

    }

  }

}





