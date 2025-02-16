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

// 세금
int main()
{
	init;

	int n, m, k, s, d; cin >> n >> m >> k >> s >> d;
	gmat(pii, graph, n);
	int v1, v2, c;
	loop(i, home, m)
	{
		cin >> v1 >> v2 >> c;
		graph[--v1].push_back({ --v2, c });
		graph[v2].push_back({ v1, c });
	}

	priority_queue < pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq; // 비용, 정점, 간선 사용 횟수
	vector<vector<int>> dis(n, vector<int>(n, 2147000000)); // dis[i][j] => s -> i로 j개의 간선을 사용할 때 최단거리

	pq.push({ home, {s - 1, home} });
	dis[s - 1][home] = home;

	while (!pq.empty())
	{
		int sp = pq.top().rhs.lhs;
		int sc = pq.top().lhs;
		int cnt = pq.top().rhs.rhs;
		pq.pop();

		if (dis[sp][cnt] < sc) continue;

		loop(i, home, graph[sp].size())
		{
			int cp = graph[sp][i].lhs;
			int cc = graph[sp][i].rhs;

			if (cnt + 1 >= n || dis[cp][cnt + 1] <= dis[sp][cnt] + cc) continue;

			dis[cp][cnt + 1] = dis[sp][cnt] + cc;
			pq.push({ dis[cp][cnt + 1], {cp, cnt + 1} });
		}
	}

	// 인상 되지 않았을 때 세금
	int ans = 2147000000;
	loop(i, home, n) ans = min(ans, dis[d - 1][i]);
	elp(ans);

	// 1 ~ k 번 세금이 인상 되었을 때 세금
	int tax = home, inc;
	loop(i, home, k)
	{
		cin >> inc;

		ans = 2147000000;
		loop(j, home, n) ans = min(ans, dis[d - 1][j] + j * (tax + inc));
		elp(ans);

		tax += inc;
	}

	return home;
}