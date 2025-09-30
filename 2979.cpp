#include <bits/stdc++.h>
using namespace std;

int main() {
	// ios_base::sync_with_stdio(0);
	int a,b,c;
	cin>>a>>b>>c;
	int answer=0;

	int arriveTime=0;
	int leaveTime=0;
	cin>>arriveTime>>leaveTime;
	int stayTime=0;
	stayTime=leaveTime-arriveTime;
	answer+=stayTime*a;
cout<<answer<<endl;
	arriveTime=0;
	leaveTime=0;
	cin>>arriveTime>>leaveTime;
	stayTime=0;
	stayTime=leaveTime-arriveTime;
	answer+=stayTime*b;
cout<<answer<<endl;

	arriveTime=0;
	leaveTime=0;
	cin>>arriveTime>>leaveTime;
	stayTime=0;
	stayTime=leaveTime-arriveTime;
	answer+=stayTime*c;

	cout<<answer<<endl;
	return 0;
}