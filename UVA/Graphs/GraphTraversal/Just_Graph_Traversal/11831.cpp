#include <bits/stdc++.h>

using namespace std;
int mod ( int n ){
	int result;
	return result = ((n % 4) + 4 )% 4;
}
int main(){


	int n, m, s;

	while( cin >> n >> m >> s){
		if( n  == 0 && m == 0 && s == 0 ) break;
		char map[n][m];
		for(int i = 0; i < n; i++)
			cin >> map[i];	
		string in;
		cin >> in;
		int ori = 0;
		char orien[4] = {'N','L','S', 'O'};		
		int movs[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
		char *p;
		int x,y;
		for (int i = 0; i < n; i++){			
			for (int j = 0; j < m; j++){
				p = find( orien, orien + 4, map[i][j]);
				if(  p != orien + 4){					
					x = i; y = j; 
					ori = p- orien;					
				}
			}
		}
		int ns = 0;				

		for(int i = 0; i < in.size(); i++){			
			if( in[i] == 'D' ) ori = mod(++ori);
			else if( in[i] == 'E') ori = mod(--ori);
			else{ // si quiere moverse
				int nx = x + movs[ori][0];
				int ny = y + movs[ori][1];
				if( nx < 0 || ny < 0 ||
					nx >= n || ny >= m
				) continue;
				if( map[nx][ny] == '#') continue;
				if( map[nx][ny] == '*') ns++, map[nx][ny] = ' ';
				x = nx;
				y = ny;
			}
		}

		cout << ns << endl;	
	}
}