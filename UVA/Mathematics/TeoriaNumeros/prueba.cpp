#include <bits/stdc++.h>

using namespace std;

int main(){
	string num;
	getline(cin, num);	
	sort(num.begin(), num.end());
	string ini = num;
	string fin;
	do{        
		fin = num;		
    }while(next_permutation(num.begin(), num.end()));
	cout << ini << " " << fin << endl;
}