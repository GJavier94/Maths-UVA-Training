/*
Tiene que estar en  c++ 11
g++ 11955.cpp -std=c++11
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define SIZE 51
ll a[SIZE][SIZE];

int parseInt(string sn){
	std::string::size_type sz;
	return std::stoi(sn,&sz);
}

void pascal(){
	memset(a, 0, sizeof(ll)*SIZE*SIZE);
	for(int i = 0 ; i < SIZE; i++){ a[i][0] = 1;
		for(int j = 1; j <= i; j++) a[i][j] = a[i-1][j-1] + a[i -1][j];			
	}
}
int main(){
	pascal();
	int cases, k = 0;
	cin >> cases;
	cin.ignore();
	while(cases--){
		k++; printf("Case %d: ", k);
		char c; string op1 = "", op2 = "", cad, sn;
		int i = 1;
		getline(cin,  cad);

		while(cad[i] != '+'){op1 += cad[i]; i++;} 
		i++;
		while(cad[i] != ')'){op2 += cad[i];i++;}
		i++;i++;
		while(cad[i]){sn += cad[i]; i++;}
		int n, k, pot1, pot2;		
		n = parseInt(sn);

		for(k = 0; k <= n ; k++){
			if(k)cout << "+";			
			if(a[n][k] > 1) cout << a[n][k] << "*";
			pot1 = n - k;
			pot2 = k;
			if(pot1 == 1) cout << op1;
			if(pot1 > 1) cout << op1 << "^" << pot1;
			if(pot1 && pot2) cout << "*";
			if(pot2 == 1) cout << op2;
			if(pot2 > 1) cout << op2 << "^" << pot2;
		}
		cout <<"\n";
	}
}


