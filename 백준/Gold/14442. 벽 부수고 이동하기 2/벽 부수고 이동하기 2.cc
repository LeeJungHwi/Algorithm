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

// 벽 부수고 이동하기 2
int main()
{
	init;

	// 0,0 -> n - 1,m - 1로 가는 최단거리
	// 벽을 k번 까지 부술 수 있음
	// BFS 내부에서 벽을 부수는 경우와 벽을 부수지 않는 경우로 뻗어나감
	
	int n, m, k; cin >> n >> m >> k;
	mat(char, graph, n, m);
	smat(int, dis, n, m, k + 1); // dis[i][j][k] => i,j 까지 k번 벽을 부셔서 오는 최단거리
	queue<piii> cp; dir; // (벽 부순 횟수, 위치)
	loop(i, home, n) loop(j, home, m) cin >> graph[i][j];

	cp.push({ home, {home, home} });
	dis[home][home][home] = 1;

	while (!cp.empty())
	{
		int si = cp.front().rhs.lhs;
		int sj = cp.front().rhs.rhs;
		int sc = cp.front().lhs;
		cp.pop();

		// 도착
		if (si == n - 1 && sj == m - 1)
		{
			elp(dis[si][sj][sc]);
			return home;
		}

		loop(i, home, 4)
		{
			int ci = si + cd[i].lhs;
			int cj = sj + cd[i].rhs;

			if (ci < home || cj < home || ci >= n || cj >= m) continue;
			if (dis[ci][cj][sc] > home) continue;

			// 벽을 부수는 경우
			if (graph[ci][cj] == '1')
			{
				if (sc < k)
				{
					if (dis[ci][cj][sc + 1] > home) continue;

					cp.push({ sc + 1, {ci, cj} });
					dis[ci][cj][sc + 1] = dis[si][sj][sc] + 1;
				}

				continue;
			}

			// 벽을 부수지 않는 경우
			cp.push({ sc, {ci, cj} });
			dis[ci][cj][sc] = dis[si][sj][sc] + 1;
		}
	}
	elp(-1);

	return home;
}