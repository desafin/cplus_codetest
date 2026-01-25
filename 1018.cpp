#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	int N, M;
	cin >> N >> M;

	vector<string> board;
	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;		   
		board.push_back(temp); 
	}

	int min_corrections = 64;

	for (int i = 0; i <= N - 8; i++)
	{
		for (int j = 0; j <= M - 8; j++)
		{

			int current_cnt = 0;

			for (int r = 0; r < 8; r++)
			{
				for (int c = 0; c < 8; c++)
				{
					if (((i + r + j + c) % 2 == 0) != (board[i + r][j + c] == 'W'))
					{
						current_cnt++;
					}
				}
			}

			current_cnt = min(current_cnt, 64 - current_cnt);

			if (current_cnt < min_corrections)
			{
				min_corrections = current_cnt;
			}
		}
	}

	cout << min_corrections;
}