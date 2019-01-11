#include <bits/stdc++.h>

using namespace std;

int mod ( int n ){
	int result;
	return result = ((n % 4) + 4 )% 4;
}
int main ( ){

	int cases;
	cin >> cases;
	string line;
	cin.ignore();

	while(cases-- ){		
		int m,n;
		cin >> m >> n;
		
		char map[m][n];
		cin.ignore();
		for( int i = 0; i < m; i++){
			getline(cin, line);
			for( int j = 0; j  < n ; j++){
				map[i][j] = line[j];
			}
		}

		int x,y;
		cin >> x >> y;	
		--x,--y;	
		char orientacion[4] = {'N','E' ,'S' ,'W'};
		int orien[4][2] = {{-1,0} , {0,1}, {1,0} , {0,-1} };
		int ori = 0;
		cin.ignore();
		while(getline(cin, line ) && line != "" ){
			cout << line << endl;
			for( int i = 0; i < line.size(); i++){
				
				if(line[i] == 'R') ori = mod(++ori);
				else if(line[i] == 'L') ori = mod(--ori);
				else if(line[i] == 'F'){
					if( map[x + orien[ori][0] ][ y + orien[ori][1] ] != '*' ){
						x += orien[ori][0];
						y += orien[ori][1];						
					}
				} 
				else if(line[i] == 'Q'){
					cout << x << " " << y << " " << orientacion[ori] << endl;
					break;
				}
				else{}
				cout <<  x << " " << y << endl;
			}
		}

	}

}