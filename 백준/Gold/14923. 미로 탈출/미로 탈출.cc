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

// 미로 탈출
int main()
{
	init;

	// 홍익 위치 -> 탈출 위치로 가는 최단거리
	// 벽을 한 번만 길로 바꿀 수 있음
	// BFS 내부에서 벽을 길로 바꾸는 경우와 벽을 길로 바꾸지 않는 경우로 뻗어나감

	int n, m; cin >> n >> m;
	pii sPos, ePos;
	cin >> sPos.lhs >> sPos.rhs; sPos.lhs--; sPos.rhs--;
	cin >> ePos.lhs >> ePos.rhs; ePos.lhs--; ePos.rhs--;
	mat(int, graph, n, m);
	smat(int, dis, n, m, 2); // dis[i][j][k] => i,j까지 오는데 벽을 k번 길로 바꿨을 때 최단거리
	queue<piii> cp; dir; // (벽을 길로 바꾼 횟수, 위치)
	loop(i, home, n) loop(j, home, m) cin >> graph[i][j];

	cp.push({ home, sPos });
	dis[sPos.lhs][sPos.rhs][home] = 1;

	while (!cp.empty())
	{
		int si = cp.front().rhs.lhs;
		int sj = cp.front().rhs.rhs;
		int sc = cp.front().lhs;
		cp.pop();

		// 탈출 위치 도착
		if (si == ePos.lhs && sj == ePos.rhs)
		{
			elp(dis[si][sj][sc] - 1);
			return home;
		}

		loop(i, home, 4)
		{
			int ci = si + cd[i].lhs;
			int cj = sj + cd[i].rhs;

			if (ci < home || cj < home || ci >= n || cj >= m) continue;
			if (dis[ci][cj][sc] > home) continue;
			
			// 벽을 길로 바꾸는 경우
			if (graph[ci][cj] == 1)
			{
				// 아직 벽을 길로 바꾼적이 없으면
				if (sc == home)
				{
					cp.push({ 1, {ci, cj} });
					dis[ci][cj][1] = dis[si][sj][sc] + 1;
				}
				
				continue;
			}

			// 벽을 길로 바꾸지 않는 경우
			cp.push({ sc, {ci, cj} });
			dis[ci][cj][sc] = dis[si][sj][sc] + 1;
		}
	}
	elp(-1);

	return home;
}