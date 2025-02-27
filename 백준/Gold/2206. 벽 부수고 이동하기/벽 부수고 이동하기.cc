#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
char board[1000][1000]; // 이동 : 0 벽 : 1
int dist[1000][1000][2]; // 0 : 벽 안부숨 1 : 벽 부숨
int nextDist; // 다음 거리
int n; // 행
int m; // 열
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			// 맵 입력
			cin >> board[i][j];

			// 거리 초기화
			dist[i][j][0] = -1;
			dist[i][j][1] = -1;
		}
	}

	// 시작칸과 끝나는칸 거리에 포함
	dist[0][0][0] = 1;
	dist[0][0][1] = 1;

	queue<pair<int, pair<int, int>>> Q = {};

	Q.push({0, {0, 0}}); // 시작칸 큐에 추가

	while (!Q.empty())
	{
		pair<int, pair<int, int>> cur = Q.front();
		int isBroken = cur.Y.second; // 벽을 부쉈는지 체크

		// 최단거리 출력
		if (cur.X == n - 1 && cur.Y.first == m - 1)
		{
			cout << dist[cur.X][cur.Y.first][isBroken];

			return 0;
		}

		Q.pop();

		// 다음 거리 초기화
		nextDist = dist[cur.X][cur.Y.first][isBroken] + 1;

		// BFS
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y.first + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) // 해당칸이 범위내에 들어오지 않으면
				continue;

			if (dist[nx][ny][isBroken] == -1 && board[nx][ny] == '0') // 아직 이동하지않았고 이동할수있는곳이면
			{
				dist[nx][ny][isBroken] = nextDist;
				Q.push({nx, {ny, isBroken}});
			}

			if (!isBroken && board[nx][ny] == '1' && dist[nx][ny][1] == -1)
			{
				dist[nx][ny][1] = nextDist;
				Q.push({ nx, {ny, 1}});
			}
		}
	}
	cout << -1; // 이동 불가
	return 0;
}