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

// 면접보는 승범이네
int main()
{
	init;

	// 불특정 면접장까지의 거리가 가장 가까운 면접자의 도시 거리 중 최댓값을 가지는 도시
	// 멀티 소스 다익스트라

	int n, m, k; cin >> n >> m >> k;
	gmat(pii, graph, n);
	int v1, v2, c;
	loop(i, home, m)
	{
		cin >> v1 >> v2 >> c;

		// 도착 정점인 면접장부터 출발하므로 간선 방향 반대
		graph[--v2].push_back({ --v1, c });
	}
	
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	vector<ll> dis(n, LLONG_MAX);
	loop(i, home, k)
	{
		cin >> v1;
		pq.push({ home , --v1 });
		dis[v1] = home;
	}

	ll maxDis = -LLONG_MAX;
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

	int maxCity = -1;
	loop(i, home, n)
	{
		if (maxDis < dis[i])
		{
			maxDis = dis[i];
			maxCity = i;
		}
	}
	elp(++maxCity);
	elp(maxDis);

	return home;
}