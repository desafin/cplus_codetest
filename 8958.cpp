#include <bits/stdc++.h>
using namespace std;

int main() {
  int caseNum;
  cin >> caseNum;
  for (int i = 0; i < caseNum; i++) {
    int score = 1;
    int sum = 0;
    string result;
    cin >> result;
    for (int j = 0; j < result.length(); j++) {
      if (result[j] == 'O') {
        sum += score;
        score++;
        // cout << sum << endl;
      } else if (result[j] == 'X') {
        score = 1;
      }
    }
    cout << sum << endl;
  }
  return 0;
}