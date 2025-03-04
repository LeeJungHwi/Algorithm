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
	loop(i, home, n + 1) loop(j, home, m + 2) vis[i][j] = false;

	// 채굴한 광물 개수
	int cnt = home;

	// 0,0부터 BFS 돌려서 s 강도로 채굴 가능한 광물 개수 카운팅
	cp.push({ home, home });
	vis[home][home] = true;

	while (!cp.empty())
	{
		int si = cp.front().lhs;
		int sj = cp.front().rhs;
		cp.pop();

		loop(i, home, 4)
		{
			int ci = si + cd[i].lhs;
			int cj = sj + cd[i].rhs;

			if (ci < home || cj < home || ci >= n + 1 || cj >= m + 2) continue;
			if (vis[ci][cj]) continue;
			if (g[ci][cj] > s) continue; // 채굴기 성능보다 강도가 높은 광물은 X

			cp.push({ ci, cj });
			vis[ci][cj] = true;
			// 광물인 경우만 채굴
			if(g[ci][cj] > home) cnt++;
		}
	}

	// k개 이상 채굴하면 가능한 경우
	return cnt >= k;
}

// 채굴
int main()
{
	init;

	// 바닥하고만 닿아있는 광물을 제외하기 위해 그래프 크기를 n + 1, m + 2로 하고
	// 0,0부터 BFS 돌려서 s 강도로 채굴 가능한 광물 개수 카운팅
	// lo => 0
	// hi => maxD
	// s로 채굴했을 때 k개 이상 채굴할 수 있으면 가능한 경우이므로 더 최솟값이 있는지 재탐색
	cin >> n >> m >> k;
	mat(int, graph, n + 1, m + 2);
	mat(bool, vis, n + 1, m + 2);
	int l = home, h = -2147000000;
	loop(i, 1, n + 1) loop(j, 1, m + 1)
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