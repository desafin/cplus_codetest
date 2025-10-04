#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	stack<int> s;
	
	int sum_num=0;
	int count;
	cin>>count;
	for(int i=0;i<count;i++)
	{
		int num;
		cin>>num;
		if(num==0)
		{
			s.pop();
		}
		else
		{
			s.push(num);
		}
	}
	while(!s.empty())
	{
		sum_num+=s.top();
		s.pop();
	}
	cout<<sum_num<<endl;
	return 0;
}