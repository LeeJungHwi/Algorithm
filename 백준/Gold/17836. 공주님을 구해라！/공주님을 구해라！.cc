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
#define gmat(t, v, r) vector<vector<t> > v((r))
#define mat(t, v, r, c) vector<vector<t> > v((r), vector<t>((c)))
#define smat(t, v, r, c, s) vector<vector<vector<t> > > v((r), vector<vector<t>>((c), vector<t>((s))))

#define dir vector<pii> cd = { {-1, home}, {1, home}, { home, -1 }, { home, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } }
#define kdir vector<pii> kcd = { {-1, -2}, {-2, -1}, { -2, 1 }, { -1, 2 }, { 1, -2 }, { 2, -1 }, { 1, 2 }, { 2, 1 } }
#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX = 2147000000;
const int MIN = -2147000000;

// 공주님을 구해라!
int main()
{
	init;

	// T시간 안에 0,0 -> n-1,m-1로 이동
	// 1.그람검을 구하지 않는 경우 0,0 -> n-1,m-1 BFS
	// 2.그람검을 구하는 경우 0,0 -> 그람검 BFS + 그람검 -> n-1,m-1까지 거리
	// 1, 2중 최솟값, 불가능한 경우 Fail

	int n, m, t; cin >> n >> m >> t;
	mat(int, graph, n, m);
	mat(int, dis, n, m);
	queue<pii> cp; dir;
	pii swordPos = { -1, -1 }; // 그람검 위치
	loop(i, home, n) loop(j, home, m)
	{
		cin >> graph[i][j];
		if (graph[i][j] == 2) swordPos = { i, j };
	}

	cp.push({ home, home });
	dis[home][home] = 1;

	int ans = 2147000000; // 공주님을 구하는 최단시간

	// 1.그람검을 구하지 않는 경우 0,0 -> n-1,m-1 BFS
	while (!cp.empty())
	{
		int si = cp.front().lhs;
		int sj = cp.front().rhs;
		cp.pop();

		loop(i, home, 4)
		{
			int ci = si + cd[i].lhs;
			int cj = sj + cd[i].rhs;

			if (ci < home || cj < home || ci >= n || cj >= m) continue;
			if (dis[ci][cj] > home) continue;
			if (graph[ci][cj] == 1) continue;

			cp.push({ ci, cj });
			dis[ci][cj] = dis[si][sj] + 1;
		}
	}

	// T시간 안에 구할 수 있으면 최솟값 업데이트 => 거리가 업데이트 되어 있어야함
	if (dis[n - 1][m - 1] > home && dis[n - 1][m - 1] - 1 <= t) ans = min(ans, dis[n - 1][m - 1] - 1);

	// 거리 초기화
	loop(i, home, n) loop(j, home, m) dis[i][j] = home;

	// 2.그람검을 구하는 경우 0,0 -> 그람검 BFS + 그람검 -> n-1,m-1까지 거리
	cp.push({ home, home });
	dis[home][home] = 1;

	bool isSword = false; // 그람검을 구했는지 체크
	while (!cp.empty())
	{
		int si = cp.front().lhs;
		int sj = cp.front().rhs;
		cp.pop();

		// 그람검을 구한 경우 종료
		if (si == swordPos.lhs && sj == swordPos.rhs) { isSword = true; break; }

		loop(i, home, 4)
		{
			int ci = si + cd[i].lhs;
			int cj = sj + cd[i].rhs;

			if (ci < home || cj < home || ci >= n || cj >= m) continue;
			if (dis[ci][cj] > home) continue;
			if (graph[ci][cj] == 1) continue;

			cp.push({ ci, cj });
			dis[ci][cj] = dis[si][sj] + 1;
		}
	}

	// 그람검을 구한 경우 거리를 구해서 T시간 안에 구할 수 있으면 최솟값 업데이트
	if (isSword)
	{
		dis[swordPos.lhs][swordPos.rhs] += abs(swordPos.lhs - n + 1) + abs(swordPos.rhs - m + 1);
		if (dis[swordPos.lhs][swordPos.rhs] - 1 <= t) ans = min(ans, dis[swordPos.lhs][swordPos.rhs] - 1);
	}

	// ans가 업데이트 되지 않았으면 구할 수 없음
	if (ans == 2147000000) { elp("Fail"); return home; }

	// T시간 안에 구할 수 있으면 ans 출력
	elp(ans);

	return home;
}