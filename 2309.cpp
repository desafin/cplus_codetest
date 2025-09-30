#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v;
	// 코드 작성
	for(int i=0;i<9;i++)
	{
		int tall;
		cin>>tall;
		v.push_back(tall);
	}
	sort(v.begin(),v.end());
	do
	{
		int sum=0;
		for(int i=0;i<7;i++)
		{
			sum+=v[i];
			
		}
		if(sum==100)
		{
				break;
		}
	}while(next_permutation(v.begin(),v.end()));
	for(int i=0;i<7;i++)
	{
		cout<<v[i]<<"\n";
	}
	return 0;
}