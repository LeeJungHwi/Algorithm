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

// 불
int main()
{
	init;

	// 불 멀티 소스 BFS
	// 상근 BFS
	// 경계를 만나면 탈출

	int tc; cin >> tc;
	
	dir;
	while (tc--)
	{
		int m, n; cin >> m >> n;
		mat(char, graph, n, m);
		mat(int, dis, n, m);
		queue<pii> cp;
		pii sPos;
		loop(i, home, n) loop(j, home, m)
		{
			cin >> graph[i][j];

			// 불 멀티 소스 BFS
			if (graph[i][j] == '*')
			{
				cp.push({ i, j });
				dis[i][j] = 1;
			}
			// 상근 위치 저장
			else if (graph[i][j] == '@') sPos = { i, j };
		}

		// 불 멀티 소스 BFS
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
				if (graph[ci][cj] == '#') continue;

				cp.push({ ci, cj });
				dis[ci][cj] = dis[si][sj] + 1;
			}
		}

		// 상근 BFS
		cp.push(sPos);
		dis[sPos.lhs][sPos.rhs] = 1;
		bool isEscape = false;

		while (!cp.empty())
		{
			int si = cp.front().lhs;
			int sj = cp.front().rhs;
			cp.pop();

			loop(i, home, 4)
			{
				int ci = si + cd[i].lhs;
				int cj = sj + cd[i].rhs;

				// 경계를 만나면 탈출
				if (ci < home || cj < home || ci >= n || cj >= m)
				{
					elp(dis[si][sj]);
					isEscape = true;
					break;
				}

				// 불이 더 빨리 도착하거나 동시에 도착하면 X
				if (dis[ci][cj] > home && dis[ci][cj] <= dis[si][sj] + 1) continue;
				if (graph[ci][cj] == '#') continue;

				cp.push({ ci, cj });
				dis[ci][cj] = dis[si][sj] + 1;
			}

			if (isEscape) break;
		}

		if (isEscape) continue;
		elp("IMPOSSIBLE");
	}

	return home;
}