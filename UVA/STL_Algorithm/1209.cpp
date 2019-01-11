#include <bits/stdc++.h>

using namespace std;

int getMax(string a){
	int max = 0, aux;
	for( int  i = 0 ; i <  a.size() -1; i++){
		aux = abs( a[i+1] - a[i]);
		if( max < aux)
			max = aux;
	}	
	return max;
}

int main ( ){

	string input;
	cin >> input;

	pair<string,int> result1;
	pair<string,int> result2;
	///string -> cadena
	// int --> value de abs max 

	// recorremo hacia atras
	string a = input ;
	
	result1.first = a;
	result1.second = 0 ;

	for( int i = 0 ;i < 9; i++){
		prev_permutation(a.begin(), a.end());
		if( result1.second < getMax(a)){
			result1.first = a;
			result1.second = getMax(a);			
		}
		
	}
	a = input ;
	result2.first = a;
	result2.second = 0;		

	for( int i = 0 ;i < 9; i++){
		next_permutation(a.begin(), a.end());
		if( result2.second < getMax(a)){
			result2.first = a;
			result2.second = getMax(a);			
		}
		
	}
	
	if( result1.second >= result2.second ){
		cout << result1.first << result1.second << endl;
	}else{
		cout << result2.first << result2.second << endl;
	}

}





