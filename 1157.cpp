#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  cin >> str;

  int count[26] = {
      0,
  };

  for (int i = 0; i < str.length(); i++) {
    int idx = 0;
    if (str[i] >= 97) {
      idx = str[i] - 97;
    } else {
      idx = str[i] - 65;
    }
    count[idx]++;
  }

  int max_cnt = -1;
  char result = '?';

  for (int i = 0; i < 26; i++) {
    if (count[i] > max_cnt) {
      max_cnt = count[i];
      result = i + 65;
    } else if (count[i] == max_cnt) {
      result = '?';
    }
  }
  cout << result << endl;
}