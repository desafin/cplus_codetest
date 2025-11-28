#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string a,b,c;
	cin>>a;
	cin>>b;
	cin>>c;
	
	int ia,ib,ic;
	
	string ab;
	ab = a+b;
	int iab =stoi(ab);

	ia=stoi(a);
	ib=stoi(b);
	ic=stoi(c);

	cout<<(ia+ib)-ic<<"\n";
	cout<<iab-ic<<endl;
	return 0;
}