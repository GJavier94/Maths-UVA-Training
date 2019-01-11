#include <bits/stdc++.h>

using namespace std;

int main(){
	
	long long a,b,c,d,L;

	while( cin >> a >> b >> c >> d >> L
		&& ( a || b || c || d || L)){
		long long fx, cont = 0;
		for(int x = 0 ; x <= L; x++){
			fx = a*x*x + b*x + c;
			if(! ( fx%d )  ) cont++;
		}
		cout << cont << endl;
	}
}