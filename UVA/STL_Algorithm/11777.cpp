#include <bits/stdc++.h>

using namespace std;

bool myfunction(int a , int b){
	return a > b ;
}

int main(){
	int cases;
	cin >> cases;
	for( int i = 0 ; i < cases ; i++){
		int t1, t2, final, attendance;
		vector<int> clas(3);
		cin >> t1 >> t2 >> final >> attendance >>  clas[0] >> clas[1] >> clas[2];
		sort(clas.begin(), clas.end(), myfunction);
		
		int sum  =   t1+ t2+ final+ attendance +  (int) ( (clas[0] + clas[1])/2.0 ) ;
		
		cout << "Case " << i + 1  << ": "; 
		if( sum >= 90 ) cout << "A" << endl;
		else if ( sum >= 80  && sum < 90) cout << "B" << endl;
		else if ( sum >= 70  && sum < 80) cout << "C" << endl;
		else if ( sum >= 60  && sum < 70) cout << "D" << endl;
		else cout << "F" << endl;

	}
}
