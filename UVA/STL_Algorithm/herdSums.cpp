#include <bits/stdc++.h>

using namespace std;

int main ( ){

	int n ;
	cin >> n;
	int i = 1 , j = 0 ;
	int sum = 0;
	int contador = 0;
	while ( j != n ){
		if( sum <= n ){			
			if( sum == n ){				
				contador++;
			}
			j++;
			sum += j ;			
		}else{
			sum -= i;
			i++;
		}
	}
	contador++;
	cout << contador << endl;
}