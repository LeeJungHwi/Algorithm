#include <bits/stdc++.h>
using namespace std;

#define home 0
#define pii pair<int, int>
#define loop(v, s, e) for(int v = s; v < e; v++)
#define elprint(a) cout << a << '\n'
#define mat(t, v, r, c) vector<vector<t> > v(r, vector<t>(c))
#define X first
#define Y second

// 채굴
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m, k;
	cin >> n >> m >> k;

	// 최대 강도
	mat(int, graph, n, m);
	int maxStr = 0;
	loop(i, 0, n) loop(j, 0, m)
	{
		cin >> graph[i][j];
		maxStr = max(maxStr, graph[i][j]);
	}
	mat(bool, vis, n, m);
	queue<pii> checkPos;
	vector<pii> checkDir = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

	// 0 => F, maxStr = T
	// range => 1 ~ maxStr
	int l = 0, r = maxStr, d = maxStr;
	while (l <= r)
	{
		int standard = (l + r) / 2;
		bool isStandard = false;

		// 가장자리 => 바닥 광물 X
		loop(i, 0, n)
		{
			if (graph[i][0] < standard + 1 && !vis[i][0])
			{
				vis[i][0] = true;
				checkPos.push({ i, 0 });
			}

			if (graph[i][m - 1] < standard + 1 && !vis[i][m - 1])
			{
				vis[i][m - 1] = true;
				checkPos.push({ i, m - 1 });
			}
		}
		loop(i, 0, m)
		{
			if (graph[0][i] < standard + 1 && !vis[0][i])
			{
				vis[0][i] = true;
				checkPos.push({ 0, i });
			}
		}

		// BFS
		int cnt = checkPos.size();
		while (!checkPos.empty())
		{
			pii standardPos = checkPos.front();
			checkPos.pop();

			// k 이상 채굴
			if (cnt > k - 1)
			{
				isStandard = true;
				break;
			}

			loop(i, 0, 4)
			{
				int checkI = standardPos.X + checkDir[i].X;
				int checkJ = standardPos.Y + checkDir[i].Y;

				if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= m) continue;
				if (vis[checkI][checkJ]) continue;
				if (graph[checkI][checkJ] > standard) continue;

				checkPos.push({ checkI, checkJ });
				vis[checkI][checkJ] = true;
				cnt++;
			}
		}

		if (isStandard)
		{
			d = standard;
			r = standard - 1;
		}
		else l = standard + 1;

		// 초기화
		loop(i, 0, n) loop(j, 0, m) vis[i][j] = false;
		while (!checkPos.empty()) checkPos.pop();
	}

	elprint(d);

	return home;
}