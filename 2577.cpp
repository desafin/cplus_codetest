#include <bits/stdc++.h>
using namespace std;

int main() {
	int a ,b,c;
	cin>>a>>b>>c;
	int result;
	result=a*b*c;

	// cout<<result<<endl;

	string resultString;

	resultString = to_string(result);

	int resultList[10] ={0,};

	int checkNum=0;

	for (int i = 0; i < resultString.length(); i++) {
        int digit = resultString[i] - '0';
        resultList[digit]++;
    }
	for(int i=0;i<10;i++)
	{
		cout<<resultList[i]<<"\n";
	}

	return 0;
}