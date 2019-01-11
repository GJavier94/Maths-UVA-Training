#include <bits/stdc++.h>
#define max 85

using namespace std;

char mat[max][max],ch;
int color[max][max],R,C;

#define FOR(i,a,b) for(int i = a; i < b; i++)

int dr[] = {1,0,-1,0};
int dc[] = {0,1,0,-1};

void dfs(int i,int j){
	if(mat[i][j]=='X') return ;
    if(color[i][j]!=0) return ;
    mat[i][j] = ch;
    color[i][j]=1;
    FOR(d,0,4) dfs(i + dr[d] ,j + dc[d]);    
}

int main(){
    int i,j,k,l,len;


    while(gets(mat[0])){
        i=1;
        memset(color,0, sizeof(color));
        while(gets(mat[i])){
            if(mat[i][0]=='_') break;
            i++;
        }
        R = i;

        FOR(i,0,R){
            for(j=0; mat[i][j]!='\0'; j++){
                if(mat[i][j]!='X' && mat[i][j]!=' ' && color[i][j] ==0){
                    ch = mat[i][j];
                    dfs(i,j);
                }
            }
        }
        for(i=0; i<=R; i++){            
            puts(mat[i]);
        }
        memset(mat,'\0',sizeof(mat));
    }
    return 0;
}