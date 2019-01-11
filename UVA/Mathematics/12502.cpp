#include <bits/stdc++.h>

using namespace std;
#define FOR(i,a,b) for( int i = a; i < b; i++)
int main(){

	int T,x,y,monto; cin >> T;

	FOR(k,1,T+1){
		cin >> x >> y >> monto;
		int asig = (x + y) / 3;
		int x1 = abs(asig - x);
		int y1 = abs(asig - y);
		int real = x1 + y1;
		printf("%d\n",(int)round(    ((double)(monto*x1)/(double)real )  ) );
	}
}