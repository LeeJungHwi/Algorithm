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

int n, m;
priority_queue<pii, vector<pii>, greater<pii>> pq;

vector<int> MultiDijk(vector<int> &s, vector<vector<pii>> &g)
{
	vector<int> dis(n, 2147000000);

	loop(i, home, s.size())
	{
		pq.push({ home, s[i] });
		dis[s[i]] = home;
	}

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

	return dis;
}

// 집 구하기
int main()
{
	init;

	cin >> n >> m;
	gmat(pii, graph, n);
	int v1, v2, c;
	loop(i, home, m)
	{
		cin >> v1 >> v2 >> c;
		graph[--v1].push_back({ --v2, c });
		graph[v2].push_back({ v1, c });
	}

	int cnt, x, y;
	cin >> cnt >> x;
	vec(int, mcdo, cnt);
	loop(i, home, cnt) { cin >> mcdo[i]; mcdo[i]--; }
	cin >> cnt >> y;
	vec(int, star, cnt);
	loop(i, home, cnt) { cin >> star[i]; star[i]--; }

	vector<int> mcdoDis = MultiDijk(mcdo, graph);
	vector<int> starDis = MultiDijk(star, graph);

	// 맥세권인 정점 거리 + 스세권인 정점 거리의 최솟값
	int ans = 2147000000;
	loop(i, home, n)
	{
		// 맥도날드나 스타벅스가 위치한 정점은 집이 없음
		// mcdoDis[i] == 0 => 출발지가 맥도날드
		// starDis[i] == 0 => 출발지가 스타벅스
		if (mcdoDis[i] > home && starDis[i] > home && mcdoDis[i] <= x && starDis[i] <= y)
		{
			ans = min(ans, mcdoDis[i] + starDis[i]);
		}
	}
	elp(cond(ans == 2147000000, -1, ans));

	return home;
}