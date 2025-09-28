#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int caseNum1;
	int caseNum2;
	vector<string> everHeard;
	vector<string> result;
	cin>>caseNum1>>caseNum2;
	for(int i=0;i<caseNum1;i++)
	{
		string name;
		cin>>name;
		everHeard.push_back(name);
		// cout<<"pushback"<<"\n";

	}
	sort(everHeard.begin(),everHeard.end());
	for(int i=0;i<caseNum2;i++)
	{
		string name;
		cin>>name;
		if(binary_search(everHeard.begin(),everHeard.end(),name))
		{
			result.push_back(name);
		}
	}
	cout<<result.size()<<"\n";
	for(int i=0;i<result.size();i++)
	{
		cout<<result[i]<<"\n";
	}
	return 0;
}