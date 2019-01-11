#include <bits/stdc++.h>

using namespace std;

int main(){
	char c;
	int number;
	while(cin >> c){
		number = c -'0';
		while(cin >> c && c != '#'){
			number = number << 1;
			number += c - '0';
			number = number % 131071;
		}
		if(number)printf("NO\n");
		else printf("YES\n");
	}

}


