#include <bits/stdc++.h>
using namespace std;

int main(){
	int t,n,b,k,a,ans,res;
	cin >> t;
	while(t--){
		cin >> n >> b;
		ans = 0;
		while(b--){
			res = 1;
			cin >> k ;
			while(cin >> k ){
				cin >> a;
				res *=a; res%=n;
			}
			ans+=res; ans %=n;
		}
		cout << ans << endl;
	}
}