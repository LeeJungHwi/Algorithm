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

// 달이 차오른다, 가자.
int main()
{
	init;

	// 시작위치 -> 탈출위치 최단거리
	// 열쇠 조합 상태 => 000000 ~ 111111
	// BFS 내부에서 열쇠, 문, 빈공간으로 뻗어나감

	int n, m; cin >> n >> m;
	mat(char, graph, n, m);
	smat(int, dis, n, m, pow(2, 6)); // dis[i][j][k] => i,j에서 현재 열쇠 조합 상태가 k일 때 최단거리
	queue<piii> cp; dir; // (열쇠 조합 상태, 위치)
	loop(i, home, n) loop(j, home, m)
	{
		cin >> graph[i][j];

		// 시작 위치 큐에 저장
		if (graph[i][j] == '0')
		{
			cp.push({ home, {i, j} });
			dis[i][j][home] = 1;
		}
	}

	while (!cp.empty())
	{
		int si = cp.front().rhs.lhs;
		int sj = cp.front().rhs.rhs;
		int sc = cp.front().lhs;
		cp.pop();

		// 탈출
		if (graph[si][sj] == '1')
		{
			elp(dis[si][sj][sc] - 1);
			return home;
		}

		loop(i, home, 4)
		{
			int ci = si + cd[i].lhs;
			int cj = sj + cd[i].rhs;
			int cc = sc;

			if (ci < home || cj < home || ci >= n || cj >= m) continue;
			if (graph[ci][cj] == '#') continue;

			// 열쇠
			if (islower(graph[ci][cj]))
			{
				cc |= 1 << (graph[ci][cj] - 'a'); // a ~ f => 0 ~ 5

				// sc | bitmask => 현재 방문 조합 상태에 해당 열쇠 비트 추가
				if (dis[ci][cj][cc] > home) continue;

				cp.push({ cc, {ci, cj} });
				dis[ci][cj][cc] = dis[si][sj][sc] + 1;
			}
			// 문
			else if (isupper(graph[ci][cj]))
			{
				cc &= 1 << (graph[ci][cj] - 'A'); // A ~ F => 0 ~ 5

				// sc & bitmask => 현재 문의 열쇠가 있는지 체크
				if (cc == home) continue;
				if (dis[ci][cj][sc] > home) continue;

				cp.push({ sc, {ci, cj} });
				dis[ci][cj][sc] = dis[si][sj][sc] + 1;
			}
			// 빈공간
			else
			{
				if (dis[ci][cj][sc] > home) continue;

				cp.push({ sc, {ci, cj} });
				dis[ci][cj][sc] = dis[si][sj][sc] + 1;
			}
		}
	}
	elp(-1);

	return home;
}