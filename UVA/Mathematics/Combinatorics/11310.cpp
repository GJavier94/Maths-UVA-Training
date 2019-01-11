/*
	problema de combinatoria 
	encontrar el patron 
	a[i-1] aporta todo a a[i]
	a[i-2] aporta por 4
	y a[i-3 ] aporta por 2

*/


#include <bits/stdc++.h>

using namespace std;

#define SIZE 41
typedef long long ll;
ll a[SIZE];
void precalc(){
	a[0] = 1;
	a[1] = 1;
	a[2] = 5;
	for(int i = 3; i <SIZE; i++) a[i] = a[i - 1] + 4*a[i -2] + 2*a[i-3];

}
int main(){
	precalc();
	int cases; cin >> cases;
	while(cases--){
		int n; cin >> n;
		cout << a[n] <<"\n";
	}
}