#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int casenum;
	cin>>casenum;
	vector<int> v;
	for (int i=0;i<casenum;i++)
	{
		string cmd;
		cin>>cmd;
		if(cmd=="add")
		{
			int num;
			cin>>num;
			auto result = find(v.begin(),v.end(),num);
			if(result==v.end())
			{
				v.push_back(num);
			}
			else
			{
			}

		}
		else if(cmd=="remove")
		{
			int num;
			cin>>num;
			v.erase(remove_if(v.begin(),v.end(),[num](int val){return val == num;}),v.end());
		}
		else if(cmd=="check")
		{
			int num;
			cin>>num;
			auto result = find(v.begin(),v.end(),num);
			if(result==v.end())
			{
				cout<<0<<"\n";
			}
			else
			{
				cout<<1<<"\n";
			}
		}
		else if(cmd=="toggle")
		{
			int num;
			cin>>num;
			auto result = find(v.begin(),v.end(),num);
			if(result==v.end())
			{
				v.push_back(num);
			}
			else
			{
				v.erase(remove_if(v.begin(),v.end(),[num](int val){return val == num;}),v.end());
			}
		}
		else if(cmd=="all")
		{
			v.clear();
			for(int j=1;j<21;j++)
			{
				v.push_back(j);
			}
		}
		else if(cmd=="empty")
		{
			v.clear();
		}

	}
	return 0;
}