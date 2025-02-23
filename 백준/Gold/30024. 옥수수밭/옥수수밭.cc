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

// 옥수수밭
int main()
{
	init;

	// 현재 수확할 수 있는 옥수수 중 가장 가치가 높은 옥수수를 k번 수확함
	// 가장자리 옥수수 최대힙에 저장
	// k번 꺼내면서 꺼낸 옥수수의 상하좌우 옥수수를 최대힙에 저장

	int n, m; cin >> n >> m;
	mat(int, graph, n, m);
	mat(bool, vis, n, m);
	priority_queue<piii> pq; dir; // (가치, 위치)
	loop(i, home, n) loop(j, home, m) cin >> graph[i][j];
	int k; cin >> k;

	// 가장자리 옥수수 최대힙에 저장
	loop(i, home, n)
	{
		// 첫 열
		if (!vis[i][home])
		{
			pq.push({ graph[i][home],{i, home} });
			vis[i][home] = true;
		}

		// 마지막 열
		if (!vis[i][m - 1])
		{
			pq.push({ graph[i][m - 1], {i, m - 1} });
			vis[i][m - 1] = true;
		}
	}
	loop(i, home, m)
	{
		// 첫 행
		if (!vis[home][i])
		{
			pq.push({ graph[home][i],{home, i} });
			vis[home][i] = true;
		}
		
		// 마지막 행
		if (!vis[n - 1][i])
		{
			pq.push({ graph[n - 1][i], {n - 1, i} });
			vis[n - 1][i] = true;
		}
	}

	// k번 꺼내면서 꺼낸 옥수수의 상하좌우 옥수수를 최대힙에 저장
	while (k--)
	{
		int si = pq.top().rhs.lhs;
		int sj = pq.top().rhs.rhs;
		pq.pop();

		// 가장 가치가 높은 옥수수 수확
		scp(si + 1); elp(sj + 1);

		loop(i, home, 4)
		{
			int ci = si + cd[i].lhs;
			int cj = sj + cd[i].rhs;

			if (ci < home || cj < home || ci >= n || cj >= m) continue;
			if (vis[ci][cj]) continue;

			pq.push({ graph[ci][cj], {ci, cj} });
			vis[ci][cj] = true;
		}
	}

	return home;
}