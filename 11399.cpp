#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v;
	int casenum;
	cin>>casenum;
	for(int i=0;i<casenum;i++)
	{
		int num;
		cin>>num;
		v.push_back(num);
	}
	int submin =0;
	int totalmin =0;
	sort(v.begin(),v.end());
	{
		for(int i =0 ;i<v.size();i++)
		{
			submin+=v[i];
			totalmin+=submin;
		}
	}
	cout<<totalmin;
	return 0;
}