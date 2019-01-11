#include <bits/stdc++.h>

using namespace std;
typedef vector<char> vc;
typedef vector<vc> vcc;
typedef vector<int> vi;
typedef vector<vi> vii;

#define FOR(i,a,b) for(int i = a; i < b; i++)

int m, n;
int ind;

int dr[] = {1,1,0,-1,-1,-1, 0, 1};
int dc[] = {0,1,1, 1, 0,-1,-1,-1};
void floodFill(vcc& mapa, vii& vis, int i, int  j, char c1, int label){
	if( i < 0 || j < 0 || i >= m || j >= n) return;
	if(mapa[i][j] != c1) return;
	if(vis[i][j]) return;
	vis[i][j] = label;

	FOR(d,0,8) floodFill(mapa, vis, i + dr[d], j + dc[d] , c1, label);
	return;
}
int main(){
	string row;

	while(getline(cin,row)){
		vcc mapa(105,vc(105));
		vii vis(105,vi(105));
		m = n = 0;
		int pos = 0;
		FOR(i,0,row.size()) if(row[i] != ' ') mapa[m][pos++] = row[i];		
		m++;

		while(getline(cin, row) && row[0] != '%'){			
			pos = 0;			
			FOR(i,0,row.size()) if(row[i] != ' ') mapa[m][pos++] = row[i];
			n = pos;
			m++;
		}
				

		ind = 0;
		FOR(i,0,m){
			FOR(j,0,n){
				if(!vis[i][j]){					
					ind++;
					floodFill(mapa,vis, i, j, mapa[i][j], ind);
				}			
			}
		}
		
		int align[105] = {}, i, j;
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                int tmp = vis[j][i], cnt = 0;
                while(tmp)
                    tmp = tmp/10, cnt++;
                if(align[i] < cnt)
                    align[i] = cnt;
            }
        }
        char format[50] = "%?d";
        for(i = 0; i < m; i++, puts("")) {
            for(j = 0; j < n; j++) {
                format[1] = align[j]+'0';
                if(j)
                    putchar(' ');
                printf(format, vis[i][j]);
            }
        }
        puts("%");
	}
}