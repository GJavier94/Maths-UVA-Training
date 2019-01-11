#include <bits/stdc++.h>

using namespace std;

#define M 34943

int  exp_mod(int b, int p, int  m ){
	int ans = 1;	
	while (p) {
		if (p & 1) ans = (ans * b) % m;
		b = (b * b) % m;
		p >>= 1;
	}
	return ans;
}

int main(){
	string line;
	while( getline(cin,line) ){
		if(line.size() == 1)if(line[0] == '#')return 0;
		int pot = 2, ans = 0 ;
		for(int i = line.size() - 1; i >= 0; i--,pot++ ){
			ans = (ans +  (line[i] * exp_mod_2(256,pot,M))%M)%M;
		}
		ans = (M - ans)% M;
		int a1 = ans&255;
		int a2 = (ans>>8)&255;
		printf("%.2X %.2X\n",a2,a1);				
	}
}