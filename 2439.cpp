#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int num;
	cin>>num;
	int cnt =num;
	for(int i =0;i<cnt;i++)
	{
		for(int j=0;j<cnt;j++)
		{
			if(j>=num-1)
			{
				cout<<"*";
				
			}
			else
			{
				cout<<" ";
			}
		}
		cout<<"\n";
		num --;
	}
	return 0;
}