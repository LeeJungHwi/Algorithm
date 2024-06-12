#include <bits/stdc++.h>
using namespace std;

#define home 0
#define pii pair<int, int>
#define loop(v, s, e) for(int v = s; v < e; v++)
#define elprint(a) cout << a << '\n'
#define cond(c, t, f) ((c) ? (t) : (f))
#define mat(t, v, r, c) vector<vector<t> > v(r, vector<t>(c))
#define X first
#define Y second

// 주난의 난
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m;
	cin >> n >> m;
	pii sPos, ePos;
	cin >> sPos.X >> sPos.Y >> ePos.X >> ePos.Y;
	mat(int, graph, n, m);
	mat(int, dis, n, m);
	deque<pii> checkPos;
	vector<pii> checkDir;
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });
	
	string inputString;
	loop(i, 0, n)
	{
		cin >> inputString;
		loop(j, 0, m) if (inputString[j] != '0') graph[i][j] = 1;
	}

	sPos.X -= 1;
	sPos.Y -= 1;
	ePos.X -= 1;
	ePos.Y -= 1;
	checkPos.push_front(sPos);
	dis[sPos.X][sPos.Y] = 1;

	while (!checkPos.empty())
	{
		pii standardPos = checkPos.front();
		checkPos.pop_front();

		if (standardPos == ePos)
		{
			elprint(dis[standardPos.X][standardPos.Y] - 1);
			return home;
		}

		loop(i, 0, 4)
		{
			int checkI = standardPos.X + checkDir[i].X;
			int checkJ = standardPos.Y + checkDir[i].Y;

			if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= m) continue;
			if (dis[checkI][checkJ] > 0) continue;

			// 0-1 BFS
			// 현재 점프 => 비용 0
			// 다음 점프 => 비용 1
			dis[checkI][checkJ] = cond(!graph[checkI][checkJ], dis[standardPos.X][standardPos.Y], dis[standardPos.X][standardPos.Y] + 1);
			cond(!graph[checkI][checkJ], checkPos.push_front({ checkI, checkJ }), checkPos.push_back({ checkI, checkJ }));
		}
	}

	return home;
}