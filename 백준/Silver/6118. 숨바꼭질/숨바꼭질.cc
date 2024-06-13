#include <bits/stdc++.h>
using namespace std;

#define home 0
#define loop(v, s, e) for(int v = s; v < e; v++)
#define scprint(a) cout << a << ' '
#define mat(t, v, r) vector<vector<t> > v(r)

// 숨바꼭질
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m;
	cin >> n >> m;

	mat(int, graph, n);
	vector<int> dis(n);
	queue<int> checkPos;
	int v1, v2;
	loop(i, 0, m)
	{
		cin >> v1 >> v2;
		graph[v1 - 1].push_back(v2 - 1);
		graph[v2 - 1].push_back(v1 - 1);
	}

	int maxDis = 0;
	vector<int> ans;

	checkPos.push(0);
	dis[0] = 1;

	while (!checkPos.empty())
	{
		int standardPos = checkPos.front();
		checkPos.pop();

		loop(i, 0, graph[standardPos].size())
		{
			if (dis[graph[standardPos][i]] > 0) continue;

			checkPos.push(graph[standardPos][i]);
			dis[graph[standardPos][i]] = dis[standardPos] + 1;

			if (maxDis < dis[graph[standardPos][i]])
			{
				maxDis = dis[graph[standardPos][i]];
				ans.clear();
				ans.push_back(graph[standardPos][i] + 1);
			}
			else if (maxDis == dis[graph[standardPos][i]]) ans.push_back(graph[standardPos][i] + 1);
		}
	}

	sort(ans.begin(), ans.end());
	scprint(ans[0]);
	scprint(maxDis - 1);
	scprint(ans.size());

	return home;
}