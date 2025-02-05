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

// 가운데에서 만나기
int main()
{
	init;

	int n, m; cin >> n >> m;
	mat(int, graph, n + 1, n + 1);
	loop(i, home, n + 1) loop(j, home, n + 1) graph[i][j] = 1000000000;
	int v1, v2, c;
	loop(i, home, m)
	{
		cin >> v1 >> v2 >> c;
		graph[v1][v2] = c;
	}
	loop(i, home, n + 1) graph[i][i] = home;

	loop(k, 1, n + 1)
	{
		loop(i, 1, n + 1)
		{
			loop(j, 1, n + 1)
			{
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	
	int k; cin >> k;
	vec(int, friendPos, k);
	loop(i, home, k) cin >> friendPos[i];

	tvec(int, ans);
	int minMaxDis = 2147000000; // 왕복시간 최대 중 최소

	loop(i, 1, n + 1)
	{
		int maxDis = -2147000000; // 왕복시간 최대
		bool isCycle = true;

		loop(j, home, friendPos.size())
		{
			// 사이클 안 되면 X
			if (graph[friendPos[j]][i] == 1000000000 || graph[i][friendPos[j]] == 1000000000)
			{
				isCycle = false;
				break;
			}

			maxDis = max(maxDis, graph[friendPos[j]][i] + graph[i][friendPos[j]]);
		}

		// 사이클 안 되는 도시면 X
		if (!isCycle) continue;

		if (minMaxDis > maxDis)
		{
			minMaxDis = maxDis;
			ans.clear();
			ans.push_back(i);
		}
		else if (minMaxDis == maxDis) ans.push_back(i);
	}
	sort(all(ans));
	loop(i, home, ans.size()) scp(ans[i]);

	return home;
}