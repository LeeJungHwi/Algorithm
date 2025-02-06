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

// 서강그라운드
int main()
{
	init;

	// 각 정점에서 다른 정점간 최단거리가 수색범위 이하인곳의 아이템 수 합의 최댓값 => 플로이드

	int n, m, r; cin >> n >> m >> r;
	vec(int, item, n + 1);
	loop(i, 1, n + 1) cin >> item[i];
	mat(int, graph, n + 1, n + 1);
	loop(i, home, n + 1) loop(j, home, n + 1) graph[i][j] = 1000000000;
	int v1, v2, c;
	loop(i, home, r)
	{
		cin >> v1 >> v2 >> c;
		graph[v1][v2] = c;
		graph[v2][v1] = c;
	}
	loop(i, home, n + 1) graph[i][i] = home;

	loop(k, 1, n + 1) loop(i, 1, n + 1) loop(j, 1, n + 1) graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

	int ans = -2147000000;
	loop(i, 1, n + 1)
	{
		int itemCnt = item[i];
		loop(j, 1, n + 1)
		{
			if (i == j) continue;

			if (m >= graph[i][j]) itemCnt += item[j];
		}

		ans = max(ans, itemCnt);
	}
	elp(ans);

	return home;
}