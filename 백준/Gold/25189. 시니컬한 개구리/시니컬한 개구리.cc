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

// 시니컬한 개구리
int main()
{
	init;

	// sPos -> ePos 최단거리
	// 개구리밥을 한번 무시할 수 있음 => 상하좌우로 원하는 칸만큼 이동
	// BFS 내부에서 개구리밥을 무시하는 경우와 개구리밥을 무시하지 않는 경우로 뻗어나감
	int n, m; cin >> n >> m;
	pii sPos, ePos;
	cin >> sPos.lhs >> sPos.rhs >> ePos.lhs >> ePos.rhs;
	sPos.lhs--; sPos.rhs--; ePos.lhs--; ePos.rhs--;
	mat(int, graph, n, m);
	smat(bool, vis, n, m, 2); // vis[i][j][k] => i,j로 k번 개구리밥을 무시하고 방문
	vec(bool, visI, n); // visI[i] => i번째 행에서 개구리밥을 무시함
	vec(bool, visJ, m); // visI[i] => i번째 열에서 개구리밥을 무시함
	loop(i, home, n) loop(j, home, m) cin >> graph[i][j];
	queue<pair<pii, pii>> cp; dir; // (개구리밥 무시 횟수, 점프 횟수, 위치)

	cp.push({ {home, home}, sPos });
	vis[sPos.lhs][sPos.rhs][home] = true;

	while (!cp.empty())
	{
		int si = cp.front().rhs.lhs;
		int sj = cp.front().rhs.rhs;
		int sc = cp.front().lhs.lhs;
		int sp = cp.front().lhs.rhs;
		cp.pop();

		// 도착
		if (si == ePos.lhs && sj == ePos.rhs)
		{
			elp(sp);
			return home;
		}

		// 개구리밥을 무시하는 경우 => 경계를 만날 떄 까지 점프
		if (sc == home)
		{
			// 상하
			if (!visJ[sj])
			{
				loop(i, home, 2)
				{
					int ci = si;
					int cj = sj;

					while (true)
					{
						ci += cd[i].lhs;
						cj += cd[i].rhs;

						if (ci < home || cj < home || ci >= n || cj >= m) break;
						if (vis[ci][cj][sc + 1]) continue;

						cp.push({ {sc + 1, sp + 1}, {ci, cj} });
						vis[ci][cj][sc + 1] = true;
					}
				}

				visJ[sj] = true;
			}

			// 좌우
			if (!visI[si])
			{
				loop(i, 2, 4)
				{
					int ci = si;
					int cj = sj;

					while (true)
					{
						ci += cd[i].lhs;
						cj += cd[i].rhs;

						if (ci < home || cj < home || ci >= n || cj >= m) break;
						if (vis[ci][cj][sc + 1]) continue;

						cp.push({ {sc + 1, sp + 1}, {ci, cj} });
						vis[ci][cj][sc + 1] = true;
					}
				}

				visI[si] = true;
			}
		}

		loop(i, home, 4)
		{
			// 개구리밥을 무시하지 않는 경우 => 그래프 크기 만큼 점프
			int ci = si + cd[i].lhs * graph[si][sj];
			int cj = sj + cd[i].rhs * graph[si][sj];

			if (ci < home || cj < home || ci >= n || cj >= m) continue;
			if (vis[ci][cj][sc]) continue;

			cp.push({ {sc, sp + 1}, {ci, cj} });
			vis[ci][cj][sc] = true;
		}
	}
	elp(-1);

	return home;
}