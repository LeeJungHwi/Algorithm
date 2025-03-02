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

vector<vector<char>> graph(5, vector<char>(5));
vector<vector<bool>> vis(5, vector<bool>(5, true));
queue<pii> cp; dir;
vector<pii> sPos;
vector<int> order;
int ans;

void DFS(int L, int s, int bitmask)
{
	if (L == 7)
	{
		// 선택한 7명 위치 vis를 false로
		loop(i, home, order.size()) vis[sPos[order[i]].lhs][sPos[order[i]].rhs] = false;

		// 첫번째 공주 부터 BFS
		cp.push(sPos[order[home]]);
		vis[sPos[order[home]].lhs][sPos[order[home]].rhs] = true;
		int adjoinCnt = 1; // 인접한 수
		int idasomCnt = cond(graph[sPos[order[home]].lhs][sPos[order[home]].rhs] == 'S', 1, home); // 이다솜파 수

		while (!cp.empty())
		{
			int si = cp.front().lhs;
			int sj = cp.front().rhs;
			cp.pop();

			loop(i, home, 4)
			{
				int ci = si + cd[i].lhs;
				int cj = sj + cd[i].rhs;

				if (ci < home || cj < home || ci >= 5 || cj >= 5) continue;
				if (vis[ci][cj]) continue;

				cp.push({ ci, cj });
				vis[ci][cj] = true;
				adjoinCnt++;
				if (graph[ci][cj] == 'S') idasomCnt++;
			}
		}

		// 방문 초기화
		loop(i, home, 5) loop(j, home, 5) vis[i][j] = true;

		// 인접하지 않거나 이다솜파가 4명 이상이 아니면 X
		if (adjoinCnt != 7 || idasomCnt < 4) return;

		ans++;
	}
	else
	{
		// 비중복조합
		loop(i, s, sPos.size())
		{
			if ((bitmask & (1 << i)) > home) continue;

			order.push_back(i);
			DFS(L + 1, i, bitmask | (1 << i));
			order.pop_back();
		}
	}
}

// 소문난 칠공주
int main()
{
	init;

	// 비중복조합 7개 위치 뽑음
	// 7개 위치가 인접하고 이다솜파가 4명 이상이면 카운팅
	// vis를 true로 초기화하고 선택한 7개 위치만 false로
	// BFS 돌려서 인접하는지, 이다솜파가 4명 이상인지 확인
	loop(i, home, 5) loop(j, home, 5)
	{
		cin >> graph[i][j];
		sPos.push_back({ i, j });
	}

	DFS(home, home, home);
	elp(ans);

	return home;
}