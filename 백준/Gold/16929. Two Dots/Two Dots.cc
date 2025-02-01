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
dir;

bool dfs(int i, int j, int pI, int pJ, char c, vector<vector<char> > &g, vector<vector<bool> > &v)
{
	// 현재 점 방문
	v[i][j] = true;

	loop(k, home, 4)
	{
		int ci = i + cd[k].lhs;
		int cj = j + cd[k].rhs;

		if (ci < home || cj < home || ci >= n || cj >= m) continue;

		// 같은색 체크
		if (g[ci][cj] != c) continue;

		// 방문한 점 중 사이클 감지
		// 사이클 조건 => 부모점을 제외한 방문한 점을 만나면
		if (v[ci][cj] && (ci != pI || cj != pJ)) return true;

		// 방문체크
		if (v[ci][cj]) continue;

		// 방문한 점이 아니면 재귀
		if (dfs(ci, cj, i, j, c, g, v)) return true;
	}

	// 한 점에서의 탐색이 끝나도록 사이클을 찾지못했으면 방문해제
	v[i][j] = false;
	return false;
}

// Two Dots
int main()
{
	init;

	cin >> n >> m;
	mat(char, graph, n, m);
	mat(bool, vis, n, m);
	loop(i, home, n) loop(j, home, m) cin >> graph[i][j];

	// 각 점을 돌면서 사이클 찾음
	loop(i, home, n)
	{
		loop(j, home, m)
		{
			if (!vis[i][j])
			{
				// 각 점에서 시작해서 사이클이 존재하는 점을 찾으면 Yes
				if (dfs(i, j, -1, -1, graph[i][j], graph, vis))
				{
					elp("Yes");
					return home;
				}
			}
		}
	}

	// 모든 점을 돌았는데 사이클을 가진 점이 없으면 No
	elp("No");

	return home;
}