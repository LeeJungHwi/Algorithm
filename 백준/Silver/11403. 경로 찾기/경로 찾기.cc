#include <bits/stdc++.h>
using namespace std;

#define home 0
#define loop(v, s, e) for(int v = s; v < e; v++)
#define scprint(a) cout << a << ' '
#define cond(c, t, f) ((c) ? (t) : (f))
#define mat(t, v, r, c) vector<vector<t> > v(r, vector<t>(c))

// 경로 찾기
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	int n;
	cin >> n;
	mat(int, graph, n, n);
	vector<bool> vis(n);
	queue<int> checkPos;
	loop(i, 0, n) loop(j, 0, n) cin >> graph[i][j];
	loop(i, 0, n) loop(j, 0, n)
	{
		checkPos.push(i);

		while (!checkPos.empty())
		{
			int standardPos = checkPos.front();
			checkPos.pop();

			loop(k, 0, n)
			{
				if (!graph[standardPos][k]) continue;
				if (vis[k]) continue;

				checkPos.push(k);
				vis[k] = true;
			}
		}

		// i => j 경로가 있는지?
		cond(vis[j], scprint(1), scprint(0));
		if (j == n - 1) cout << '\n';
		loop(k, 0, n) vis[k] = false;
	}

	return home;
}