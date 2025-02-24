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

// 벽 부수고 이동하기 4
int main()
{
	init;

	// 이동할 수 있는 위치에서 BFS 돌려서 영역 내 이동할 수 있는 위치의 수를 만나는 벽에 카운팅

	int n, m; cin >> n >> m;
	mat(int, graph, n, m);
	mat(bool, vis, n, m);
	queue<pii> cp; dir;
	tvec(pii, sPos);
	string is;
	loop(i, home, n)
	{
		cin >> is;
		loop(j, home, m)
		{
			graph[i][j] = is[j] - '0';
			if (graph[i][j] == home) sPos.push_back({ i, j });
		}
	}

	loop(i, home, sPos.size())
	{
		// 이미 카운팅에 사용된 위치는 X
		if (vis[sPos[i].lhs][sPos[i].rhs]) continue;

		cp.push(sPos[i]);
		vis[sPos[i].lhs][sPos[i].rhs] = true;
		int areaCnt = 1; // 영역 내 이동할 수 있는 위치의 수
		set<pii> wallPos; // 카운팅할 벽

		while (!cp.empty())
		{
			int si = cp.front().lhs;
			int sj = cp.front().rhs;
			cp.pop();

			loop(j, home, 4)
			{
				int ci = si + cd[j].lhs;
				int cj = sj + cd[j].rhs;

				if (ci < home || cj < home || ci >= n || cj >= m) continue;
				if (vis[ci][cj]) continue;
				// 카운팅할 벽 저장
				if (graph[ci][cj] > home)
				{
					wallPos.insert({ ci, cj });
					continue;
				}

				cp.push({ ci, cj });
				vis[ci][cj] = true;
				areaCnt++;
			}
		}

		// 벽에 영역 내 이동할 수 있는 위치 수 만큼 누적
		mloop(it, wallPos) graph[it->lhs][it->rhs] += areaCnt;
	}

	// 10으로 나눈 나머지 출력
	for (auto a : graph)
	{
		for (auto b : a)
		{
			p(b % 10);
		}
		cout << '\n';
	}

	return home;
}