#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

const int MAX_NUM = 1001;

std::vector<std::vector<int>> graph;
std::vector<bool> visited;

void DFS(int x)
{
	// 1. ���� ��� �湮
	visited[x] = true;
	std::cout << x << " ";

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

void BFS(int x)
{
	std::queue<int> q;
	
	// 1. ���� ��带 ť�� ���� �ִ´�.
	q.push(x);

	// 2. ť�� ���� ��带 �湮 ó���Ѵ�.
	visited[x] = true;

	// ť���� ��� ��带 ���´ٸ� ���� (���� ���� ���� ���Ӱ� push�� ���ٸ� ����)
	while (!q.empty()) {
		// ���� ��带 �ĺ��ϱ� ���� ����
		int i = q.front();

		std::cout << i << " ";

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
	visited.resize(N + 1, false);

	for (int i = 0; i < M; ++i)
	{
		int u, v;
		std::cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	DFS(V);

	std::cout << std::endl;

	visited.assign(N + 1, false);
	
	BFS(V);
}