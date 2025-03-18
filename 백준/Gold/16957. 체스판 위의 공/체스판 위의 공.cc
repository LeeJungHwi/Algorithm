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

vector<vector<pii>> unf(501, vector<pii>(501)); // 각 위치의 최종 위치

pii Find(pii p)
{
	if (unf[p.lhs][p.rhs] == p) return p;
	return unf[p.lhs][p.rhs] = Find(unf[p.lhs][p.rhs]);
}

void Union(pii p1, pii p2)
{
	p1 = Find(p1);
	p2 = Find(p2);
	if (p1 != p2) unf[p1.lhs][p1.rhs] = p2;
}

// 체스판 위의 공
int main()
{
	init;

	// 그래프 돌면서 각 위치 포함 8방향에 대해 가장 작은 정수 위치 찾아서 유니온 => 각 집합의 최종 위치들이 저장됨
	// 각 위치에 대해 파인드 => 최종 위치의 공 개수 카운팅
	int n, m; cin >> n >> m;
	mat(int, graph, n, m); dir;
	loop(i, home, n) loop(j, home, m)
	{
		cin >> graph[i][j];
		unf[i][j] = { i, j };
	}

	// 그래프 돌면서 각 위치 포함 8방향에 대해 가장 작은 정수 위치와 값 메모
	loop(i, home, n) loop(j, home, m)
	{
		int mmin = graph[i][j];
		pii minPos = { i, j };
		loop(k, home, 8)
		{
			int ci = i + cd[k].lhs;
			int cj = j + cd[k].rhs;

			if (ci < home || cj < home || ci >= n || cj >= m) continue;

			if (mmin > graph[ci][cj])
			{
				mmin = graph[ci][cj];
				minPos = { ci, cj };
			}
		}

		Union({ i, j }, minPos);
	}

	// 각 위치에 대해 파인드 => 최종 위치의 공 개수 카운팅
	mat(int, ans, n, m);
	loop(i, home, n) loop(j, home, m)
	{
		pii desPos = Find({ i, j });
		ans[desPos.lhs][desPos.rhs]++;
	}

	for (auto a : ans)
	{
		for (auto b : a)
		{
			scp(b);
		}
		cout << '\n';
	}

	return home;
}