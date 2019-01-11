#include <bits/stdc++.h>
using namespace std;
bool check(int n){
	while(n != 0){
		if(n%10 == 7) return true;
		n /= 10;
	}
	return false;
}

int main(){	
	int n,m, k;
	while( cin >> n >> m >> k && ( m || n || k)){
		int v[n];
		memset(v,0, sizeof(v));
		int flag = 1;
		int clap = 1;
		int i = 0;
		while(1){
			if(!i)flag = 1;
			if(i == n - 1)flag = 0;			

			if(!(clap%7)||check(clap)) v[i]++;

			if(v[m - 1] == k) {printf("%d\n",clap); break;}
			clap++;
			if(flag) i++;
			else i--;
		}
	}
}