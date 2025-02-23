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
#define gmat(t, v, r) vector<vector<t> > v((r))
#define mat(t, v, r, c) vector<vector<t> > v((r), vector<t>((c)))
#define smat(t, v, r, c, s) vector<vector<vector<t> > > v((r), vector<vector<t>>((c), vector<t>((s))))

#define dir vector<pii> cd = { {-1, home}, {1, home}, { home, -1 }, { home, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } }
#define kdir vector<pii> kcd = { {-1, -2}, {-2, -1}, { -2, 1 }, { -1, 2 }, { 1, -2 }, { 2, -1 }, { 1, 2 }, { 2, 1 } }
#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX = 2147000000;
const int MIN = -2147000000;

int n, m, k;
queue<pii> cp; dir;

bool Check(int s, vector<vector<int>> &g, vector<vector<bool>> &vis)
{
	// 방문체크 초기화
	loop(i, home, n) loop(j, home, m) vis[i][j] = false;

	// 채굴한 광물 개수
	int cnt = home;

	// 바닥하고만 닿아있는 광물을 제외한 가장자리 광물부터 멀티 소스 BFS
	loop(i, home, n)
	{
		// 첫 열
		if (g[i][home] <= s && !vis[i][home])
		{
			cp.push({ i, home });
			vis[i][home] = true;
			cnt++;
		}

		// 마지막 열
		if (g[i][m - 1] <= s && !vis[i][m - 1])
		{
			cp.push({ i, m - 1 });
			vis[i][m - 1] = true;
			cnt++;
		}
	}
	loop(i, home, m)
	{
		// 첫 행
		if (g[home][i] <= s && !vis[home][i])
		{
			cp.push({ home, i });
			vis[home][i] = true;
			cnt++;
		}

		// 마지막 행의 양끝을 제외한 곳은 바닥하고만 닿은 광물이므로 X
	}

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
			if (vis[ci][cj]) continue;
			if (g[ci][cj] > s) continue; // 채굴기 성능보다 강도가 높은 광물은 X

			cp.push({ ci, cj });
			vis[ci][cj] = true;
			cnt++;
		}
	}

	// k개 이상 채굴하면 가능한 경우
	return cnt >= k;
}

// 채굴
int main()
{
	init;

	// 바닥하고만 닿아있는 광물을 제외한 가장자리 광물부터 멀티 소스 BFS
	// 채굴기 성능 D는 강도가 D이하인 광물을 채굴할 수 있음
	// lo => 0
	// hi => maxD
	// s로 채굴했을 때 k개 이상 채굴할 수 있으면 가능한 경우이므로 더 최솟값이 있는지 재탐색
	cin >> n >> m >> k;
	mat(int, graph, n, m);
	mat(bool, vis, n, m);
	int l = home, h = -2147000000;
	loop(i, home, n) loop(j, home, m)
	{
		cin >> graph[i][j];
		h = max(h, graph[i][j]);
	}

	int ans = h; // k개 이상 광물을 캘 수 있는 성능 최솟값
	while (l <= h)
	{
		int s = (l + h) / 2;

		// s로 채굴했을 때 k개 이상 채굴할 수 있으면 가능한 경우이므로 더 최솟값이 있는지 재탐색
		if (Check(s, graph, vis))
		{
			ans = s;
			h = s - 1;
		}
		else l = s + 1;
	}
	elp(ans);

	return home;
}