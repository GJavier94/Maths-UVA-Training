#include <bits/stdc++.h>

using namespace std;

int main(){
	string  in = "1234";

	string::size_type sz;

	int i_dec = stoi(in, &sz);
	i_dec++;
	cout << i_dec  << endl;
}