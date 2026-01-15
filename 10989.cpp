#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int caseNum;
	cin>>caseNum;
	int count[10001] = {0}; 

    for (int i = 0; i < caseNum; i++) 
    {
        int num;
        cin >> num;
        count[num]++; 
    }

    for (int i = 1; i <= 10000; i++) 
    {
        for (int j = 0; j < count[i]; j++) 
        {
            cout << i << "\n";
        }
    }
}