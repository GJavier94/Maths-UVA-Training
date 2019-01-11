#include <bits/stdc++.h>

using namespace std;

int dp[10000][10];

void precalcula(){
	int tn;
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i < 10000; i++){
		memcpy(dp[i], dp[i-1], 40);
		tn = i;
		while(tn) dp[i][tn%10]++, tn/=10;
	}
}

int main(){
	precalcula();
	int T, N, i;
	cin >> T;
	while(T--){
		cin >> N;
		for(i = 0; i < 9 ; i++){
			cout << dp[N][i] << " ";
		}
		cout << dp[N][i] << "\n";
	}
}