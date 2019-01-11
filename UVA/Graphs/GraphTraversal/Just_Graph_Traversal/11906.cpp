#include <bits/stdc++.h>
using namespace std;
 
int r, c, m, n, w;
int mat [100 + 2] [100 + 2];
 
void print (int r, int c) {
 
    for ( int i = 0; i < r; i++ ) {
        for ( int j = 0; j < c; j++ ) {
            printf (" %d ", mat [i] [j]);
        }
        printf ("\n");
    }
 
    printf ("\n\n");
}
 
int main ()
{
    int testCases; scanf ("%d", &testCases);
    int cases = 0;
 
    while ( testCases-- ) {
 
        for( int i = 0;i < 102 ;i++){
            for (int j = 0; j < 102; j++)
            {
                mat[i][j] = 0;
            }
        }
         
        scanf ("%d %d %d %d", &r, &c, &m, &n);
        scanf ("%d", &w);
 
        map < pair<int, int>, bool > waterMap;
 
        for ( int i = 0; i < w; i++ ) {
            int a, b; scanf ("%d %d", &a, &b);
            waterMap [make_pair(a, b)] = true;
        }
         
        queue <pair<int, int> > q;
        q.push(make_pair(0, 0));
 
        map <pair<int, int>, bool> visited;
        visited [make_pair(0, 0)] = true;
 
        mat [0] [0] = 0;
         
        int dr [] = {-m, -m, m, m, -n, n, -n, n};
        int dc [] = {n, -n, n, -n, m, m, -m, -m};
 
        while (!q.empty()) {
            pair<int, int> pop = q.front (); q.pop();
 
            int newX, newY;
            set<pair<int, int> > distinct;
 
            for ( int i = 0; i < 8; i++ ) {
                newX = dr [i] + pop.first;
                newY = dc [i] + pop.second;
 
                distinct.insert(make_pair(newX, newY));
            }
 
            for (set<pair<int, int> >::iterator it = distinct.begin(); it != distinct.end(); it++ ) {
                pop = *it;
                newX = pop.first;
                newY = pop.second;
                 
                if ( newX >= 0 && newX < r && newY >= 0 && newY < c && !waterMap [make_pair(newX, newY)]) {
                    mat [newX] [newY]++;
 
                    if ( !visited [make_pair(newX, newY)] ) {
                        visited [make_pair(newX, newY)] = true;
                        q.push(make_pair(newX, newY));
                    }
                     
 
                }
            }
 
            print (r, c);
        }
 
        int cntEven = 0, cntOdd = 0;
 
        for ( int i = 0; i < r; i++ ) {
            for ( int j = 0; j < c; j++ ) {
                if ( mat [i] [j] || ( !i && !j ) ) {
                    if ( mat [i] [j] % 2 ) cntOdd++;
                    else cntEven++;
                }
            }
        }
 
         printf ("Case %d: %d %d\n", ++cases, cntEven, cntOdd);
    }
 
    return 0;
}