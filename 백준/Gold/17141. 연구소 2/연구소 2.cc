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
#define ssmat(t, v, r, c, s1, s2) vector<vector<vector<vector<t> > > > v((r), vector<vector<vector<t>>>((c), vector<vector<t>>((s1), vector<t>((s2)))))
#define issmat(t, v, r, c, s1, s2, i) vector<vector<vector<vector<t> > > > v((r), vector<vector<vector<t>>>((c), vector<vector<t>>((s1), vector<t>((s2), i))))
#define sssmat(t, v, r, c, s1, s2, s3) vector<vector<vector<vector<vector<t> > > > > v((r), vector<vector<vector<vector<t>>>>((c), vector<vector<vector<t>>>((s1), vector<vector<t>>((s2), vector<t>((s3))))))
#define isssmat(t, v, r, c, s1, s2, s3, i) vector<vector<vector<vector<vector<t> > > > > v((r), vector<vector<vector<vector<t>>>>((c), vector<vector<vector<t>>>((s1), vector<vector<t>>((s2), vector<t>((s3), i)))))

#define dir vector<pii> cd = { {-1, home}, {1, home}, { home, -1 }, { home, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } }
#define kdir vector<pii> kcd = { {-1, -2}, {-2, -1}, { -2, 1 }, { -1, 2 }, { 1, -2 }, { 2, -1 }, { 1, 2 }, { 2, 1 } }
#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX = 2147000000;
const int MIN = -2147000000;

int n, m, ans = MAX;
vector<pii> zeroPos, virusPos;
queue<pii> cp; dir;
vector<int> order;

void DFS(int L, int s, int bitmask, vector<vector<int>>& graph, vector<vector<int>>& dis)
{
	if (L == m)
	{
		// 바이러스 놓기
		loop(i, home, order.size())
		{
			cp.push(virusPos[order[i]]);
			dis[virusPos[order[i]].lhs][virusPos[order[i]].rhs] = 1;
		}

		// 멀티 소스 BFS
		int minDis = 1;
		int zeroCnt = zeroPos.size() + virusPos.size() - m;

		while (!cp.empty())
		{
			int si = cp.front().lhs;
			int sj = cp.front().rhs;
			cp.pop();

			loop(i, home, 4)
			{
				int ci = si + cd[i].lhs;
				int cj = sj + cd[i].rhs;

				if (ci < home || cj < home || ci >= n || cj >= n) continue;
				if (dis[ci][cj] > home) continue;
				if (graph[ci][cj] == 1) continue;

				cp.push({ ci, cj });
				dis[ci][cj] = dis[si][sj] + 1;
				zeroCnt--;
				minDis = max(minDis, dis[ci][cj]);
			}
		}

		// 거리 초기화
		loop(i, home, n) loop(j, home, n) dis[i][j] = home;

		// 남아있는 빈 칸이 있으면 X
		if (zeroCnt > home) return;

		// 모든 빈 칸에 바이러스가 퍼지는 시간 최솟값 업데이트
		ans = min(ans, minDis);
	}
	else
	{
		// 비중복조합
		loop(i, s, virusPos.size())
		{
			if ((bitmask & (1 << i)) > home) continue;

			order.push_back(i);
			DFS(L + 1, i, bitmask | (1 << i), graph, dis);
			order.pop_back();
		}
	}
}

// 연구소
int main()
{
	init;

	// 바이러스 칸 중 m개 비중복조합 뽑아서 바이러스 놓기
	// 모든 바이러스 위치부터 멀티 소스 BFS
	// 모든 빈 칸에 바이러스를 퍼뜨리는 시간 최솟값

	cin >> n >> m;
	mat(int, graph, n, n);
	mat(int, dis, n, n);
	loop(i, home, n) loop(j, home, n)
	{
		cin >> graph[i][j];

		// 빈 칸 위치, 바이러스 위치 저장
		if (graph[i][j] == home) zeroPos.push_back({ i, j });
		else if (graph[i][j] == 2) virusPos.push_back({ i, j });
	}

	DFS(home, home, home, graph, dis);
	elp(cond(ans == MAX, -1, ans - 1));

	return home;
}