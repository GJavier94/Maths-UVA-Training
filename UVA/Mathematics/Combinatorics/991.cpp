#include <bits/stdc++.h>

using namespace std;
#define SIZE 11
int a[SIZE];
void precalc(){
	a[0] = 1;
	for(int i = 1; i < SIZE; i++){
		a[i] = (4*i - 2)*a[i - 1];
		a[i] /= (i + 1);
	}
}
int main(){
	precalc();
	int n;
	bool flag = true;
	while(cin >> n ){
		if(flag) flag = false;
		else cout <<"\n";
		cout << a[n] << "\n";
	}
}