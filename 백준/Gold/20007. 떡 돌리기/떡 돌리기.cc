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

// 떡 돌리기
int main()
{
	init;

	// 성현이 집에서 다익스트라
	// 가장 가까운 집부터 sum에 누적
	// sum이 x를 초과하면 일 수 카운팅
	// 왕복 최단거리가 x를 초과하는 경우 -1
	int n, m, x, y; cin >> n >> m >> x >> y;

	gmat(pii, graph, n);
	int v1, v2, c;
	loop(i, home, m)
	{
		cin >> v1 >> v2 >> c;
		graph[v1].push_back({ v2, c });
		graph[v2].push_back({ v1, c });
	}
	vector<int> dis(n, 2147000000);

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ home, y });
	dis[y] = home;

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
	
	// 가장 가까운 집부터 sum에 누적
	// sum이 x를 초과하면 일 수 카운팅
	// 왕복 최단거리가 x를 초과하는 경우 -1
	sort(all(dis));
	int ans = 1, sum = home;
	loop(i, home, dis.size())
	{
		if (dis[i] * 2 > x)
		{
			elp(-1);
			return home;
		}

		if (sum + dis[i] * 2 > x)
		{
			sum = dis[i] * 2;
			ans++;
			continue;
		}

		sum += dis[i] * 2;
	}
	elp(ans);

	return home;
}