#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int year;
	cin>>year;
	bool result = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
	if (result)
	{
		cout << 1 << endl;
	}
	else
	{
		cout << 0 << endl;
	}
	return 0;
}