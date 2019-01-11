#include <bits/stdc++.h>

using namespace std;

int main (){
	string tiempo = "1:50";
	int hours,minutes;

	sscanf(tiempo.c_str(), "%d:%d", &hours, &minutes);

	cout << hours << " " << minutes << endl;

}