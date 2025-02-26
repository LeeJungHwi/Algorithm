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

// 확장 게임
int main()
{
	init;

	// 플레이어 i가 가지는 성부터 멀티 소스 BFS 돌려서 Si칸 만큼 확장
	// 남은 빈공간이 없거나 더 이상 확장이 일어나지 않으면 각 플레이어가 가지는 성의 개수 출력

	int n, m, k; cin >> n >> m >> k;
	vec(int, s, k); // 각 플레이어가 확장 가능한 칸수
	loop(i, home, k) cin >> s[i];
	mat(char, graph, n, m);
	mat(int, dis, n, m);
	queue<pii> cp; dir;
	map<int, vector<pii>> castlePos; // 각 플레이어가 가지는 성 위치
	map<int, int> castleCnt; // 각 플레이어의 성 개수
	int emptyCnt = home; // 남은 빈공간 개수
	loop(i, home, n) loop(j, home, m)
	{
		cin >> graph[i][j];

		// 각 플레이어가 가지는 성 위치 저장 및 개수 카운팅
		if (isdigit(graph[i][j]))
		{
			castlePos[graph[i][j] - '0'].push_back({ i, j });
			castleCnt[graph[i][j] - '0']++;
		}
		// 남은 빈공간 개수 카운팅
		else if(graph[i][j] == '.') emptyCnt++;
	}

	while (true)
	{
		// 플레이어 i가 가지는 성부터 멀티 소스 BFS 돌려서 Si칸 만큼 확장
		bool isExpand = false; // 플레이어가 한명이라도 확장했는지 체크
		mloop(it, castlePos)
		{
			// 현재 플레이어가 가지는 성 위치들 큐에 넣기
			loop(i, home, it->rhs.size())
			{
				cp.push(it->rhs[i]);
				dis[it->rhs[i].lhs][it->rhs[i].rhs] = 1;
			}

			// 멀티 소스 BFS 돌려서 Si칸 만큼 확장
			tvec(pii, expandCastlePos); // 현재 플레이어가 이번턴에 확장한 성 위치
			while (!cp.empty())
			{
				int si = cp.front().lhs;
				int sj = cp.front().rhs;
				cp.pop();

				// Si칸 만큼 확장
				if (dis[si][sj] > s[it->lhs - 1]) continue;

				loop(i, home, 4)
				{
					int ci = si + cd[i].lhs;
					int cj = sj + cd[i].rhs;

					if (ci < home || cj < home || ci >= n || cj >= m) continue;
					if (dis[ci][cj] > home) continue;
					if (graph[ci][cj] != '.') continue; // 빈공간이 아니면 X

					cp.push({ ci, cj });
					dis[ci][cj] = dis[si][sj] + 1;

					graph[ci][cj] = it->lhs + '0'; // 현재 플레이어 성으로 마킹
					expandCastlePos.push_back({ ci, cj }); // 확장한 성 위치 추가
					emptyCnt--; // 남은 빈공간 감소
					castleCnt[it->lhs]++; // 현재 플레이어 성 개수 카운팅
					isExpand = true; // 확장이 일어남
				}
			}

			// 확장한 성 위치부터 다음 BFS
			castlePos[it->lhs] = expandCastlePos;
		}

		// 남은 빈공간이 없거나 더 이상 확장이 일어나지 않으면 각 플레이어가 가지는 성의 개수 출력
		if (emptyCnt == home || !isExpand)
		{
			mloop(it, castleCnt) scp(it->rhs);
			return home;
		}
	}

	return home;
}