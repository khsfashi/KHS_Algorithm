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
	// 1. 현재 노드 방문
	visited[x] = true;
	result[x] = ++num;

	// 인접 노드 정렬
	std::sort(graph[x].begin(), graph[x].end());

	// 2. 인접한 노드 중 방문하지 않은 노드를 선택
	for (int neighbor : graph[x])
	{
		if (!visited[neighbor])
		{
			// 3. 선택된 인접 노드에 대해 1번과 2번을 반복
			// 재귀 호출을 통해 4번까지 행함
			// 노드를 찾는 행동이 없으므로 모든 노드 방문시 종료
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