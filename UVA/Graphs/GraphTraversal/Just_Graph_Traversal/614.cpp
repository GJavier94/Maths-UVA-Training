#include <bits/stdc++.h>

using namespace std;

int m,n;
int ix,iy;
int fx,fy;

typedef vector<int> fila;
typedef vector<fila> matriz;

struct Nodo{
	int x,y,lev;
};


bool findFinal = false;


void meteEnCola(stack<Nodo>& cola, Nodo n ){
	if(cola.empty()){cola.push(n);return ;}
	while( n.lev <= (cola.top()).lev ){
		cola.pop();
	}
	cola.push(n);
}

bool checaMov(int x , int y, int p, matriz &mapa){
	if( x < 0 || y < 0 || x >= m || y >= n )
        return false;
    if( mapa[x][y]&p)
    	return false;
    return true;

}
void dfs(int x, int y, int level, matriz &mapa, matriz &vis, stack<Nodo>& cola){
	if(findFinal) return;

	if( x < 0 || y < 0 || x >= m || y >= n ) return;
	if(vis[x][y] == -1) return;
	vis[x][y] = -1;
	meteEnCola(cola,Nodo{x,y,++level});
	
	if(x == fx && y == fy) findFinal = true;
	bool flag = true;
	// checar si me puedo mover para ese lado 
	//WEST
	if( checaMov (x, y-1, 1,mapa) )
		dfs(x, y-1, level, mapa, vis, cola);
	//North
	if( checaMov (x - 1, y, 2,mapa) )
		dfs(x-1, y, level, mapa, vis, cola);
	//East
	if( checaMov (x, y, 1,mapa) )
		dfs(x, y+1, level, mapa, vis, cola);
	//south
	if( checaMov (x, y, 2,mapa) )
		dfs(x +1, y, level, mapa, vis, cola);


}

int main (){
	int k = 0;
	while( cin >> m  >> n >> ix >> iy >> fx >> fy){
		k++;
		if(!( m || n || ix || iy || fx || fy )) break;
		stack<Nodo> cola;
		matriz mapa(m, fila(n));
		matriz vis(m, fila(n));
		--ix, --iy, --fx, --fy;
		findFinal = false;
		for(int i = 0; i < m; i++)
			for( int j = 0 ; j < n ; j++) cin >> mapa[i][j];
		dfs(ix, iy, 0, mapa, vis,cola); // la primera vez el nivel es de 0

		if(cola.top().x == fx && cola.top().y == fy )
		while(!cola.empty()){
			Nodo n  = cola.top(); cola.pop();		
			vis[n.x][n.y] = n.lev;
		}
		
		cout << "Maze " << k << endl<<endl;
		cout << "+";for( int j = 0; j < n ; j++){cout << "---+";} cout << endl;
		for( int i = 0; i < m; i++){
			cout << "|";
			for(int j = 0;  j < n; j++){
				if(vis[i][j] == -1) cout << "???";
				else if(!vis[i][j]) cout << "   ";
				else printf("%3d",vis[i][j] );
				if( j == n -1 || mapa[i][j] == 1 || mapa[i][j] == 3) cout << "|";
				else cout << " ";
			}
			puts("");
		cout << "+";
			for (int j = 0; j < n; j++){
				if( i == m - 1 || mapa[i][j] == 2 || mapa[i][j] == 3 ) cout << "---+";
				else cout << "   +";
			}
			puts("");
		}
		cout << endl << endl;
	}	
}