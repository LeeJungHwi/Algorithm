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

// 농장 관리
int main()
{
	init;

	// 봉우리 => 인접한 정점 8개의 정점 집합 중 자신보다 높은 높이를 가지는 정점 집합이 있으면 안됨
	// 같은 높이의 정점은 하나의 봉우리 집합으로침

	int n, m; cin >> n >> m;
	mat(int, graph, n, m);
	mat(bool, vis, n, m);
	loop(i, home, n) loop(j, home, m) cin >> graph[i][j];
	queue<pii> cp; dir;

	int ans = home; // 봉우리 개수
	loop(i, home, n) loop(j, home, m) if (!vis[i][j] && graph[i][j] > home)
	{
		cp.push({ i, j });
		vis[i][j] = true;
		bool isPeek = true; // 현재 정점이 봉우리인지 체크

		// 현재 정점과 인접한 8개의 정점 집합 체크
		while (!cp.empty())
		{
			int si = cp.front().lhs;
			int sj = cp.front().rhs;
			cp.pop();

			loop(k, home, 8)
			{
				int ci = si + cd[k].lhs;
				int cj = sj + cd[k].rhs;

				if (ci < home || cj < home || ci >= n || cj >= m) continue;
				if (graph[ci][cj] > graph[si][sj]) isPeek = false; // 현재 봉우리보다 높은 정점 집합이 있으면 봉우리 X
				if (vis[ci][cj]) continue;
				if (graph[ci][cj] != graph[i][j]) continue; // 현재 방향의 정점과 같은 높이로 연결된 정점은 같은 봉우리 집합

				cp.push({ ci, cj });
				vis[ci][cj] = true;
			}
		}

		if (isPeek) ans++; // 현재 정점이 봉우리인 경우 카운팅
	}
	elp(ans);

	return home;
}