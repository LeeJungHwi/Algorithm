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

priority_queue<pii, vector<pii>, greater<pii>> pq;

void Dijk(int s, vector<int> &dis, vector<vector<pii>> &g)
{
	pq.push({ home, s });
	dis[s] = home;

	while (!pq.empty())
	{
		int sp = pq.top().rhs;
		int sc = pq.top().lhs;
		pq.pop();

		if (dis[sp] < sc) continue;

		loop(i, home, g[sp].size())
		{
			int cp = g[sp][i].lhs;
			int cc = g[sp][i].rhs;

			if (dis[cp] <= dis[sp] + cc) continue;

			dis[cp] = dis[sp] + cc;
			pq.push({ dis[cp], cp });
		}
	}
}

// 가장 먼 곳
int main()
{
	init;

	int n; cin >> n;
	vec(int, friendPos, 3);
	int num;
	loop(i, home, 3) { cin >> friendPos[i]; friendPos[i]--; }
	sort(all(friendPos));

	// base => 현재 살고있는 집 중 가장 작은 땅의 번호
	int ans = friendPos[home] + 1;
	int maxDis = home;

	gmat(pii, graph, n);
	int m, v1, v2, c; cin >> m;
	loop(i, home, m)
	{
		cin >> v1 >> v2 >> c;
		graph[--v1].push_back({ --v2, c });
		graph[v2].push_back({ v1, c });
	}

	// 각 친구집에서 다익스트라
	vector<int> dis1(n, 2147000000), dis2(n, 2147000000), dis3(n, 2147000000);
	Dijk(friendPos[home], dis1, graph);
	Dijk(friendPos[1], dis2, graph);
	Dijk(friendPos[2], dis3, graph);

	// 가장 가까운 친구의 집까지의 거리
	loop(i, home, n) dis1[i] = min({ dis1[i], dis2[i], dis3[i] });

	// 가장 가까운 친구의 집까지의 거리 중 최댓값
	loop(i, home, n)
	{
		if (maxDis < dis1[i])
		{
			maxDis = dis1[i];
			ans = i;
		}
	}
	elp(++ans);

	return home;
}