//18:01
#include <bits/stdc++.h>

using namespace std;

struct Team{
	int number;
	int problemsSolved;
	int totalTime;

	int problems[7];
	int tried[7];

	void init ( ){
		number = 0;
		problemsSolved = 0 ;
		totalTime  = 0 ;

		memset(problems,0,7);
		memset(tried,0,7);
	}
};

int convierteTiempo (string tiempo ){
	int t;
	int  hours, minutes;
	sscanf(tiempo.c_str(),"%d:%d",&hours, &minutes);
	t = hours*60 + minutes;
	return t;
}

bool myfn( Team t1 , Team t2){
	if ( t1.problemsSolved  !=  t2.problemsSolved )  return t1.problemsSolved  >  t2.problemsSolved;
	
	if( t1.totalTime != t2.totalTime ) return t1.totalTime < t2.totalTime;

	return t1.number < t2.number;

}
int main ( ){

	int  cases;
	cin >> cases;
	cin.ignore();
	string cad;
	getline(cin,cad);

	while( cases--){

		int number, t;
		char problem, status;
		string tiempo;

		vector<Team> teams;
		map<char, int>  p;
		p['A'] = 0;
		p['B'] = 1;
		p['C'] = 2;
		p['D'] = 3;
		p['E'] = 4;
		p['F'] = 5;
		p['G'] = 6;

		map<int, int> exist;

		while( getline( cin, cad) && cad.size() != 0 ){
			stringstream ss(cad);
			ss >> number >> problem >> tiempo >> status;
			//cout << number <<" " << problem <<" " << tiempo <<" " << status << endl;
			cout << cad << endl;
			
			number--;
			if( exist[number] == 0 ){
				Team t; t.init(); t.number = number + 1;
				teams.push_back(t);
				exist[number] =  1;
			}

			int numProblem  = p[problem];
			if( teams[ number].problems[ numProblem ] == 0 ){
				if( status == 'N'){
					teams[ number ].tried[ numProblem ]++;
				}else{
					teams[number].problems[numProblem] = 1;
					teams[number].problemsSolved++;
					t = convierteTiempo (tiempo ) + teams[ number ].tried[ numProblem ]*20;
					teams[number].totalTime += t;
				}
			}	
		}
		
		sort( teams.begin( ), teams.end(), myfn);

		cout << "RANK TEAM PRO/SOLVED TIME" << endl;
		int rank = 1;
		for (int i = 0; i < teams.size(); i++){
			Team t  = teams[i];		
			if ( i == 0 )
				printf("%4d %4d",1,t.number); 

			else {
				if ( teams[i].problemsSolved != teams[i - 1].problemsSolved  || teams[i].totalTime != teams[i - 1].totalTime )
					rank++;
				printf("%4d %4d",rank,t.number); 
			}
			
			if( t.problemsSolved)
				 printf("    %-7d %4d\n",t.problemsSolved ,t.totalTime);
			else cout << endl;
		}

	}

	
}
