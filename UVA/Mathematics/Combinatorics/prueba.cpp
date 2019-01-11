//upperbound

// #include <bits/stdc++.h>
// using namespace std;

// typedef vector<int> vi;

// int main(){
// 	int r[] = {1,2,2,3,3,4,4,4,5,6,7,7,9,9,9};
// 	vi nums(r, r + 15 );
// 	vi :: iterator it;
// 	int elem; cin >> elem;
// 	it = upper_bound(nums.begin(), nums.end(), elem);
// 	int pos = it - nums.begin();
// 	cout << pos << " " << *it << endl;
	
// }

//lower_bound

/*
 Si quiero el intervarlo 
 [a , b] 
 lower_bound(a)  me da el a
 it = lower_bound(b + 1);it-- me da el b

*/

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main(){
	int r[] = {1,2,2,3,3,4,4,4,5,6,7,7,9,9,9};
	vi nums(r, r + 15 );
	vi :: iterator it;
	int a,b;

	while(cin >> a >> b && a && b){
		it = lower_bound(nums.begin(), nums.end(), a);
		int posA = it - nums.begin();
		it = lower_bound(nums.begin(), nums.end(), b + 1);
		int posB = --it - nums.begin();
		cout << posA << " " << posB << endl;
		
	}
	
}


