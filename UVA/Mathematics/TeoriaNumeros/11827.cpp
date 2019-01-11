#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

int gcd(int a, int b){ return b == 0 ? a : gcd(b, a % b);}

int main(){
	int cases; cin >> cases;
	cin.ignore();
	string line;
	while(cases--){
		getline(cin, line);
		stringstream ss(line);

		vi v(100);
		int pos = 0;
		while( ss >> v[pos]) pos++; // se queda con el numero de elmentos
		int gMax = 0, g;
		for(int i = 0; i < pos; i++)
			for(int j = i + 1; j < pos; j++){
				g = gcd(v[i], v[j]);
				if( gMax < g) gMax = g;
			}

		printf("%d\n", gMax);
		
	}
}