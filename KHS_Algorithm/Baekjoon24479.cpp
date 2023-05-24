#include <iostream>
#include <vector>
#include <algorithm>
#define Fastio std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0)

std::vector<std::vector<int>> graph;
std::vector<bool> visited;
std::vector<int> result;
int num = 0;

void DFS(int x)
{
	// 1. ���� ��� �湮
	visited[x] = true;
	result[x] = ++num;

	// ���� ��� ����
	std::sort(graph[x].begin(), graph[x].end());

	// 2. ������ ��� �� �湮���� ���� ��带 ����
	for (int neighbor : graph[x])
	{
		if (!visited[neighbor])
		{
			// 3. ���õ� ���� ��忡 ���� 1���� 2���� �ݺ�
			// ��� ȣ���� ���� 4������ ����
			// ��带 ã�� �ൿ�� �����Ƿ� ��� ��� �湮�� ����
			DFS(neighbor);
		}
	}
}


int main()
{
	Fastio;
	int N, M, V;

	std::cin >> N >> M >> V;

	graph.resize(N + 1);
	result.resize(N + 1);
	visited.resize(N + 1, false);

	for (int i = 0; i < M; ++i)
	{
		int u, v;
		std::cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	DFS(V);

	for (int i = 1; i < N + 1; ++i)
		printf("%d\n", result[i]);
}