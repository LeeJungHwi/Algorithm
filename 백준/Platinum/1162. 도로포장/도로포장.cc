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

// 도로포장
int main()
{
	init;

	ll n, m, k; cin >> n >> m >> k;
	gmat(pll, graph, n);
	ll v1, v2, c;
	loop(i, home, m)
	{
		cin >> v1 >> v2 >> c;
		graph[--v1].push_back({ --v2, c });
		graph[v2].push_back({ v1, c });
	}

	priority_queue < pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater< pair<ll, pair<ll, ll>>>> pq;
	vector<vector<ll>> dis(n, vector<ll>(k + 1, LLONG_MAX)); // dis[i][j] => 1 -> i 까지 j번 포장해서 가는 최단거리

	pq.push({ home, {home, home} }); // 비용, 정점, 포장 횟수
	dis[home][home] = home;

	while (!pq.empty())
	{
		ll sp = pq.top().rhs.lhs;
		ll sc = pq.top().lhs;
		ll cnt = pq.top().rhs.rhs;
		pq.pop();

		if (dis[sp][cnt] < sc) continue;

		loop(i, home, graph[sp].size())
		{
			ll cp = graph[sp][i].lhs;
			ll cc = graph[sp][i].rhs;

			// 포장 X
			if (dis[cp][cnt] > dis[sp][cnt] + cc)
			{
				dis[cp][cnt] = dis[sp][cnt] + cc;
				pq.push({ dis[cp][cnt] , {cp, cnt} });
			}

			// 포장 
			if (cnt < k && dis[cp][cnt + 1] > dis[sp][cnt])
			{
				dis[cp][cnt + 1] = dis[sp][cnt];
				pq.push({ dis[cp][cnt + 1], {cp, cnt + 1 } });
			}
		}
	}

	// 1 -> n 까지 k번 이하로 포장해서 가는 경로중 최단경로
	ll ans = LLONG_MAX;
	loop(i, home, k + 1) ans = min(ans, dis[n - 1][i]);
	elp(ans);

	return home;
}