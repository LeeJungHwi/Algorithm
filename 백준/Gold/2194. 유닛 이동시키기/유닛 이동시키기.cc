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

// 유닛 이동시키기
int main()
{
	init;

	// 기준이 유닛 좌상 => 방문체크는 좌상에서 상하좌우 한칸만 확인
	// 다음 좌상의 첫행, 첫열, 마지막행, 마지막열만 한칸 씩 진행하면서 확인 => 사이는 이미 확인됨
	// 경계 또는 장애물을 만나면 갈 수 없음

	int n, m, h, w, k; cin >> n >> m >> h >> w >> k;
	mat(int, graph, n, m);
	mat(int, dis, n, m);
	queue<pii> cp; dir;
	pii block, sPos, ePos;

	// k개의 장애물 설치
	loop(i, home, k)
	{
		cin >> block.lhs >> block.rhs;
		graph[--block.lhs][--block.rhs] = 1;
	}

	cin >> sPos.lhs >> sPos.rhs >> ePos.lhs >> ePos.rhs;
	sPos.lhs--; sPos.rhs--; ePos.lhs--; ePos.rhs--;
	cp.push(sPos);
	dis[sPos.lhs][sPos.rhs] = 1;

	while (!cp.empty())
	{
		int si = cp.front().lhs;
		int sj = cp.front().rhs;
		cp.pop();

		loop(i, home, 4)
		{
			// 기준이 유닛 좌상 => 방문체크는 좌상에서 상하좌우 한칸만 확인
			int ci = si + cd[i].lhs;
			int cj = sj + cd[i].rhs;
			if (ci < home || cj < home || ci >= n || cj >= m) continue;
			if (dis[ci][cj] > home) continue;

			// 다음 좌상의 첫행, 첫열, 마지막행, 마지막열만 확인 => 사이는 이미 확인됨
			bool isMove = true;
			loop(j, home, cond(i < 2, w, h))
			{
				// 두 번째 항 => 0이면 첫 행, 1이면 마지막 행
				// 세 번째 항 => 좌우이므로 하로 한칸 씩 이동
				int cii = si + cd[i].lhs * cond(i == 1, h, 1) + cond(i >= 2, j, home);

				// 두 번째 항 => 2면 첫 열, 3이면 마지막 열
				// 세 번째 항 => 상하이므로 우로 한칸 씩 이동
				int cjj = sj + cd[i].rhs * cond(i == 3, w, 1) + cond(i < 2, j, home);

				// 경계 또는 벽을 만나면 X
				if (cii < home || cjj < home || cii >= n || cjj >= m || graph[cii][cjj] == 1)
				{
					isMove = false;
					break;
				}
			}
			if (!isMove) continue;

			cp.push({ ci, cj });
			dis[ci][cj] = dis[si][sj] + 1;
		}
	}
	elp(dis[ePos.lhs][ePos.rhs] - 1);

	return home;
}