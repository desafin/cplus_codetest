#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int a,b,c;
	cin>>a>>b>>c;
	int list[101]={0,};
	int answer =0;
	for(int i=0;i<3;i++)
	{
		int arriveTime;
		int leaveTime;
		cin>>arriveTime>>leaveTime;
		for(int j=arriveTime;j<leaveTime;j++)
		{
			list[j]++;
		}
	}
	for(int i=0;i<101;i++)
	{
		if(list[i]==1)
		{
			answer+=a;
		}
		else if(list[i]==2)
		{
			answer+=b*2;
		}
		else if(list[i]==3)
		{
			answer+=c*3;
		}
	}
	cout<<answer<<endl;
}