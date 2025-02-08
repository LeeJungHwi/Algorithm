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

// 얼음 미로
int main()
{
	init;

	int n, m; cin >> m >> n;
	mat(char, graph, n, m);
	mat(int, dis, n, m);
	pii sPos, ePos;
	loop(i, home, n) loop(j, home, m)
	{
		cin >> graph[i][j];
		if (graph[i][j] == 'T') sPos = { i, j };
		else if (graph[i][j] == 'E') ePos = { i, j };
		dis[i][j] = 2147000000;
	}

	priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater< pair<int, pii>>> pq; dir;
	pq.push({ home, sPos });
	dis[sPos.lhs][sPos.rhs] = home;

	while (!pq.empty())
	{
		int si = pq.top().rhs.lhs, sj = pq.top().rhs.rhs, sc = pq.top().lhs; pq.pop();

		if (dis[si][sj] < sc) continue;

		loop(i, home, 4)
		{
			int ci = si, cj = sj, cc = sc;
			
			while (true)
			{
				// 같은 방향으로 한 칸씩 진행
				ci += cd[i].lhs;
				cj += cd[i].rhs;

				// 미끄러지다가 경계나 구멍을 만나면 X
				if (ci < home || cj < home || ci >= n || cj >= m) break;
				if (graph[ci][cj] == 'H') break;

				// 바위를 만나면 최단거리 업데이트, 힙에 추가 => 바위 직전에 멈춰서 다음 탐색 진행
				if (graph[ci][cj] == 'R')
				{
					ci -= cd[i].lhs;
					cj -= cd[i].rhs;

					if (dis[ci][cj] <= cc) break;

					dis[ci][cj] = cc;
					pq.push({ cc, {ci, cj} });
					break;
				}

				// 출구를 만나면 최단거리 업데이트, 힙에 추가 X => 탈출하면 다음 탐색 할 필요 없음
				if (graph[ci][cj] == 'E')
				{
					if (dis[ci][cj] <= cc) continue;
					dis[ci][cj] = cc;
					break;
				}

				// 한 칸씩 진행하면서 비용 누적
				cc += graph[ci][cj] - '0';
			}
		}
	}
	elp(cond(dis[ePos.lhs][ePos.rhs] == 2147000000, -1, dis[ePos.lhs][ePos.rhs]));

	return home;
}