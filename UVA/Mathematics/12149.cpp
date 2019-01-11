#include <bits/stdc++.h>

using namespace std;

int main (){
	int n;
	while(cin >> n && n){
		if(n == 1) {cout << "1" << endl; continue;}
		int square = n*n;
		int i = 1;		
		int suma = 0;
		while(i*i != square){
			suma += i*i;
			i++;
		}
		suma += i*i;
		cout << suma << endl;
	}
}