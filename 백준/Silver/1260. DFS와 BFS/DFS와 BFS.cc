#include <bits/stdc++.h>
using namespace std;

#define home 0
#define loop(v, s, e) for(int v = s; v < e; v++)
#define scprint(a) cout << a << ' '
#define mat(t, v, r, c) vector<vector<t> > v(r, vector<t>(c))

void DFS(int L, vector<vector<int> > &graph, vector<bool> &vis)
{
	vis[L] = true;
	scprint(L + 1);

	loop(i, 0, graph.size())
	{
		if (!graph[L][i]) continue;
		if (vis[i]) continue;

		DFS(i, graph, vis);
	}
}

// DFS와 BFS
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m, s;
	cin >> n >> m >> s;

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

	// DFS
	DFS(s - 1, graph, vis);
	cout << '\n';

	// BFS
	loop(i, 0, n) vis[i] = false;
	checkPos.push(s - 1);
	vis[s - 1] = true;

	while (!checkPos.empty())
	{
		int standardPos = checkPos.front();
		checkPos.pop();
		scprint(standardPos + 1);

		loop(i, 0, n)
		{
			if (!graph[standardPos][i]) continue;
			if (vis[i]) continue;

			checkPos.push(i);
			vis[i] = true;
		}
	}

	return home;
}