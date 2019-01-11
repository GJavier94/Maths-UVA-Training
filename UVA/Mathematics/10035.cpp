#include <bits/stdc++.h>
using namespace std;

int main ( ){
	long long int s1, s2;

	while(cin >> s1 >> s2 && ( s1 || s2)){
		int ac = 0, numAc = 0;

		while(s1 || s2){
			ac = ((s1%10) + (s2%10) + ac) / 10;
			s1 /= 10;
			s2 /= 10;
			numAc += ac;
		}
		if(!numAc) printf("No carry operation.\n");
		else if( numAc == 1) printf("1 carry operation.\n");
		else printf("%d carry operations.\n", numAc);
	}
}