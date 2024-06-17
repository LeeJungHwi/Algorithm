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

// Grid
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m;
	cin >> n >> m;
	mat(int, graph, n, m);
	mat(int, dis, n, m);
	queue<pii> checkPos;
	vector<pii> checkDir  = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
	string inputString;
	loop(i, 0, n)
	{
		cin >> inputString;
		loop(j, 0, inputString.size()) graph[i][j] = inputString[j] - '0';
	}

	checkPos.push({ 0, 0 });
	dis[0][0] = 1;

	while (!checkPos.empty())
	{
		pii standard = checkPos.front();
		checkPos.pop();

		loop(i, 0, 4)
		{
			int ci = standard.X + checkDir[i].X * graph[standard.X][standard.Y];
			int cj = standard.Y + checkDir[i].Y * graph[standard.X][standard.Y];

			if (ci < 0 || cj < 0 || ci >= n || cj >= m) continue;
			if (dis[ci][cj] > 0) continue;

			checkPos.push({ ci, cj });
			dis[ci][cj] = dis[standard.X][standard.Y] + 1;
		}
	}

	cond(dis[n - 1][m - 1] > 0, elprint(to_string(dis[n - 1][m - 1] - 1)), elprint("IMPOSSIBLE"));

	return home;
}