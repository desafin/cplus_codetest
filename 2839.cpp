#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
<<<<<<< HEAD
	cout.tie(0);
	int n;
	int answer=0;
	cin>>n;
	while(n>=0)
	{
		if(n%5==0)
		{
			answer+=n/5;
			cout<<answer<<"\n";
			return 0;
		}
		n-=3;
		answer++;
	}
	cout<<-1<<"\n";
=======
	int num;
	cin>>num;
	int cnt=0;
>>>>>>> 09216d8 (add)
	return 0;
}