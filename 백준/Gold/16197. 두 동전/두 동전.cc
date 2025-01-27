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

// 두 동전
int main()
{
	init;

	int n, m; cin >> n >> m;
	mat(char, graph, n, m);
	mat(int, dis, n, m);
	pii c1 = { -1, -1 }, c2 = { -1, -1 };
	loop(i, home, n)
	{
		loop(j, home, m)
		{
			cin >> graph[i][j];
			if (graph[i][j] == 'o')
			{
				if (c1.lhs == -1) c1 = { i, j };
				else c2 = { i, j };
			}
		}
	}
	queue<pair<pair<int, int>, pair<int, int> > > cp; dir;
	map<pair<pair<int, int>, pair<int, int> >, int> vis;
	cp.push({ c1, c2 });
	vis[{c1, c2}]++;
	int moveCnt = home;

	// 동시에 떨어지면 X
	// 겹쳐지면 X
	// 10회 넘기면 X
	int ans = home;
	while (!cp.empty())
	{
		if (++moveCnt > 10) { elp(-1); return home; }

		int cpSize = cp.size();
		while (cpSize--)
		{
			pair<pair<int, int>, pair<int, int> > s = cp.front();
			cp.pop();

			loop(i, home, 4)
			{
				int ci1 = s.lhs.lhs + cd[i].lhs;
				int cj1 = s.lhs.rhs + cd[i].rhs;
				int ci2 = s.rhs.lhs + cd[i].lhs;
				int cj2 = s.rhs.rhs + cd[i].rhs;

				int fallCnt = home;
				if (ci1 < home || cj1 < home || ci1 >= n || cj1 >= m) fallCnt++;
				if (ci2 < home || cj2 < home || ci2 >= n || cj2 >= m) fallCnt++;

				// 하나만 떨어짐
				if (fallCnt == 1) { elp(moveCnt); return home; }

				// 동시에 떨어지면 X
				if (fallCnt == 2) continue;

				// 둘다 안떨어짐
				// 벽 체크 => 제자리
				if (graph[ci1][cj1] == '#')
				{
					ci1 = s.lhs.lhs;
					cj1 = s.lhs.rhs;
				}
				if (graph[ci2][cj2] == '#')
				{
					ci2 = s.rhs.lhs;
					cj2 = s.rhs.rhs;
				}

				// 겹쳐지면 X
				if (ci1 == ci2 && cj1 == cj2) continue;

				// 방문체크
				if (vis[{ {ci1, cj1}, { ci2, cj2 }}] > home) continue;

				cp.push({ {ci1, cj1}, {ci2, cj2} });
				vis[{ {ci1, cj1}, { ci2, cj2 }}]++;
			}
		}
	}
	elp(-1);

	return home;
}