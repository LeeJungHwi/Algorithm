#include <bits/stdc++.h>
using namespace std;

#define home 0
#define loop(v, s, e) for(int v = s; v < e; v++)
#define scprint(a) cout << a << ' '
#define mat(t, v, r) vector<vector<t> > v(r)

// 효율적인 해킹
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m;
	cin >> n >> m;

	mat(int, graph, n);
	vector<bool> vis(n);
	queue<int> checkPos;
	int v1, v2;
	loop(i, 0, m)
	{
		cin >> v1 >> v2;
		graph[v2 - 1].push_back(v1 - 1);
	}

	int maxCnt = 0;
	vector<int> ans;
	loop(i, 0, n)
	{
		checkPos.push(i);
		vis[i] = true;
		int cnt = 0;

		// 해킹 할 수 있는 컴퓨터 수
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

		// 갱신
		if (maxCnt < cnt)
		{
			maxCnt = cnt;
			ans.clear();
			ans.push_back(i + 1);
		}
		else if (maxCnt == cnt) ans.push_back(i + 1);
	}

	sort(ans.begin(), ans.end());
	loop(i, 0, ans.size()) scprint(ans[i]);

	return home;
}