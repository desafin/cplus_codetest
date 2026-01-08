#include <bits/stdc++.h>
using namespace std;

int main() {
	iso_base::sync_with_stdio(0);
	cin.tie(0);
	stack<int> stack;
	
	//오름차순대로 들어가도록 push가 목표 하지만 중간에 순서를 바꿔줘야함 
	int num;
	cin>>num;
	//최대값 선언해야함
	for(int i=0;i<num;i++)
	{
		int n;
		cin>>n;
		//오름차순일때만 push 즉 top이랑 비교해야함
		stack.push(n);
	}

	// 코드 작성
	return 0;
} y