#include <bits/stdc++.h>
using namespace std;

int main() {
	// 코드 작성
	string str;
	cin>>str;
	bool result =true;
	for(int i=0;i<str.length()/2;i++)
	{
		if(str[i]!=str[str.length()-(i+1)])
		{
			result=false;
		}

	}
	if(result)
	{
		cout<<1<<endl;
	}
	else
	{
		cout<<0<<endl;
	}
	return 0;
}