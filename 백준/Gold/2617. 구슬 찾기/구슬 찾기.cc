#include <bits/stdc++.h>
using namespace std;

#define home 0
#define loop(v, s, e) for(int v = s; v < e; v++)
#define elprint(a) cout << a << '\n'
#define mat(t, v, r) vector<vector<t> > v(r)

// 구슬 찾기
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m;
	cin >> n >> m;

	mat(int, graph, n);
	mat(int, rgraph, n);
	vector<bool> vis(n);
	queue<int> checkPos;
	int v1, v2;
	loop(i, 0, m)
	{
		cin >> v1 >> v2;
		graph[v2 - 1].push_back(v1 - 1);
		rgraph[v1 - 1].push_back(v2 - 1);
	}

	int ans = 0;

	// 나보다 무거운 구슬
	loop(i, 0, n)
	{
		checkPos.push(i);
		vis[i] = true;

		int cnt = 0;
		while (!checkPos.empty())
		{
			int standardPos = checkPos.front();
			checkPos.pop();

			loop(j, 0, graph[standardPos].size())
			{
				if (vis[graph[standardPos][j]]) continue;

				checkPos.push(graph[standardPos][j]);
				vis[graph[standardPos][j]] = true;
				cnt++;
			}
		}

		loop(j, 0, n) vis[j] = false;
		if (cnt >= (n + 1) / 2) ans++;
	}

	// 나보다 가벼운 구슬
	loop(i, 0, n)
	{
		checkPos.push(i);
		vis[i] = true;

		int cnt = 0;
		while (!checkPos.empty())
		{
			int standardPos = checkPos.front();
			checkPos.pop();

			loop(j, 0, rgraph[standardPos].size())
			{
				if (vis[rgraph[standardPos][j]]) continue;

				checkPos.push(rgraph[standardPos][j]);
				vis[rgraph[standardPos][j]] = true;
				cnt++;
			}
		}

		loop(j, 0, n) vis[j] = false;
		if (cnt >= (n + 1) / 2) ans++;
	}

	elprint(ans);

	return home;
}