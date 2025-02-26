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

	// 가장자리 외부공기를 모두 큐에넣고 멀티소스BFS로 -1로 마킹하기
	// 녹은 치즈(-1)를 제외한 모든 치즈 위치에 대해서 상하좌우 보면서 -1로 마킹된 외부 공기를 만나면 녹을 치즈로 판별
	// 남아있는 치즈 개수와 녹일 치즈의 개수가 같으면 종료
	// 아직 전부 녹지 않으면 치즈를 녹여 외부공기(-1)로 만들고 다음 외부공기 판별을 위해 큐에 추가

	int n, m; cin >> n >> m;
	mat(int, graph, n, m);
	queue<pii> cp; dir;
	tvec(pii, cheesePos); // 치즈 위치
	int cheeseCnt = home; // 남아있는 치즈 개수
	loop(i, home, n) loop(j, home, m)
	{
		cin >> graph[i][j];
		if (graph[i][j] == 1)
		{
			cheeseCnt++; // 남아있는 치즈 개수 카운팅
			cheesePos.push_back({ i, j }); // 치즈 위치 저장
		}
	}

	// 가장자리 외부공기를 모두 큐에넣기
	loop(i, home, n)
	{
		if (graph[i][home] == home && graph[i][home] != -1)
		{
			graph[i][home] = -1;
			cp.push({ i, home });
		}
		if (graph[i][m - 1] == home && graph[i][m - 1] != -1)
		{
			graph[i][m - 1] = -1;
			cp.push({ i, m - 1 });
		}
	}
	loop(i, home, m)
	{
		if (graph[home][i] == home && graph[home][i] != -1)
		{
			graph[home][i] = -1;
			cp.push({ home, i });
		}
		if (graph[n - 1][i] == home && graph[n - 1][i] != -1)
		{
			graph[n - 1][i] = -1;
			cp.push({ n - 1, i });
		}
	}

	int ans = home; // 치즈를 모두 녹이는데 걸리는 시간
	while (true)
	{
		ans++; // 1시간 후

		// 멀티소스BFS로 -1로 마킹하기
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
				if (graph[ci][cj] != home) continue;

				cp.push({ ci, cj });
				graph[ci][cj] = -1;
			}
		}

		// 녹은 치즈(-1)를 제외한 모든 치즈 위치에 대해서 상하좌우 보면서 -1로 마킹된 외부 공기를 만나면 녹을 치즈로 판별
		tvec(pii, meltPos); // 녹을 치즈
		loop(i, home, cheesePos.size()) if (graph[cheesePos[i].lhs][cheesePos[i].rhs] == 1)
		{
			int si = cheesePos[i].lhs;
			int sj = cheesePos[i].rhs;

			loop(j, home, 4)
			{
				int ci = si + cd[j].lhs;
				int cj = sj + cd[j].rhs;

				if (graph[ci][cj] == -1)
				{
					meltPos.push_back({ si, sj });
					break;
				}
			}
		}

		// 남아있는 치즈 개수와 녹일 치즈의 개수가 같으면 종료
		if (cheeseCnt == meltPos.size())
		{
			elp(ans);
			elp(cheeseCnt);
			return home;
		}

		// 아직 전부 녹지 않으면 치즈를 녹여 외부공기(-1)로 만들고 다음 외부공기 판별을 위해 큐에 추가
		loop(i, home, meltPos.size())
		{
			cheeseCnt--;
			graph[meltPos[i].lhs][meltPos[i].rhs] = -1;
			cp.push(meltPos[i]);
		}
	}

	return home;
}