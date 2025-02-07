#include <bits/stdc++.h>
using namespace std;

#define home 0

#ifdef ONLINE_JUDGE
#define init ios_base::sync_with_stdio(home); cin.tie(home)
#else
#define init ios_base::sync_with_stdio(home); cin.tie(home); ifstream cin("input.txt")
#endif

#define ll long long
#define ld long double

#define pii pair<int, int>
#define pll pair<ll, ll>

#define loop(v, s, e) for(int v = (s); v < (e); v++)
#define rloop(v, s, e) for(int v = (s); v > (e); v--)
#define mloop(v, a) for(auto v = (a).begin(); v != (a).end(); v++)
#define mrloop(v, a) for(auto v = (a).rbegin(); v != (a).rend(); v++)

#define p(a) cout << (a)
#define elp(a) cout << (a) << '\n'
#define scp(a) cout << (a) << ' '

#define tvec(t, v) vector<t> v
#define vec(t, v, r) vector<t> v((r))
#define gmat(t, v, r) vector<vector<t> > v((r))
#define mat(t, v, r, c) vector<vector<t> > v((r), vector<t>((c)))

#define dir vector<pii> cd = { {-1, home}, {1, home}, { home, -1 }, { home, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } }
#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX = 2147000000;
const int MIN = -2147000000;

void DFS(int s, int d, vector<vector<pii>> &g, vector<bool> &vis, int &maxDis, int &maxDisVertex)
{
	if (maxDis < d)
	{
		maxDis = d;
		maxDisVertex = s;
	}

	loop(i, home, g[s].size())
	{
		int cp = g[s][i].lhs;
		int cc = g[s][i].rhs;

		if (vis[cp]) continue;

		vis[cp] = true;
		DFS(cp, d + cc, g, vis, maxDis, maxDisVertex);
	}
}

// 트리의 지름
int main()
{
	init;

	// 트리의 지름
	// 1.트리에서 임의의 정점 x를 찾는다
	// 2.정점 x에서 가장 먼 정점 y를 찾는다
	// 3.정점 y에서 가장 먼 정점 z를 찾는다
	// y와 z 사이 거리가 트리의 지름이된다
	
	int n; cin >> n;
	gmat(pii, graph, n);
	vec(bool, vis, n);
	int v1, v2, c;
	loop(i, home, n)
	{
		cin >> v1;
		--v1;

		while (true)
		{
			cin >> v2;
			if (v2 == -1) break;
			cin >> c;

			graph[v1].push_back({ --v2, c });
			graph[v2].push_back({ v1, c });
		}
	}

	int x = home, y, z, yMaxDis = -2147000000, zMaxDis = -2147000000;
	vis[x] = true;
	DFS(x, home, graph, vis, yMaxDis, y);
	loop(i, home, n) vis[i] = false;
	vis[y] = true;
	DFS(y, home, graph, vis, zMaxDis, z);
	elp(zMaxDis);

	return home;
}