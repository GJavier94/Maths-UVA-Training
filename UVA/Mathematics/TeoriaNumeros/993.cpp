#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){

	int cases; cin >> cases;
	int n;
	while(cases--){
		cin >> n;
		if(n == 1){printf("1\n"); continue;}
		if(n == 0){printf("0\n"); continue;}
		string line = "";
		for(int i = 9; i >= 2; i--)
			if(n % i == 0){
				n /= i;
				line += i + '0';				
			}

		if(n != 1) printf("-1\n");
		else{
			for(int i = line.size() - 1; i >= 0; i--)
				cout << line[i];
			printf("\n");			
		}
	}	

}