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

// 치즈
int main()
{
	init;

	// 치즈 내부공기가 아닌 외부공기와 2개 이상 닿아있는 치즈는 녹음 => 한번에 없애야함
	// 공기를 만나면 BFS 돌려서 치즈를 만나면 녹일 치즈에 저장해서 한번에 녹임
	// 공기가 경계를 만나지 않으면 치즈 내부공기이므로 녹이지 않음
	// 남아있는 치즈 개수와 녹일 치즈의 개수가 같으면 종료

	int n, m; cin >> n >> m;
	mat(int, graph, n, m);
	mat(bool, vis, n, m);
	queue<pii> cp; dir;
	int cheeseCnt = home; // 남아있는 치즈 개수
	loop(i, home, n) loop(j, home, m)
	{
		cin >> graph[i][j];
		if (graph[i][j] == 1) cheeseCnt++;
	}

	int ans = home; // 치즈를 모두 녹이는데 걸리는 시간
	while (true)
	{
		ans++; // 1시간 후
		tvec(pii, realMeltCheese); // 진짜로 녹일 치즈

		// 공기를 만나면
		loop(i, home, n) loop(j, home, m) if (!vis[i][j] && graph[i][j] == home)
		{
			cp.push({ i, j });
			vis[i][j] = true;

			bool isBorder = false; // 공기가 경계를 만나는지 체크
			map<pii, int> meltCheese; // 녹일치즈 (위치, 외부공기 닿은 횟수)
			while (!cp.empty())
			{
				int si = cp.front().lhs;
				int sj = cp.front().rhs;
				cp.pop();

				loop(k, home, 4)
				{
					int ci = si + cd[k].lhs;
					int cj = sj + cd[k].rhs;

					// 경계를 만나는지 체크
					if (ci < home || cj < home || ci >= n || cj >= m) { isBorder = true; continue; }
					if (vis[ci][cj]) continue;
					// 치즈를 만나면 녹일 치즈 외부공기 닿은 횟수 카운팅
					if (graph[ci][cj] == 1)
					{
						meltCheese[{ci, cj}]++;
						continue;
					}

					cp.push({ ci, cj });
					vis[ci][cj] = true;
				}
			}

			// 경계를 만난 공기에 2번 이상 닿은 치즈만 녹음
			if (isBorder) mloop(it, meltCheese)
				if (it->rhs >= 2) realMeltCheese.push_back({it->lhs.lhs, it->lhs.rhs});
		}

		// 남아있는 치즈 개수와 녹일 치즈 개수가 같다면 종료
		if (cheeseCnt == realMeltCheese.size()) { elp(ans); return home; }

		// 아직 모두 녹이지 못하면
		// 남아있는 치즈 개수 감소
		// 치즈 녹이기
		// 방문체크 초기화
		cheeseCnt -= realMeltCheese.size();
		loop(i, home, realMeltCheese.size()) graph[realMeltCheese[i].lhs][realMeltCheese[i].rhs] = home;
		loop(i, home, n) loop(j, home, m) vis[i][j] = false;
	}

	return home;
}