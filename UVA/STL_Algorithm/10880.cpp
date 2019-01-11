#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int t;
  int c, r;
  set<int> div;
  set<int> :: iterator it ;

  cin >> t;

  for (int casenum = 0; casenum < t; casenum++) {
    cin >> c >> r;

    div.clear();

    cout << "Case #" << casenum+1 << ":";

    if (c == r) {
      cout << " 0" << endl;
      continue;
    }

    int tmp = c - r;

    for (int i = 1, sq = sqrt(tmp); i <= sq; i++) {
      if (tmp % i == 0) {
        if (i > r)
          div.insert(i);

        if ( (tmp/i) > r)
           div.insert(tmp/i);
      }
    }

    for ( it = div.begin(); it != div.end(); it++)
      cout << " " << *it;
    cout << endl;
  }

  return 0;
}