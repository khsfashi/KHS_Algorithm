#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define Fastio std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0)

std::vector<std::vector<int>> graph;
std::vector<bool> visited;
std::vector<int> result;
int num = 0;

void BFS(int x)
{
	std::queue<int> q;

	// 1. ���� ��带 ť�� ���� �ִ´�.
	q.push(x);

	// 2. ť�� ���� ��带 �湮 ó���Ѵ�.
	visited[x] = true;
	result[x] = ++num;

	// ť���� ��� ��带 ���´ٸ� ���� (���� ���� ���� ���Ӱ� push�� ���ٸ� ����)
	while (!q.empty()) {
		// ���� ��带 �ĺ��ϱ� ���� ����
		int i = q.front();

		// 3. ť�� ���� ��带 ������.
		q.pop();

		// ���� ��� ����
		std::sort(graph[i].begin(), graph[i].end());

		// 4. ���� ���� ��� �� �湮���� ���� ��� ��带 ť�� �ִ´�.
		for (int neighbor : graph[i])
		{
			if (!visited[neighbor])
			{
				// �� �ڵ忡���� �湮 ó���� �԰� ���ÿ� ť�� ��带 �ִ´�.
				// ���� ���� ��带 ���� ť�� �־��ٸ�, �ٽ� ���� �ö� ť�� �� ������ �ݺ��Ѵ�.
				visited[neighbor] = true;
				result[neighbor] = ++num;
				q.push(neighbor);
			}
		}
		// 5. ť�� �� ������ 2���� 3���� �ݺ��Ѵ�.
	}
}

int main()
{
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

	BFS(V);

	for (int i = 1; i < N + 1; ++i)
		printf("%d\n", result[i]);
}