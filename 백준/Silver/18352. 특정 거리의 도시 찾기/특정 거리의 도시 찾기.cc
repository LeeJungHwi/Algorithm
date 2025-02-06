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

// 특정 거리의 도시 찾기
int main()
{
	init;

	int n, m, k, x; cin >> n >> m >> k >> x;
	gmat(pii, graph, n);
	int v1, v2;
	loop(i, home, m)
	{
		cin >> v1 >> v2;
		graph[--v1].push_back({ --v2, 1 });
	}
	vector<int> dis(n, 2147000000);

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ home, --x });
	dis[x] = home;

	while (!pq.empty())
	{
		int sp = pq.top().rhs;
		int sc = pq.top().lhs;
		pq.pop();

		if (dis[sp] < sc) continue;

		loop(i, home, graph[sp].size())
		{
			int cp = graph[sp][i].lhs;
			int cc = graph[sp][i].rhs;

			if (dis[cp] <= dis[sp] + cc) continue;

			dis[cp] = dis[sp] + cc;
			pq.push({ dis[cp], cp });
		}
	}

	tvec(int, ans);
	loop(i, home, n) if (dis[i] == k) ans.push_back(i + 1);
	sort(all(ans));
	if (ans.empty()) { elp(-1); return home; }
	loop(i, home, ans.size()) elp(ans[i]);

	return home;
}