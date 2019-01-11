#include <bits/stdc++.h>

using namespace std;

int main ( ){

	int cases;cin >> cases;
	int m,n;
	while(cases--){
		cin >> n >> m;
		if(!( (n-1)%(m-1) )) printf("%d\n",(int) ( (n-1)/(m-1)  ));
		else printf("cannot do this\n");
	}
}