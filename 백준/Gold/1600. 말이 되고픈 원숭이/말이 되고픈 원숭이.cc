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
#define kDir vector<pii> kcd = { {-1, -2}, {-2, -1}, { -2, 1 }, { -1, 2 }, { 1, -2 }, { 2, -1 }, { 1, 2 }, { 2, 1 } }
#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX = 2147000000;
const int MIN = -2147000000;

// 말이 되고픈 원숭이
int main()
{
	init;

	// 나이트 이동 k번 => 나이트 이동 횟수 상태 추가
	// BFS 내부에서 나이트 이동과 상하좌우 이동으로 가지 뻗음

	int k, m, n; cin >> k >> m >> n;
	mat(int, graph, n, m);
	loop(i, home, n) loop(j, home, m) cin >> graph[i][j];
	vector<vector<vector<int>>> dis(n, vector<vector<int>>(m, vector<int>(k + 1))); // dis[i][j][k] => i, j까지 k번 나이트 이동했을 때 최단거리
	queue<pair<pii, int>> cp; dir; kDir; // (위치, 나이트 이동 횟수)

	cp.push({ {home, home}, home });
	dis[home][home][home] = 1;

	while (!cp.empty())
	{
		int si = cp.front().lhs.lhs;
		int sj = cp.front().lhs.rhs;
		int sc = cp.front().rhs;
		cp.pop();

		// 나이트 이동
		if (sc < k)
		{
			loop(i, home, 8)
			{
				int ci = si + kcd[i].lhs;
				int cj = sj + kcd[i].rhs;
				int cc = sc + 1;

				if (ci < home || cj < home || ci >= n || cj >= m) continue;
				if (dis[ci][cj][cc] > home) continue;
				if (graph[ci][cj] == 1) continue;

				cp.push({ {ci, cj}, cc });
				dis[ci][cj][cc] = dis[si][sj][sc] + 1;
			}
		}

		// 상하좌우 이동
		loop(i, home, 4)
		{
			int ci = si + cd[i].lhs;
			int cj = sj + cd[i].rhs;
			int cc = sc;

			if (ci < home || cj < home || ci >= n || cj >= m) continue;
			if (dis[ci][cj][cc] > home) continue;
			if (graph[ci][cj] == 1) continue;

			cp.push({ {ci, cj}, cc });
			dis[ci][cj][cc] = dis[si][sj][sc] + 1;
		}
	}

	// 나이트 이동 횟수에 따라 n - 1, m - 1로 가는 최단거리 업데이트
	int ans = 2147000000;
	loop(i, home, k + 1) if (dis[n - 1][m - 1][i] > home) ans = min(ans, dis[n - 1][m - 1][i]);
	elp(cond(ans == 2147000000, -1, ans - 1));

	return home;
}