#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(int x, vector<vector<int>> computers, vector<bool>& visited)
{
	visited[x] = true;
	for (int neighbor = 0; neighbor < computers.size(); ++neighbor)
	{
		if (!visited[neighbor] && computers[x][neighbor] == 1)
		{
			DFS(neighbor, computers, visited);
		}
	}
}

int solution(int n, vector<vector<int>> computers) {

	vector<bool> visited(n, false);
	int cnt = 0;

	for (int i = 0; i < n; ++i)
	{
		if (!visited[i])
		{
			DFS(i, computers, visited);
			cnt++;
		}
	}
	
    return cnt;
}