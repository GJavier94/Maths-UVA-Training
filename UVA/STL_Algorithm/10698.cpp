#include <bits/stdc++.h>

using namespace std;

struct Team
{
	int pos, gamesPlayed,totpts, glSc, glSuff ;
	string name;

	void init(){
		pos =  gamesPlayed = totpts =  glSc =  glSuff  = 0 ;
		name = "";
	}

	void actualiza(int g1, int g2){	
		gamesPlayed++;
		glSc += g1;
		glSuff += g2;
		if(g1 > g2) totpts += 3;
		else if ( g1 ==g2 ) totpts +=1;
		else{}
	}
};

bool myfn ( Team t1 , Team t2){
	if( t1.totpts != t2.totpts ) return  t1.totpts > t2.totpts;
	if( (t1.glSc - t1.glSuff) != ( t2.glSc - t2.glSuff) ) return (t1.glSc - t1.glSuff) > ( t2.glSc - t2.glSuff) ;
	if( t1.glSc != t2.glSc )  return  t1.glSc > t2.glSc;

	transform(t1.name.begin(), t1.name.end(), t1.name.begin(), ::tolower);
	transform(t2.name.begin(), t2.name.end(), t2.name.begin(), ::tolower);
	return (t1.name).compare( t2.name) < 0;
}

int main ( ){
	int t, g;
	bool flag = true;
	while( cin >> t >> g ){
		if (t == 0 && g == 0) break;
        if(flag) flag = false;
        else cout << endl;
        
		vector<Team> teams(t);
		map<string, int > ma;
		for( int i = 0; i < t ; i++){
			Team t; t.init();
			cin >> t.name;
			teams[i] = t;
			ma[t.name] = i;
		}
		
		string t1, t2, g1,g2, comodin;
		for( int i = 0 ; i < g; i++){
			cin >> t1 >> g1 >> comodin >> g2 >> t2;
			string::size_type sz;
  			int g11 = stoi (g1,&sz);
  			int g22 = stoi(g2,&sz);
			teams[ ma[t1] ].actualiza(g11,g22);
			teams[ ma[t2] ].actualiza(g22,g11);
		}
		sort( teams.begin(), teams.end(), myfn);

		for( int i = 0; i < t ; i++){
			Team t = teams[i];
			int rank = 0;
			if (i == 0){
				rank = i + 1;
                printf("%2d. ", rank);
			}else if ( teams[i].totpts != teams[i-1].totpts || (teams[i].glSc - teams[i].glSuff ) != (teams[i-1].glSc - teams[i-1].glSuff )|| teams[i].glSc != teams[i-1].glSc) {
                rank = i + 1;
                printf("%2d. ", rank);
            } else {
                printf("    ");			 
            }

            printf("%15s %3d %3d %3d %3d %3d ", t.name.c_str(), t.totpts, t.gamesPlayed, t.glSc, t.glSuff, t.glSc - t.glSuff);

            if (t.gamesPlayed == 0) printf("%6s\n", "N/A");
            else printf("%6.2f\n", t.totpts * 100.0 / (3.0 * t.gamesPlayed) + 1e-9);
		}
		
	}
}