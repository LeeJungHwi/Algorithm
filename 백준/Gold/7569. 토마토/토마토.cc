#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define Z third
int board[102][102][102]; // 익음 : 1 익지않음 : 0 토마토없음 : -1
int dist[102][102][102]; // 시간
int n; // 행
int m; // 열
int h; // 높이
int dx[6] = { 0, 0, 1, -1, 0, 0};
int dy[6] = { 1, -1, 0, 0, 0, 0};
int dz[6] = { 0, 0, 0, 0, 1, -1 };
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n >> h;
	queue<tuple<int, int, int>> Q = {};
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				cin >> board[j][k][i];
				if (board[j][k][i] == 1) // 토마토가 익었다면
					Q.push({ j, k, i});
				if (board[j][k][i] == 0) // 토마토가 아직 안익었다면
					dist[j][k][i] = -1;
			}
		}
	}
	while (!Q.empty()) // 큐가 빌때까지
	{
		tuple<int, int, int> cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 6; dir++)
		{
			int nx = get<0>(cur) + dx[dir];
			int ny = get<1>(cur) + dy[dir];
			int nz = get<2>(cur) + dz[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) // 해당칸이 범위내에 들어오지 않으면
				continue;
			if (dist[nx][ny][nz] >= 0) // 이미 토마토가 익었다면
				continue;
			dist[nx][ny][nz] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1; // 해당칸이 익는데 걸리는 날짜
			Q.push({ nx, ny, nz}); // 해당칸 큐에 추가
		}
	}
	int ans = 0; // 처음부터 모든 토마토가 익은상태이면 0
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (dist[j][k][i] == -1) // 익지 않은 토마토가 있다면
				{
					cout << -1;
					return 0;
				}
				ans = max(ans, dist[j][k][i]); // 마지막에 익는 토마토의 시간
			}
		}
	}
	cout << ans;
}