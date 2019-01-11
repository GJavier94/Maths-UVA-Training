#include <bits/stdc++.h>

using namespace std;

int main(){

	int cases; cin >> cases;

	while(cases--){
		int n; cin >> n; int av[n];
		memset(av,0, sizeof(av));
		int total = 0;
		for(int i = 0; i < n ; i++){
			cin >> av[i];
			total += av[i];			
		}

		int average = total/n;
		int sum = 0;
		for(int i = 0; i < n ; i++){
			if(av[i] > average) sum++;
		}

		printf("%.3lf%%\n",((double)sum/ (double)n)*100 );		 			
	}
}