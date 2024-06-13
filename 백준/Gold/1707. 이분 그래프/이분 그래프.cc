#include <bits/stdc++.h>
using namespace std;

#define home 0
#define loop(v, s, e) for(int v = s; v < e; v++)
#define elprint(a) cout << a << '\n'
#define cond(c, t, f) ((c) ? (t) : (f))
#define mat(t, v, r) vector<vector<t> > v(r)

// 이분 그래프
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	int t;
	cin >> t;

	int n, m, v1, v2;
	while (t--)
	{
		cin >> n >> m;

		mat(int, graph, n);
		queue<int> checkPos;
		vector<int> bipartite(n);

		loop(i, 0, m)
		{
			cin >> v1 >> v2;
			graph[v1 - 1].push_back(v2 - 1);
			graph[v2 - 1].push_back(v1 - 1);
		}

		bool isBipartite = true;
		loop(i, 0, n)
		{
			if (bipartite[i] > 0) continue;

			checkPos.push(i);
			bipartite[i] = 1;

			while (!checkPos.empty())
			{
				int standardPos = checkPos.front();
				checkPos.pop();

				loop(j, 0, graph[standardPos].size())
				{
					// 인접한 정점이 같은 집합 => 이분 그래프 X
					if (bipartite[graph[standardPos][j]] > 0 && bipartite[graph[standardPos][j]] == bipartite[standardPos])
					{
						isBipartite = false;

						break;
					}

					if (bipartite[graph[standardPos][j]] > 0) continue;

					// 인접한 정점 다른 집합으로 분할
					bipartite[graph[standardPos][j]] = cond(bipartite[standardPos] == 1, 2, 1);
					checkPos.push(graph[standardPos][j]);
				}

				if (!isBipartite) break;
			}

			if (!isBipartite) break;
		}

		cond(isBipartite, elprint("YES"), elprint("NO"));
	}

	return home;
}