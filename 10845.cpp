#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int cmdNum;
  cin >> cmdNum;
  queue<int> q1;
  for (int i = 0; i < cmdNum; i++) {
    string cmdStr;
    cin >> cmdStr;
    if (cmdStr == "push") {
      int num;
      cin >> num;
      q1.push(num);
    } else if (cmdStr == "pop") {
      if (q1.empty()) {
        cout << -1 << "\n";

      } else {
        int num;
        num = q1.front();
        q1.pop();
        cout << num << "\n";
      }
    } else if (cmdStr == "size") {
      int num;
      num = q1.size();
      cout << num << "\n";

    } else if (cmdStr == "empty") {
      if (q1.empty()) {
        cout << 1 << "\n";
      } else {
        cout << 0 << "\n";
      }

    } else if (cmdStr == "front") {
      if (q1.empty()) {
        cout << -1 << "\n";
      } else {
        cout << q1.front() << "\n";
      }

    } else if (cmdStr == "back") {
      if (q1.empty()) {
        cout << -1 << "\n";
      } else {
        cout << q1.back() << "\n";
      }
    }
  }
}
