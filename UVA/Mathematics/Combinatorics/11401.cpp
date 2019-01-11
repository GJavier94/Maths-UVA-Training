/*
Encontrar el patron es de lo mas dificil 

3 0 
4 1
5 3
6 7
7 13
8 22

donde 
0  =  0

1  =  0  + 1*1
3  =  1 + 1*2
7  =  3 + 2*2
13    7 + 2*3
22    13 + 3*3
...    22 + 3*4

es geometrica 

*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define SIZE 1000001
ll a[SIZE];

void precalc(){
	a[0] = a[1] = a[2] = a[3] = 0;
	ll m = 0;
	for(int i = 4; i < SIZE; i++){
		if(i&1)
			a[i] = a[i - 1] + m*(m+1);
		else{
			m++;
			a[i] = a[i-1] + m*m;
		}				
	}
}

int main(){
	precalc();	
	int n;
	while(cin >> n && n > 2 ){
		cout << a[n] <<"\n";
	}
}