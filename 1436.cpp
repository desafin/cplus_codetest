#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int end_num, n, count = 1;
	string str;

	cin >> n;
	if (n == 1) {
		cout << 666;
	}
	else {
		end_num = 1665;
		while (n != count) {
			end_num++;
			str = to_string(end_num);
			
			if (str.find("666") != string::npos) {
				count++;
			}
		}
		cout << end_num;
	}	

	return 0;
}