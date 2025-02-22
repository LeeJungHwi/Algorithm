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

// Puyo Puyo
int main()
{
	init;

	// 1.같은 색 뿌요가 4개 이상 상하좌우로 연결 되어 있다면 한번에 없어짐 => 한번에 없애야함
	// 2.위에 남은 뿌요는 경계 또는 다른 뿌요를 만날때까지 아래로 내려옴 => 역순으로 돌면서 내리고 내릴 때 이전 값은 .으로 채움
	// 더 이상 4개 이상 연결되지 않을때까지 1, 2 반복

	mat(char, graph, 12, 6);
	mat(bool, vis, 12, 6);
	queue<pii> cp; dir;
	int startI = -1; // 시작 열 => startI열 부터 탐색
	loop(i, home, 12) loop(j, home, 6)
	{
		cin >> graph[i][j];
		if (graph[i][j] != '.' && startI == -1) startI = i;
	}

	// 뿌요가 없는 경우
	if (startI == -1) { elp(home); return home; }

	int ans = home; // 연쇄 횟수
	while (true)
	{
		// 1.같은 색 뿌요가 4개 이상 상하좌우로 연결 되어 있다면 한번에 없어짐 => 한번에 없애야함

		int removeCnt = home; // 없앤 횟수
		loop(i, startI, 12) loop(j, home, 6) if (!vis[i][j] && graph[i][j] != '.')
		{
			cp.push({ i, j });
			vis[i][j] = true;
			tvec(pii, removePuyo); // 한번에 없앨 푸요 위치 저장
			removePuyo.push_back({ i, j });

			// 현재 뿌요와 같은 색 뿌요가 4개 이상 상하좌우로 연결 되어 있는지 확인
			while (!cp.empty())
			{
				int si = cp.front().lhs;
				int sj = cp.front().rhs;
				cp.pop();

				loop(k, home, 4)
				{
					int ci = si + cd[k].lhs;
					int cj = sj + cd[k].rhs;

					if (ci < home || cj < home || ci >= 12 || cj >= 6) continue;
					if (vis[ci][cj]) continue;
					if (graph[ci][cj] != graph[si][sj]) continue; // 다른 색 뿌요거나 빈 공간인 경우 X

					cp.push({ ci, cj });
					vis[ci][cj] = true;
					removePuyo.push_back({ ci, cj });
				}
			}

			// 크기가 4보다 작으면 연쇄 X
			if (removePuyo.size() < 4) continue;

			// 같은 색 뿌요가 4개 이상 연결 되어 있으면 뿌요 한번에 없앰
			loop(k, home, removePuyo.size()) graph[removePuyo[k].lhs][removePuyo[k].rhs] = '.';
			removeCnt++;
		}

		// 더 이상 연쇄가 일어 나지 않으면 종료
		if (removeCnt == home) break;

		// 없앤 뿌요가 있으면 1연쇄 카운팅하고 방문체크 초기화
		ans++;
		loop(i, startI, 12) loop(j, home, 6) vis[i][j] = false;

		// 2.위에 남은 뿌요는 경계 또는 다른 뿌요를 만날때까지 아래로 내려옴 => 역순으로 돌면서 내리고 내릴 때 이전 값은 .으로 채움
		rloop(i, 10, startI - 1) loop(j, home, 6) if (graph[i][j] != '.')
		{
			int si = i;

			while (true)
			{
				// 경계 또는 다른 뿌요를 만나면 X
				if (++si >= 12 || graph[si][j] != '.') break;

				// 아래로 내리면서 이전 값은 .으로 채움
				graph[si][j] = graph[si - 1][j];
				graph[si - 1][j] = '.';
			}
		}
	}
	elp(ans);

	return home;
}