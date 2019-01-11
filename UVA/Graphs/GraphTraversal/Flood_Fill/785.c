#include <bits/stdc++.h>

char matrix[30 + 5][80 + 5];

int dr[] = {1,0,-1,0};
int dc[] = {0,1,0,-1};

#define FOR(i,a,b) for( int i = a; i < b; i++)

bool isValid(int x, int y ){
    if(matrix[x][y] == mark || matrix[x][y] == 'X')
    return true;
}

void dfs(int x, int y ){

    FOR(i,0,4){
        int nx = x + dr[i];
        int ny = y + dc[i];
        if(isValid(nx,ny)){
            matrix[nx][ny] = mark;
            dfs(nx, ny);
        }
    }
}


int main (){
    
    while(gets(matrix[0])){
        int ind = 1;

        while(gets(matrix[ind])){
            if(matrix[ind][0] == ' ') break;
            ind++;
        }

        FOR(i,0,ind){
            FOR(j,0,strlen(matrix[i])){
                if(matrix[i][j] != ' ' && matrix[i][j] != 'X'){
                    char mark = matrix[i][j];
                    matrix[i][j] = ' ';
                    dfs(i,j,mark);
                    matrix[i][j] = mark;
                }
            }
        }


    }
}