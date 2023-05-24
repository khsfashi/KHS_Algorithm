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

	// 1. 시작 노드를 큐에 집어 넣는다.
	q.push(x);

	// 2. 큐에 넣은 노드를 방문 처리한다.
	visited[x] = true;
	result[x] = ++num;

	// 큐에서 모든 노드를 꺼냈다면 종료 (전부 꺼낸 이후 새롭게 push가 없다면 종료)
	while (!q.empty()) {
		// 현재 노드를 식별하기 위한 변수
		int i = q.front();

		// 3. 큐에 넣은 노드를 꺼낸다.
		q.pop();

		// 인접 노드 정렬
		std::sort(graph[i].begin(), graph[i].end());

		// 4. 이후 인접 노드 중 방문하지 않은 모든 노드를 큐에 넣는다.
		for (int neighbor : graph[i])
		{
			if (!visited[neighbor])
			{
				// 이 코드에서는 방문 처리를 함과 동시에 큐에 노드를 넣는다.
				// 이후 인접 노드를 전부 큐에 넣었다면, 다시 위로 올라가 큐가 빌 때까지 반복한다.
				visited[neighbor] = true;
				result[neighbor] = ++num;
				q.push(neighbor);
			}
		}
		// 5. 큐가 빌 때까지 2번과 3번을 반복한다.
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