/*
	simpre que divida dos enteros y lo asigne a un double 
	hay qu castearlo	
*/ 
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
vi num, den;
int gcd(int a, int b ){ return b == 0 ? a : gcd(b, a % b);}
bool myfn(int i, int j){
	double f1, f2;
	f1 = (double)num[i] / den[i];
	f2 = (double)num[j] / den[j];	
	if(f1 < f2 ) return true;
	return false;
}
int main(){
	int n, k;
	while(cin >> n >> k ){
		num.clear();
		den.clear();
		for(int i = 1; i <= n ; i++){
			for(int j = 1; j <= i ; j++){
				if(gcd(i,j) == 1 ){
					num.push_back(j);
					den.push_back(i);
				}
			}
		}
		vi ind(num.size());
		for(int i = 0; i < num.size(); i++) ind[i] = i;
		sort(ind.begin(), ind.end(), myfn);		
		printf("%d/%d\n", num[ ind[k -1]] , den[ ind[k-1] ] );
	}
}