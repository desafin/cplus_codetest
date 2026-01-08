#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);

	int h,w,n;
	cin>>h;
	cin>>w;
	cin>>n;
	int height = (n%h)+1;
	int weight = (n/h)+1
	int result = height*10+weight;
	return 0;
}