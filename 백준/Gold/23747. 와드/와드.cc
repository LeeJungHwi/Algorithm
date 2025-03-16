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
#define piii pair<int, pii>
#define pll pair<ll, ll>
#define plll pair<ll, pll>

#define loop(v, s, e) for(int v = (s); v < (e); v++)
#define rloop(v, s, e) for(int v = (s); v > (e); v--)
#define mloop(v, a) for(auto v = (a).begin(); v != (a).end(); v++)
#define mrloop(v, a) for(auto v = (a).rbegin(); v != (a).rend(); v++)

#define p(a) cout << (a)
#define elp(a) cout << (a) << '\n'
#define scp(a) cout << (a) << ' '

#define tvec(t, v) vector<t> v
#define vec(t, v, r) vector<t> v((r))
#define ivec(t, v, r, i) vector<t> v((r), i)
#define gmat(t, v, r) vector<vector<t> > v((r))
#define mat(t, v, r, c) vector<vector<t> > v((r), vector<t>((c)))
#define imat(t, v, r, c, i) vector<vector<t> > v((r), vector<t>((c), i))
#define smat(t, v, r, c, s) vector<vector<vector<t> > > v((r), vector<vector<t>>((c), vector<t>((s))))
#define ismat(t, v, r, c, s, i) vector<vector<vector<t> > > v((r), vector<vector<t>>((c), vector<t>((s), i)))
#define ssmat(t, v, r, c, s1, s2) vector<vector<vector<vector<t> > > > v((r), vector<vector<vector<t>>>((c), vector<vector<t>>((s1), vector<t>((s2)))))
#define issmat(t, v, r, c, s1, s2, i) vector<vector<vector<vector<t> > > > v((r), vector<vector<vector<t>>>((c), vector<vector<t>>((s1), vector<t>((s2), i))))
#define sssmat(t, v, r, c, s1, s2, s3) vector<vector<vector<vector<vector<t> > > > > v((r), vector<vector<vector<vector<t>>>>((c), vector<vector<vector<t>>>((s1), vector<vector<t>>((s2), vector<t>((s3))))))
#define isssmat(t, v, r, c, s1, s2, s3, i) vector<vector<vector<vector<vector<t> > > > > v((r), vector<vector<vector<vector<t>>>>((c), vector<vector<vector<t>>>((s1), vector<vector<t>>((s2), vector<t>((s3), i)))))

#define dir vector<pii> cd = { {-1, home}, {1, home}, { home, -1 }, { home, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } }
#define kdir vector<pii> kcd = { {-1, -2}, {-2, -1}, { -2, 1 }, { -1, 2 }, { 1, -2 }, { 2, -1 }, { 1, 2 }, { 2, 1 } }
#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX = 2147000000;
const int MIN = -2147000000;

// 와드
int main()
{
	init;

	int n, m; cin >> n >> m;
	mat(char, graph, n, m);
	queue<pii> cp; dir;
	map<char, pii> d = { {'U', {-1, home}}, {'D', {1, home}}, {'L', {home, -1}}, {'R', {home, 1}} };
	loop(i, home, n) loop(j, home, m) cin >> graph[i][j];
	pii sPos; cin >> sPos.lhs >> sPos.rhs; sPos.lhs--; sPos.rhs--;
	string is; cin >> is;

	loop(i, home, is.size())
	{
		// 와드 => 인접한 같은 문자의 시야를 밝힘
		if (is[i] == 'W')
		{
			// 이미 시야가 밝혀진 곳은 X
			if (graph[sPos.lhs][sPos.rhs] == '.') continue;

			char c = graph[sPos.lhs][sPos.rhs];
			cp.push(sPos);
			graph[sPos.lhs][sPos.rhs] = '.';

			while (!cp.empty())
			{
				int si = cp.front().lhs;
				int sj = cp.front().rhs;
				cp.pop();

				loop(j, home, 4)
				{
					int ci = si + cd[j].lhs;
					int cj = sj + cd[j].rhs;

					if (ci < home || cj < home || ci >= n || cj >= m) continue;
					if (graph[ci][cj] != c) continue;

					cp.push({ ci, cj });
					graph[ci][cj] = '.';
				}
			}
		}
		// 위치 이동
		else
		{
			int ci = sPos.lhs + d[is[i]].lhs;
			int cj = sPos.rhs + d[is[i]].rhs;

			if (ci < home || cj < home || ci >= n || cj >= m) continue;

			sPos.lhs = ci;
			sPos.rhs = cj;
		}
	}

	// 마지막 위치와 상하좌우 한칸의 시야를 밝힘
	graph[sPos.lhs][sPos.rhs] = '.';
	loop(i, home, 4)
	{
		int ci = sPos.lhs + cd[i].lhs;
		int cj = sPos.rhs + cd[i].rhs;

		if (ci < home || cj < home || ci >= n || cj >= m) continue;

		graph[ci][cj] = '.';
	}

	// .이 아닌 곳은 #
	for (auto a : graph)
	{
		for (auto b : a)
		{
			p(cond(b == '.', '.', '#'));
		}
		cout << '\n';
	}

	return home;
}