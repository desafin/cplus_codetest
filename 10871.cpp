#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int num;
	int cnt;
	int n;
	vector<int> v;

	cin>>cnt;
	cin>>num;
	for(int i=0;i<cnt;i++)
	{
		cin>>n;
		v.push_back(n);
	}
	// sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++)
	{
		if(v[i]<num)
		{
			cout<<v[i]<<" ";
		}
	}
	return 0;
}