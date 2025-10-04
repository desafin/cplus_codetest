#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	stack<int> s;
	int cmd;
	int n;
	cin>>n;
	while(n--)
	{
		cin>>cmd;
		if(cmd==1)
		{
			int num;
			cin>>num;
			s.push(num);
		}
		else if(cmd==2){
			if(s.empty())
			{
				cout<<-1<<"\n";
			}
			else
			{
				cout<<s.top()<<"\n";
				s.pop();

			}
		}
		else if(cmd==3){
			cout<<s.size()<<"\n";
		}
		else if(cmd==4){
			if(s.empty())
			{
				cout<<1<<"\n";
			}
			else
			{
				cout<<0<<"\n";
			}
		}
		else if(cmd==5){
			if(!s.empty())
			{
				cout<<s.top()<<"\n";
			}
			else
			{
				cout<<-1<<"\n";
			}
		}
	}

}