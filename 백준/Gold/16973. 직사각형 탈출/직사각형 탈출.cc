#include <bits/stdc++.h>
using namespace std;

#define home 0
#define pii pair<int, int>
#define loop(v, s, e) for(int v = s; v < e; v++)
#define elprint(a) cout << a << '\n'
#define mat(t, v, r, c) vector<vector<t> > v(r, vector<t>(c))
#define X first
#define Y second

// 직사각형 탈출
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // 6, 7
	cin >> n >> m;
	mat(int, graph, n, m);
	loop(i, 0, n) loop(j, 0, m) cin >> graph[i][j];
	mat(int, dis, n, m);
	queue<pii> checkPos;
	vector<pii> checkDir;
	int h, w; // 2 2
	cin >> h >> w;
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1 * h, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 * w });

	pii startPos; // 1 1
	cin >> startPos.X >> startPos.Y;
	checkPos.push({ startPos.X - 1, startPos.Y - 1 });
	dis[startPos.X - 1][startPos.Y - 1] = 1;
	pii endPos; // 5 5
	cin >> endPos.X >> endPos.Y;

	while (!checkPos.empty())
	{
		pii standardPos = checkPos.front();
		checkPos.pop();

		// 위치 => 직사각형 좌상
		// 상하는 w만큼 좌우는 h만큼 체크
		loop(i, 0, 4)
		{
			// 경계체크, 방문체크 => 좌상에서 상하좌우 한칸씩만 확인
			if (i % 2 == 0)
			{
				int checkI = standardPos.X + checkDir[i].X;
				int checkJ = standardPos.Y + checkDir[i].Y;
				if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= m) continue;
				if (dis[checkI][checkJ] > 0) continue;
			}
			else
			{
				if (i == 1)
				{
					int checkI = standardPos.X + checkDir[i].X / h;
					int checkJ = standardPos.Y + checkDir[i].Y;
					if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= m) continue;
					if (dis[checkI][checkJ] > 0) continue;
				}
				else if (i == 3)
				{
					int checkI = standardPos.X + checkDir[i].X;
					int checkJ = standardPos.Y + checkDir[i].Y / w;
					if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= m) continue;
					if (dis[checkI][checkJ] > 0) continue;
				}
			}

			bool isMove = true; // 움직일수있는지 체크

			// 상하
			if (i < 2)
			{
				// w 만큼 우로 가면서 상하 체크
				// 하나라도 경계를 만나거나 벽에 막히면 isMove false, break
				loop(j, 0, w)
				{
					int checkI = standardPos.X + checkDir[i].X;
					int checkJ = standardPos.Y + checkDir[i].Y + j;

					// 경계체크
					if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= m)
					{
						isMove = false;

						break;
					}

					// 장애물체크
					if (graph[checkI][checkJ] == 1)
					{
						isMove = false;

						break;
					}
				}

				if (!isMove) continue;
			}
			else // 좌우
			{
				// h 만큼 하로 가면서 좌우 체크
				// 하나라도 경계를 만나거나 벽에 막히면 isMove false, break
				loop(j, 0, h)
				{
					int checkI = standardPos.X + checkDir[i].X + j;
					int checkJ = standardPos.Y + checkDir[i].Y;

					// 경계체크
					if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= m)
					{
						isMove = false;

						break;
					}

					// 장애물체크
					if (graph[checkI][checkJ] == 1)
					{
						isMove = false;

						break;
					}
				}

				if (!isMove) continue;
			}

			// 큐에저장, 거리저장
			// standard에서 상하좌우 중 하나
			if (i % 2 == 0)
			{
				checkPos.push({ standardPos.X + checkDir[i].X, standardPos.Y + checkDir[i].Y });
				dis[standardPos.X + checkDir[i].X][standardPos.Y + checkDir[i].Y] = dis[standardPos.X][standardPos.Y] + 1;
			}
			else
			{
				if (i == 1)
				{
					checkPos.push({ standardPos.X + checkDir[i].X / h, standardPos.Y + checkDir[i].Y });
					dis[standardPos.X + checkDir[i].X / h][standardPos.Y + checkDir[i].Y] = dis[standardPos.X][standardPos.Y] + 1;
				}
				else if (i == 3)
				{
					checkPos.push({ standardPos.X + checkDir[i].X, standardPos.Y + checkDir[i].Y / w });
					dis[standardPos.X + checkDir[i].X][standardPos.Y + checkDir[i].Y / w] = dis[standardPos.X][standardPos.Y] + 1;
				}
			}
		}
	}

	elprint(dis[endPos.X - 1][endPos.Y - 1] - 1);

	return home;
}