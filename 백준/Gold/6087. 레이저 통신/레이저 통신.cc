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

// 레이저 통신
int main()
{
	init;

	// 거울 설치 횟수 최단거리 => 다익스트라

	int n, m; cin >> m >> n;
	mat(char, graph, n, m);
	mat(int, dis, n, m);
	tvec(pii, cPos);
	loop(i, home, n) loop(j, home, m)
	{
		cin >> graph[i][j];
		if (graph[i][j] == 'C') cPos.push_back({ i, j });
		dis[i][j] = 2147000000;
	}

	pii sPos = cPos[home], ePos = cPos[1];

	priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq; dir; // (거울 수, cp)
	dis[sPos.lhs][sPos.rhs] = home;
	pq.push({ home, sPos });

	while (!pq.empty())
	{
		int si = pq.top().rhs.lhs;
		int sj = pq.top().rhs.rhs;
		int sc = pq.top().lhs;
		pq.pop();

		if (si == ePos.lhs && sj == ePos.rhs)
		{
			elp(--sc);
			return home;
		}

		if (dis[si][sj] < sc) continue;

		loop(i, home, 4)
		{
			int ci = si;
			int cj = sj;
			int cc = sc;

			// 벽, 경계를 만나기 전까지 같은 방향으로 한 칸씩 진행하면서 거울 설치
			while (true)
			{
				ci += cd[i].lhs;
				cj += cd[i].rhs;

				if (ci < home || cj < home || ci >= n || cj >= m) break;
				if (graph[ci][cj] == '*') break;
				if (dis[ci][cj] <= cc + 1) continue;

				dis[ci][cj] = cc + 1;
				pq.push({ cc + 1, {ci, cj} });
			}
		}
	}

	return home;
}