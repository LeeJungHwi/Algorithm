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

#define dir vector<pii> cd = { {-1, home}, {1, home}, { home, -1 }, { home, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } }
#define kdir vector<pii> kcd = { {-1, -2}, {-2, -1}, { -2, 1 }, { -1, 2 }, { 1, -2 }, { 2, -1 }, { 1, 2 }, { 2, 1 } }
#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX = 2147000000;
const int MIN = -2147000000;

// 시루의 백화점 구경
int main()
{
	init;

	// 모든 마네킹 위치(3)를큐에 넣고 멀티 소스 BFS => 거리 k까지만
	// 시루 위치(4) 부터 BFS 돌려서 의자(2)를 만나면 거리 출력
	// 의자를 만나지 못 했으면 -1

	int n, m, k; cin >> n >> m >> k;
	mat(int, graph, n, m);
	mat(int, dis, n, m);
	queue<pii> cp; dir;
	pii sPos;
	loop(i, home, n) loop(j, home, m)
	{
		cin >> graph[i][j];
		
		// 마네킹 위치들 큐에 넣기
		if (graph[i][j] == 3)
		{
			cp.push({ i, j });
			dis[i][j] = 1;
		}
		// 시루 위치 저장
		else if (graph[i][j] == 4) sPos = { i, j };
	}

	// 모든 마네킹 위치(3)를큐에 넣고 멀티 소스 BFS => 거리 k까지만
	while (!cp.empty())
	{
		int si = cp.front().lhs;
		int sj = cp.front().rhs;
		cp.pop();

		// 마네킹에서 거리 k까지만 확장
		if (dis[si][sj] > k) continue;

		loop(i, home, 4)
		{
			int ci = si + cd[i].lhs;
			int cj = sj + cd[i].rhs;

			if (ci < home || cj < home || ci >= n || cj >= m) continue;
			if (dis[ci][cj] > home) continue;
			// 마네킹 거리는 벽 검사 X

			cp.push({ ci, cj });
			dis[ci][cj] = dis[si][sj] + 1;
		}
	}
	
	// 시루 위치(4) 부터 BFS 돌려서 의자(2)를 만나면 거리 출력
	// 의자를 만나지 못 했으면 -1
	cp.push(sPos);
	dis[sPos.lhs][sPos.rhs] = 1;

	while (!cp.empty())
	{
		int si = cp.front().lhs;
		int sj = cp.front().rhs;
		cp.pop();

		// 의자(2)를 만나면 거리 출력
		if (graph[si][sj] == 2)
		{
			elp(dis[si][sj] - 1);
			return home;
		}

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
	// 의자를 만나지 못 했으면 -1
	elp(-1);

	return home;
}