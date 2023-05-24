#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int> > maps)
{
    const int n = maps.size();
    const int m = maps[0].size();

    vector<vector<int>> dist(n, vector<int>(m));
	vector<pair<int, int>> direction = { {0,1},{0,-1},{1,0},{-1,0} };

    queue<pair<int, int>> q;

    q.push(make_pair(0, 0));
    dist[0][0] = 1;

	// 큐에서 모든 노드를 꺼냈다면 종료 (전부 꺼낸 이후 새롭게 push가 없다면 종료)
	while (!q.empty()) {
		// 현재 노드를 식별하기 위한 변수
		int x = q.front().first;
		int y = q.front().second;

		// 3. 큐에 넣은 노드를 꺼낸다.
		q.pop();

		// 4. 이후 인접 노드 중 방문하지 않은 모든 노드를 큐에 넣는다.
		for (auto& dir : direction)
		{
			int newX = x + dir.first;
			int newY = y + dir.second;
			if (newX >= 0 && newX < n && newY >= 0 && newY < m && dist[newX][newY] == 0 && maps[newX][newY] == 1)
			{
				// 이 코드에서는 방문 처리를 함과 동시에 큐에 노드를 넣는다.
				// 이후 인접 노드를 전부 큐에 넣었다면, 다시 위로 올라가 큐가 빌 때까지 반복한다.
				dist[newX][newY] = dist[x][y] + 1;
				q.push(make_pair(newX, newY));
			}
		}
		// 5. 큐가 빌 때까지 2번과 3번을 반복한다.
	}

	return (dist[n - 1][m - 1] == 0) ? -1 : dist[n - 1][m - 1];
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> maps(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> maps[i][j];
		}
	}

	int result = solution(maps);
	cout << result << endl;

}