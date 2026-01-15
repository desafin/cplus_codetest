#include <bits/stdc++.h>
using namespace std;

int main() {
	int a,b,v;
	cin>>a>>b>>v;
	int days = (v - a) / (a - b) + 1;
    if ((v - a) % (a - b) != 0) {
        days++;
    }
	cout<<days<<endl;
	return 0;
}