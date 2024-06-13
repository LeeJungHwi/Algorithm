#include <bits/stdc++.h>
using namespace std;

#define home 0
#define loop(v, s, e) for(int v = s; v < e; v++)
#define elprint(a) cout << a << '\n'
#define mat(t, v, r, c) vector<vector<t> > v(r, vector<t>(c))

// 바이러스
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m;
	cin >> n >> m;
	mat(int, graph, n, n);
	vector<bool> vis(n);
	queue<int> checkPos;

	int v1, v2;
	loop(i, 0, m)
	{
		cin >> v1 >> v2;
		graph[v1 - 1][v2 - 1] = 1;
		graph[v2 - 1][v1 - 1] = 1;
	}

	checkPos.push(0);
	vis[0] = true;

	int cnt = 0;
	while (!checkPos.empty())
	{
		int standardPos = checkPos.front();
		checkPos.pop();

		loop(i, 0, n)
		{
			if (!graph[standardPos][i]) continue;
			if (vis[i]) continue;

			checkPos.push(i);
			vis[i] = true;
			cnt++;
		}
	}

	elprint(cnt);

	return home;
}