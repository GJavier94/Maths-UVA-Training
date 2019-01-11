#include <bits/stdc++.h>

using namespace std;

int main(){
	long long s,d;
	while( cin >> s >> d ){
		long long i = s, sum = 0;
		while(true){
			sum += i;
			if( sum >=  d){
				printf("%lld\n",i );
				break;
			}
			i++;
		}

	}
}	