#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int m;
	cin>>n>>m;
	vector<int> prefix_sum(n + 1, 0); 
	for (int i = 1; i <= n; i++)
	{
    int num;
    cin >> num;
    prefix_sum[i] = prefix_sum[i-1] + num;
	}
	for(int i=0;i<m;i++)
	{
		int j;
		int k;
		cin>>j>>k;
		int sum = prefix_sum[k] - prefix_sum[j-1];
		cout<<sum<<"\n";
	}
	return 0;
}