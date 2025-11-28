#include <bits/stdc++.h>
using namespace std;

int main() {
	// 코드 작성
	int h;
	int m;
	cin>>h;
	cin>>m;

	if(m>=45)
	{
		m=m-45;
	}
	else
	{
		m=60-(45-m);
		if(h>=1)
		{
			h--;
		}
		else
		{
			h=23;
		}
	}
	cout<<h<<" "<<m<<endl;
	return 0;
}