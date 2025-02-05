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

// 게임
int main()
{
	init;

	// 위험구역이 아닌곳 => 비용 0
	// 위험구역인 곳 => 비용 1
	// 죽음구역인 곳 => 이동 X

	mat(int, graph, 501, 501);
	mat(int, dis, 501, 501);
	deque<pii> cp; dir;

	// 위험구역
	int n; cin >> n;
	while (n--)
	{
		pii p1, p2;
		cin >> p1.lhs >> p1.rhs >> p2.lhs >> p2.rhs;

		for (int i = min(p1.lhs, p2.lhs); i < max(p1.lhs, p2.lhs) + 1; i++)
		{
			for (int j = min(p1.rhs, p2.rhs); j < max(p1.rhs, p2.rhs) + 1; j++)
			{
				graph[i][j] = 1;
			}
		}
	}

	// 안전구역
	int m; cin >> m;
	while (m--)
	{
		pii p1, p2;
		cin >> p1.lhs >> p1.rhs >> p2.lhs >> p2.rhs;

		for (int i = min(p1.lhs, p2.lhs); i < max(p1.lhs, p2.lhs) + 1; i++)
		{
			for (int j = min(p1.rhs, p2.rhs); j < max(p1.rhs, p2.rhs) + 1; j++)
			{
				graph[i][j] = -1;
			}
		}
	}

	//for (auto a : graph)
	//{
	//	for (auto b : a)
	//	{
	//		scp(b);
	//	}
	//	elp(' ');
	//}

	// 원점부터
	cp.push_back({ home, home });
	dis[home][home] = 1;
	while (!cp.empty())
	{
		pii s = cp.front(); cp.pop_front();
		if (s.lhs == 500 && s.rhs == 500) { elp(dis[s.lhs][s.rhs] - 1); return home; }
		loop(i, home, 4)
		{
			int ci = s.lhs + cd[i].lhs;
			int cj = s.rhs + cd[i].rhs;
			if (ci < home || cj < home || ci >= 501 || cj >= 501) continue;
			if (dis[ci][cj] > home) continue;
			if (graph[ci][cj] == -1) continue;

			// 안전구역 => 비용 0, 앞에 추가
			// 위험구역 => 비용 1, 뒤에 추가
			dis[ci][cj] = cond(!graph[ci][cj], dis[s.lhs][s.rhs], dis[s.lhs][s.rhs] + 1);
			cond(!graph[ci][cj], cp.push_front({ ci, cj }), cp.push_back({ ci, cj }));
		}
	}
	elp(-1);

	return home;
}