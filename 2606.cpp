#include <bits/stdc++.h>
using namespace std;

vector<int> network[101];
bool visited[101]={false};


int dfs(int startNode)
{
	stack<int> s;
	int infectedCount=0;

	s.push(startNode);
	visited[startNode]=true;

	while(!s.empty())
	{
		int currentNode = s.top();
		s.pop();

		for(int i=0; i < network[currentNode].size(); i++)
		{
			int nextNode = network[currentNode][i];

			if(!visited[nextNode])
			{
				visited[nextNode]=true;
				s.push(nextNode);
				infectedCount++;
			}
		}
	}
	return infectedCount;
}

int bfs(int startNode)
{
	queue<int> q;
	int infectedCount=0;

	q.push(startNode);
	visited[startNode]=true;

	while(!q.empty())
	{
		int currentNode = q.front();
		q.pop();

		for(int i=0;i<network[currentNode].size();i++)
		{
			int nextNode = network[currentNode][i];

			if(!visited[nextNode])
			{
				visited[nextNode]=true;
				q.push(nextNode);
				infectedCount++;
			}
		}
	}
	return infectedCount;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int computerNum , pairNum;
	cin>>computerNum;
	cin>>pairNum;

	for (int i =0;i<pairNum;i++)
	{
		int u,v;
		cin>>u>>v;
		network[u].push_back(v);
		network[v].push_back(u);
	}
	cout<<bfs(1)<<"\n";
	return 0;
}