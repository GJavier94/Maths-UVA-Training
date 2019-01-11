#include <bits/stdc++.h>

using namespace std;
int gcd( int a, int b){ return  b == 0 ? a : gcd(b, a % b);}

int main(){
	int m,n;

	while( cin >> m >>n ){

		if( gcd(m,n) == 1 )
			printf("%10d%10d    Good Choice\n", m,n);		
		else 
			printf("%10d%10d    Bad Choice\n", m,n);
		printf("\n");
	}
}