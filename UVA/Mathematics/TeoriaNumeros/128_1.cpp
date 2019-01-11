/*
recuerda que si trabajas con corrimientos a niv l debit
usar tipos de dato unsigned
*/

#include <bits/stdc++.h>

using namespace std;

#define M 34943

int main(){
	char ch;
	unsigned int num = 0;
	while( (ch  = getchar()) && ch != '#') {
		if(ch ==	 '\n'){
			num = (num<<16)%M;
			num = (M - num)%M;
			printf("%02X %02X\n",num>>8, num&255 );
			num = 0;
		}else num = ((num<<8) +ch) % M;
	}

}