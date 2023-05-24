#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<pair<int, int>> direction = { {0,1},{0,-1},{1,0},{-1,0} };
vector<bool> visited(26);
int R, C;
int maxNum = 0;

void DFS(vector<string>& board, int r, int c, int cnt)
{
	char cur = board[r][c];
	visited[cur - 'A'] = true;

	maxNum = max(maxNum, cnt);

	for (auto& dir : direction)
	{
		int newR = r + dir.first;
		int newC = c + dir.second;
		
		if (newR >= 0 && newR < R && newC >= 0 && newC < C)
		{
			char next = board[newR][newC];
			if (!visited[next - 'A'])
			{
				DFS(board, newR, newC, cnt + 1);
			}
		}
	}
	visited[cur - 'A'] = false;
}

int main()
{
	cin >> R >> C;
	vector<string> board(R);

	for (int i = 0; i < R; ++i)
	{
		cin >> board[i];
	}

	DFS(board, 0, 0, 1);

	cout << maxNum;
}