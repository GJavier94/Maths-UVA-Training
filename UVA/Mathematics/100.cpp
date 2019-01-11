#include <bits/stdc++.h>

using namespace std;

int main(){

	long long x1,y1,x,y;
	while( cin >> x1 >> y1 ){
		if(y1 < x1) x = y1, y = x1;
		else x = x1, y = y1;
		long long max = 0;
		for(long long i = x; i <= y; i++){
			long long n = i;
			long long sum = 1;			
			while(n != 1){
				if(n&1) n = 3*n + 1;
				else n = n/2;
				sum++;
			}
			if(max < sum) max = sum;
		}
		printf("%lld %lld %lld\n",x1,y1,max );
	}
}