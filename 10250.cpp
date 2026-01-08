#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);

	
	int h,w,n,t;
	cin>>t;
	for(int i =0;i<t;i++)
	{
	cin >> h >> w >> n;
        int height = 0;
        int weight = 0;
        if (n % h == 0) {
            height = h;
            weight = n / h;
        }
        else {
            height = n % h;
            weight = (n / h) + 1;
        }
        cout << height * 100 + weight << endl;
	}
	return 0;
}