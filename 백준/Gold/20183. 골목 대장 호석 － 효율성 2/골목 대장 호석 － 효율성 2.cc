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

ll n, m, a, b, c;
priority_queue<pll, vector<pll>, greater<pll>> pq;

bool Check(ll s, vector<vector<pll>> &g, vector<ll> &d)
{
	loop(i, home, n) d[i] = LLONG_MAX;

	pq.push({ home, a - 1 });
	d[a - 1] = home;

	while (!pq.empty())
	{
		ll sp = pq.top().rhs;
		ll sc = pq.top().lhs;
		pq.pop();

		if (d[sp] < sc) continue;

		loop(i, home, g[sp].size())
		{
			ll cp = g[sp][i].lhs;
			ll cc = g[sp][i].rhs;

			// 가중치가 s를 초과하는 간선은 X
			if (cc > s) continue;
			if (d[cp] <= d[sp] + cc) continue;

			d[cp] = d[sp] + cc;
			pq.push({ d[cp], cp });
		}
	}

	// 가진 돈 c원 이하로 최단거리가 업데이트 되어있으면 가능한경우
	return d[b - 1] != LLONG_MAX && d[b - 1] <= c;
}

// 골목 대장 호석 - 효율성 2
int main()
{
	init;

	// 기준 => 간선의 가중치
	// lo => 1
	// hi => 간선의 가중치 최댓값
	// 최대 s 가중치 이하로 도달 할 수 있으면 가능한경우

	cin >> n >> m >> a >> b >> c;
	gmat(pll, graph, n);
	ll v1, v2, cost, l = 1, h = -LLONG_MAX;
	loop(i, home, m)
	{
		cin >> v1 >> v2 >> cost;
		graph[--v1].push_back({ --v2, cost });
		graph[v2].push_back({ v1, cost });
		h = max(h, cost);
	}
	vector<ll> dis(n, LLONG_MAX);

	ll ans = home;
	while (l <= h)
	{
		ll s = (l + h) / 2;

		if (Check(s, graph, dis))
		{
			ans = s;
			h = s - 1;
		}
		else l = s + 1;
	}
	elp(cond(ans == home, -1, ans));

	return home;
}