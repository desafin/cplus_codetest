#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  stack<int> s;
  vector<char> result;

  int num;
  cin >> num;

  int cnt = 1;
  bool possible = true;

  for (int i = 0; i < num; i++) {
    int x;
    cin >> x;

    while(cnt<=x)
    {
      s.push(cnt);
      cnt++;
      result.push_back('+');
    }
    if(s.top()==x)
    {
      s.pop();
      result.push_back('-');
    }
    else
    {
      possible = false;
      break;
    }
  }

  if (possible) {
    for (int i = 0; i < result.size(); i++) {
      cout << result[i] << "\n";
    }
  } else {
    cout << "NO";
  }

  return 0;
}