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

// 탈출
int main()
{
	init;

	// 물 멀티 소스 BFS
	// 고슴도치 BFS
	// 비버의 굴 만나면 탈출(비버 굴은 물이 차지 않음)
	// 물이 더 빠르게 도착하거나 동시에 도착하면 X

	int n, m; cin >> n >> m;
	mat(char, graph, n, m);
	mat(int, dis, n, m);
	queue<pii> cp; dir;
	pii sPos;
	loop(i, home, n) loop(j, home, m)
	{
		cin >> graph[i][j];
		
		// 물 멀티 소스 BFS
		if (graph[i][j] == '*')
		{
			cp.push({ i, j });
			dis[i][j] = 1;
		}
		// 고슴도치 위치
		else if (graph[i][j] == 'S') sPos = { i, j };
	}

	// 물 멀티 소스 BFS
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
			if (graph[ci][cj] == 'X') continue;
			// 비버 굴은 물이 차지 않음
			if (graph[ci][cj] == 'D') continue;

			cp.push({ ci, cj });
			dis[ci][cj] = dis[si][sj] + 1;
		}
	}

	// 고슴도치 BFS
	cp.push(sPos);
	dis[sPos.lhs][sPos.rhs] = 1;

	while (!cp.empty())
	{
		int si = cp.front().lhs;
		int sj = cp.front().rhs;
		cp.pop();

		// 비버 굴 만나면 탈출
		if (graph[si][sj] == 'D')
		{
			elp(dis[si][sj] - 1);
			return home;
		}

		loop(i, home, 4)
		{
			int ci = si + cd[i].lhs;
			int cj = sj + cd[i].rhs;

			if (ci < home || cj < home || ci >= n || cj >= m) continue;
			// 물이 더 빠르게 도착하거나 동시에 도착하면 X
			if (dis[ci][cj] > home && dis[ci][cj] <= dis[si][sj] + 1) continue;
			if (graph[ci][cj] == 'X') continue;

			cp.push({ ci, cj });
			dis[ci][cj] = dis[si][sj] + 1;
		}
	}
	elp("KAKTUS");

	return home;
}