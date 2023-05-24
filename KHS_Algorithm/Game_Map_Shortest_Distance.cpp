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

	// ť���� ��� ��带 ���´ٸ� ���� (���� ���� ���� ���Ӱ� push�� ���ٸ� ����)
	while (!q.empty()) {
		// ���� ��带 �ĺ��ϱ� ���� ����
		int x = q.front().first;
		int y = q.front().second;

		// 3. ť�� ���� ��带 ������.
		q.pop();

		// 4. ���� ���� ��� �� �湮���� ���� ��� ��带 ť�� �ִ´�.
		for (auto& dir : direction)
		{
			int newX = x + dir.first;
			int newY = y + dir.second;
			if (newX >= 0 && newX < n && newY >= 0 && newY < m && dist[newX][newY] == 0 && maps[newX][newY] == 1)
			{
				// �� �ڵ忡���� �湮 ó���� �԰� ���ÿ� ť�� ��带 �ִ´�.
				// ���� ���� ��带 ���� ť�� �־��ٸ�, �ٽ� ���� �ö� ť�� �� ������ �ݺ��Ѵ�.
				dist[newX][newY] = dist[x][y] + 1;
				q.push(make_pair(newX, newY));
			}
		}
		// 5. ť�� �� ������ 2���� 3���� �ݺ��Ѵ�.
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