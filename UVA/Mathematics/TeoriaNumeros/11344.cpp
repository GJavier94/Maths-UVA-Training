#include <bits/stdc++.h>

using namespace std;

int main(){
	string M;
	int cases; cin >> cases;

	while(cases--){
		cin.ignore();
		getline(cin, M);
		int num; cin >> num;
		bool flag = true;
		for(int i = 0; i < num ; i++){
			int x; cin >> x;
			int y = 0;
			if(flag)
			for(int j = 0; j < M.size(); j++){
				y = y*10 + (M[j] - '0');
				y %= x;
			}
			if(y)flag = false;
		}	
		cout << M;		
		printf(" - ");
		if(flag)printf("Wonderful.\n");
		else printf("Simple.\n");
	}
}