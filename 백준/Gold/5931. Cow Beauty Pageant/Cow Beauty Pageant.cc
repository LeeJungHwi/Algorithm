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

// Cow Beauty Pageant
int main()
{
	init;

	// 영역 라벨링 후 (라벨, 위치) 맵핑
	// 맵 돌면서 현재 라벨 보다 큰 라벨과 만나는 최단거리
	// 아스키코드는 라벨이 127을 넘으면 오버플로우가 발생하므로 int형 그래프로 치환
	int n, m; cin >> n >> m;
	mat(int, graph, n, m);
	mat(int, dis, n, m);
	queue<pii> cp; dir;
	tvec(pii, sPos);
	char ic;
	loop(i, home, n) loop(j, home, m)
	{
		cin >> ic;

		// 아스키코드는 라벨이 127을 넘으면 오버플로우가 발생하므로 int형 그래프로 치환 => .(-1) X(0)
		if (ic == '.') graph[i][j] = -1;
		if (ic == 'X')
		{
			graph[i][j] = home;
			sPos.push_back({ i, j });
		}
	}

	// 영역 라벨링 후 (라벨, 위치) 맵핑
	int curLabel = home;
	map<int, vector<pii>> labelMap;
	loop(i, home, sPos.size()) if (graph[sPos[i].lhs][sPos[i].rhs] == home)
	{
		graph[sPos[i].lhs][sPos[i].rhs] = ++curLabel;
		cp.push(sPos[i]);
		labelMap[curLabel].push_back(sPos[i]);

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
				if (graph[ci][cj] > home) continue; // 이미 라벨링된 영역은 X
				if (graph[ci][cj] == -1) continue;

				graph[ci][cj] = curLabel;
				cp.push({ ci, cj });
				labelMap[curLabel].push_back({ ci, cj });
			}
		}
	}

	// 맵 돌면서 현재 라벨 보다 큰 라벨과 만나는 최단거리
	mloop(it, labelMap)
	{
		// 현재 라벨의 모든 위치 부터 멀티 소스 BFS
		loop(i, home, it->rhs.size())
		{
			cp.push(it->rhs[i]);
			dis[it->rhs[i].lhs][it->rhs[i].rhs] = 1;
		}

		int ans = MAX; // 현재 라벨 보다 큰 라벨과 만나는 최단거리
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
				// 현재 라벨 보다 큰 라벨을 만나면 최단거리
				if (graph[ci][cj] > it->lhs) { ans = dis[si][sj] - 1; break; }
				if (graph[ci][cj] != -1) continue;

				cp.push({ ci, cj });
				dis[ci][cj] = dis[si][sj] + 1;
			}

			// 최단거리 구했으면 종료
			if (ans != MAX) break;
		}

		// 최단거리 구했으면 출력 후 거리 초기화
		if (ans != MAX) elp(ans);
		loop(i, home, n) loop(j, home, m) dis[i][j] = home;
	}

	return home;
}