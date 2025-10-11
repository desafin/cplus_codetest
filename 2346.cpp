#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int casenum;
	cin>>casenum;
	deque<pair<int,int>> d;
	for(int i=0;i<casenum;i++)
	{
		int num;
		cin>>num;
		d.push_back({i+1,num});
	}

	while(!d.empty())
	{
		int currentindex =d.front().first;
		int currentnum = d.front().second;
		d.pop_front();
		cout<<currentindex<<" ";

		if(d.empty())
		{
			break;
		}

		if(currentnum>0)
		{
			for(int i=0;i<currentnum-1;i++)
			{
				d.push_back(d.front());
				d.pop_front();
			}
		}
		else
		{
			for(int i=0;i<-currentnum;i++)
			{
				d.push_front(d.back());
				d.pop_back();
			}
		}
	}
	return 0;
}