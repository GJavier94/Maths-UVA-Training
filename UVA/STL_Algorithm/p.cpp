#include <bits/stdc++.h>

using namespace std;

int getMax( string a){
	int max = 0;
	int aux;
	for (int i = 0; i < a.size() - 1; i++){
		aux = abs( a[i] - a[i+1]);
		if( max < aux ) max = aux;
	}
	return max;
}
int main ( ){

	string input;
	cin >> input ;

	pair<string, int > result;
	result.first  = " ";
	result.second  = 0  ;
	string a  = input;
	int value = 0 ;
	for( int  i  = 0  ; i < 10; i++){
		prev_permutation ( a.begin(), a.end());
		if(getMax(a) > result.second ){
			result.first = a;
			result.second  = getMax(a);
		}
	}
	a = input ;
	for( int  i  = 0  ; i < 10; i++){
		next_permutation ( a.begin(), a.end());
		if(getMax(a) > result.second ){
			result.first = a;
			result.second  = getMax(a);
		}
	}
	cout << result.first << result.second;
}