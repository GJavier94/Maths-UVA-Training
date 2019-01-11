#include <bits/stdc++.h>
using namespace std;
int main(){

	long long x1,y1,x,y;
	while( cin >> x1 >> y1  && x1 && y1){
		if(y1 < x1) x = y1, y = x1;
		else x = x1, y = y1;
		long long max = 0;
		long long value = 0;
		for(long long i = x; i <= y; i++){
			long long n = i;
			long long sum = 0;
			if( i == 1) max = 4,  value = i;
			else{
				while(n != 1){
					if(n&1) n = 3*n + 1;
					else n = n/2;
					sum++;
				}
				sum++;
				if(max < sum) max = sum, value = i;				
			}
		}
		
		printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",x,y,value,--max );
	}
}