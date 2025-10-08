#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int caseNum;
	cin>>caseNum;
	for(int i=0;i<caseNum;i++)
	{
		bool result = true;
		stack<char> s;
		string str;
		cin>>str;
		for(int j=0; j<str.length();j++)
		{
			if(str[j]=='(')
			{
				s.push(str[j]);
			}
			else if(str[j]==')')
			{
				if(s.empty())
				{
					result=false;
					break;
				}
				s.pop();
			}
		}
		if(!s.empty())
		{
			result=false;
		}
		if(result)
		{
			cout<<"YES"<<"\n";
		}
		else
		{
			cout<<"NO"<<"\n";
		}
	}
	return 0;
}