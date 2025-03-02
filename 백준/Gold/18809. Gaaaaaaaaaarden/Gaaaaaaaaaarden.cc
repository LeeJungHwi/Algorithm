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

int n, m, g, r;
queue<pii> cp; dir;
vector<pii> sPos;
vector<int> order, gorder;
int ans = home;

// g개 비중복조합
void GDFS(int L, int s, int bitmask, vector<vector<int>> &graph, vector<vector<int>> &dis, vector<vector<int>>&temp)
{
	if (L == g)
	{
		// g 1
		loop(i, home, gorder.size()) temp[sPos[order[gorder[i]]].lhs][sPos[order[gorder[i]]].rhs] = 1;

		// r 2
		loop(i, home, order.size())
		{
			if (temp[sPos[order[i]].lhs][sPos[order[i]].rhs] == home) temp[sPos[order[i]].lhs][sPos[order[i]].rhs] = 2;

			// 배양액 떨어진 곳 큐에 저장
			cp.push(sPos[order[i]]);
			dis[sPos[order[i]].lhs][sPos[order[i]].rhs] = 1;
		}

		// 멀티 소스 BFS
		int flowerCnt = home;
		while (!cp.empty())
		{
			int si = cp.front().lhs;
			int sj = cp.front().rhs;
			cp.pop();

			// 꽃이 핀 위치는 퍼질 수 없음
			if (temp[si][sj] == 3) continue;

			loop(i, home, 4)
			{
				int ci = si + cd[i].lhs;
				int cj = sj + cd[i].rhs;

				if (ci < home || cj < home || ci >= n || cj >= m) continue;
				if (graph[ci][cj] == home) continue;

				// 아직 배양액이 퍼지지 않은 곳
				if (dis[ci][cj] == home)
				{
					cp.push({ ci, cj });
					dis[ci][cj] = dis[si][sj] + 1;
					temp[ci][cj] = temp[si][sj];
				}
				// 배양액이 퍼진 곳 => 동시에 도착한 서로 다른 배양액이 꽃이 피지 않았으면 꽃이 핌
				else if(dis[ci][cj] == dis[si][sj] + 1)
				{
					if (temp[ci][cj] != temp[si][sj] && temp[ci][cj] != 3)
					{
						flowerCnt++;
						temp[ci][cj] = 3;
					}
				}
			}
		}

		// 꽃이 피는 최대 개수 업데이트
		ans = max(ans, flowerCnt);

		// 거리 및 temp 그래프 초기화
		loop(i, home, n) loop(j, home, m)
		{
			dis[i][j] = home;
			temp[i][j] = home;
		}
	}
	else
	{
		loop(i, s, order.size())
		{
			if ((bitmask & (1 << i)) > home) continue;

			gorder.push_back(i);
			GDFS(L + 1, i, bitmask | (1 << i), graph, dis, temp);
			gorder.pop_back();
		}
	}
}

// g + r개 비중복조합
void DFS(int L, int s, int bitmask, vector<vector<int>> &graph, vector<vector<int>> &dis, vector<vector<int>> &temp)
{
	if (L == g + r)
	{
		GDFS(home, home, home, graph, dis, temp);
	}
	else
	{
		loop(i, s, sPos.size())
		{
			if ((bitmask & (1 << i)) > home) continue;

			order.push_back(i);
			DFS(L + 1, i, bitmask | (1 << i), graph, dis, temp);
			order.pop_back();
		}
	}
}

// Gaaaaaaaaaarden
int main()
{
	init;

	// 배양액을 뿌릴 수 있는 땅에 초록색 배양액과 빨간색 배양액을 뿌리는 비중복조합
	// 빨간색 배양액과 초록색 배양액이 동시에 도달하는 위치에 꽃이피고 퍼트리지 않음
	
	// 1.배양액을 뿌릴 수 있는 땅에서 g + r개의 땅을 뽑음
	// 2.뽑은 땅 g + r개에서 g개의 땅을 뽑아서 temp 그래프에 1 나머지 뽑히지 않은 땅은 temp 그래프에 2로
	// 3.모든 배양액 부터 멀티 소스 BFS 돌려서 동시에 도달하면서 서로 다른 배양액이면 꽃이피고 분기 X
	cin >> n >> m >> g >> r;
	mat(int, graph, n, m);
	mat(int, dis, n, m);
	mat(int, temp, n, m);
	loop(i, home, n) loop(j, home, m)
	{
		cin >> graph[i][j];
		if (graph[i][j] == 2) sPos.push_back({ i, j });
	}

	DFS(home, home, home, graph, dis, temp);
	elp(ans);

	return home;
}