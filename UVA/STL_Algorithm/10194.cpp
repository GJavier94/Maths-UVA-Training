#include <bits/stdc++.h>

using namespace std;

struct Team{
	string name;
	int tpts, wins,ties,losses, goalScor, goalAgai;
	void init(){
		name = "";
		tpts = wins = ties = losses = goalScor = goalAgai = 0 ;				
	}
	void actualiza(int gF, int gC){
		if( gF > gC){
			tpts += 3; wins++;
		}else if (  gF < gC){
			losses++;
		}else{ // empate
			tpts += 1;ties++;
		}
		goalScor += gF;
		goalAgai += gC;
	}
};
bool myfunction( Team t1, Team t2){
	if( t1.tpts != t2.tpts ) return t1.tpts > t2.tpts;
	if( t1.wins != t2.wins ) return t1.wins > t2.wins;
	if( (t1.goalScor-t1.goalAgai) != (t2.goalScor-t2.goalAgai) )return (t1.goalScor-t1.goalAgai) > (t2.goalScor-t2.goalAgai);
	if( t1.goalScor != t2.goalScor )  return t1.goalScor > t2.goalScor;
	if( (t1.wins+t1.ties+t1.losses) != (t2.wins+t2.ties+t2.losses))	return  (t1.wins+t1.ties+t1.losses) < (t2.wins+t2.ties+t2.losses);

	transform(t1.name.begin(), t1.name.end(), t1.name.begin(), ::tolower);
	transform(t2.name.begin(), t2.name.end(), t2.name.begin(), ::tolower);
	return (t1.name).compare( t2.name) < 0 ;
}
int main(){

	int cases; cin >> cases;
	cin.ignore();
	while(cases--){		
		string input; getline(cin, input);
		cout <<  input << endl;
		int nt; 
		cin >> nt;
		cin.ignore();
		vector<Team> teams;
		map<string,int> m;

		for( int j = 0; j < nt; j++){
			string namet; getline( cin , namet ) ;			
			Team team;
			team.init();
			team.name = namet;
			m[namet] = j;
			teams.push_back(team);
		}
		string partido;
		int npart; cin >> npart;
		cin.ignore();
		for( int i = 0 ; i < npart; i++){
			getline(cin ,partido); partido += "#";
			int posI = 0, tam=0, posF;

			string team1, team2, n1,n2;
			tam = partido.find('#',posI);
			team1 = partido.substr(posI, tam);
			posI = tam + 1;
			posF = partido.find('@',posI);
			tam = posF - posI;
			n1  = partido.substr(posI,posF - posI);

			posI = posF + 1;
			posF = partido.find('#',posI);
			n2  = partido.substr(posI,posF - posI);

			posI = posF + 1;
			posF = partido.find('#',posI);
			team2  = partido.substr(posI,posF - posI);
		
  			string::size_type sz;
  			int n11 = stoi (n1,&sz);
  			int n22 = stoi(n2,&sz);
			teams[  m[team1] ].actualiza(n11 , n22);
			teams[  m[team2] ].actualiza(n22 , n11);
		}
		sort(teams.begin(), teams.end(), myfunction);
		for( int i = 0; i < teams.size();i++){
			Team t = teams[i];			
			int jugados = t.wins + t.ties + t.losses;
			int dif = t.goalScor - t.goalAgai;
			printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", 
				i+1, t.name.c_str(), t.tpts,  jugados, t.wins, t.ties, t.losses, dif, t.goalScor, t.goalAgai
			);				
		}		
		if ( cases != 0) cout << endl;
	}
}