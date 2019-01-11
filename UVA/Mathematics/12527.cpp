#include <bits/stdc++.h>
using namespace std;
bool check( int n){
	int a1, a2;
	int nums[10];	
	memset(nums, 0, sizeof(nums));
	while( n != 0){		
		a2 = n - ( ( (int)n/10) *10 );
		n /= 10;
		if(!nums[a2])  nums[a2]++;
		else return false;
	}
	return true;
}
int main(){
	int n,m;
	while( cin >> n >> m ){
		int cont = 0;
		for(int i = n; i <= m; i++ ){
			if(check(i)) cont++;
		}
		cout << cont << endl;
	}	
}