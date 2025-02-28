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
#define ismat(t, v, r, c, s1, s2, i) vector<vector<vector<vector<t> > > > v((r), vector<vector<vector<t>>>((c), vector<vector<t>>((s1), vector<t>((s2), i))));

#define dir vector<pii> cd = { {-1, home}, {1, home}, { home, -1 }, { home, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } }
#define kdir vector<pii> kcd = { {-1, -2}, {-2, -1}, { -2, 1 }, { -1, 2 }, { 1, -2 }, { 2, -1 }, { 1, 2 }, { 2, 1 } }
#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX = 2147000000;
const int MIN = -2147000000;

// 배달
int main()
{
	init;

	// 배달 상태 조합 => 00, 01, 10, 11(3)
	// 같은곳을 여러번 방문할 수 있어서 경로가 여러개일 수 있음 => 거리를 MAX로 초기화하고 더 최솟값일 때 업데이트 해야함
	// BFS 내부에서 배달 위치와 빈공간인 경우로 뻗어나감
	int n, m; cin >> n >> m;
	mat(char, graph, n, m);
	ismat(int, dis, n, m, 4, 4, MAX); // dis[i][j][k][l] => i,j를 k방향에서 왔을 때 배달 상태가 l일 때 최단거리
	queue<pair<pii, pii>> cp; dir; // (방향, 배달 상태, 위치)
	pii sPos;
	tvec(pii, cPos);
	loop(i, home, n) loop(j, home, m)
	{
		cin >> graph[i][j];

		// 시작 위치 및 배달 위치 저장
		if (graph[i][j] == 'S') sPos = { i, j };
		else if (graph[i][j] == 'C') cPos.push_back({ i, j });
	}

	// 시작 위치에서 한칸 앞 부터 시작
	loop(i, home, 4)
	{
		int ci = sPos.lhs + cd[i].lhs;
		int cj = sPos.rhs + cd[i].rhs;

		if (ci < home || cj < home || ci >= n || cj >= m) continue;
		if (graph[ci][cj] == '#') continue;

		// 배달 위치
		loop(j, home, 2)
		{
			if (ci == cPos[j].lhs && cj == cPos[j].rhs)
			{
				// c1 => 01
				// c2 => 10
				cp.push({ {i, 1 << j}, {ci, cj} });
				dis[ci][cj][i][1 << j] = 1;

				continue;
			}
		}

		// 빈공간
		cp.push({ {i, home}, {ci, cj} });
		dis[ci][cj][i][home] = 1;
	}

	while (!cp.empty())
	{
		int si = cp.front().rhs.lhs;
		int sj = cp.front().rhs.rhs;
		int sd = cp.front().lhs.lhs;
		int sc = cp.front().lhs.rhs;
		cp.pop();

		// 모두 배달된 상태 => 11(3)
		if (sc == 3)
		{
			elp(dis[si][sj][sd][sc]);
			return home;
		}

		loop(i, home, 4)
		{
			// 같은 방향 X
			if (i == sd) continue;

			int ci = si + cd[i].lhs;
			int cj = sj + cd[i].rhs;

			if (ci < home || cj < home || ci >= n || cj >= m) continue;
			if (graph[ci][cj] == '#') continue;

			// 배달 위치
			int bitmask = home;
			if (graph[ci][cj] == 'C')
			{
				loop(j, home, 2)
				{
					if (ci == cPos[j].lhs && cj == cPos[j].rhs)
					{
						// c1 => 01
						// c2 => 10
						bitmask = 1 << j;

						// sc & bitmask => 현재 배달 조합에서 배달 위치 비트를 사용했는지 체크
						if ((sc & bitmask) == 1) continue;

						// sc | bitmask => 배달 위치를 방문한 비트로 바꿈
						if (dis[ci][cj][i][sc | bitmask] <= dis[si][sj][sd][sc] + 1) continue;

						cp.push({ {i, sc | bitmask}, {ci, cj} });
						dis[ci][cj][i][sc | bitmask] = dis[si][sj][sd][sc] + 1;
					}
				}

				continue;
			}

			// 빈공간
			if (dis[ci][cj][i][sc] <= dis[si][sj][sd][sc] + 1) continue;

			cp.push({ {i, sc}, {ci, cj} });
			dis[ci][cj][i][sc] = dis[si][sj][sd][sc] + 1;
		}
	}
	elp(-1);

	return home;
}