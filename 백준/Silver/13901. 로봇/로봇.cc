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
#define pll pair<ll, ll>

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

#define dir vector<pii> cd = { {-1, home}, {1, home}, { home, -1 }, { home, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } }
#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX = 2147000000;
const int MIN = -2147000000;

// 로봇
int main()
{
	init;

	int n, m, k; cin >> n >> m >> k;
	mat(int, graph, n, m);
	pii pos;
	loop(i, home, k)
	{
		cin >> pos.lhs >> pos.rhs;
		graph[pos.lhs][pos.rhs] = -1;
	}
	cin >> pos.lhs >> pos.rhs;
	graph[pos.lhs][pos.rhs] = 1;
	map<int, pii> cd = { {1, {-1, 0}}, {2, {1, 0}}, {3, {0, -1}}, {4, {0, 1}} };
	vec(int, orderDir, 4);
	loop(i, home, 4) cin >> orderDir[i];
	
	int curDir = 0;
	int cantGoCnt = 0;
	while (true)
	{
		// 갈수없는 횟수가 4회면 위치 출력 후 종료
		if (cantGoCnt >= 4) { cout << pos.lhs << ' ' << pos.rhs << '\n'; return home; }

		// 현재 방향으로 갈수없으면 다음방향으로 바꾸고 continue, 갈수없는 횟수 카운팅
		int ci = pos.lhs + cd[orderDir[curDir]].lhs;
		int cj = pos.rhs + cd[orderDir[curDir]].rhs;

		if (ci < home || cj < home || ci >= n || cj >= m || graph[ci][cj] == -1 || graph[ci][cj] > home)
		{
			curDir = (curDir + 1) % 4;
			cantGoCnt++;
			continue;
		}
		//cout << "in";
	
		// 현재 방향으로 갈수있으면 방향을 바꾸지않고 이동, 갈수없는 횟수 초기화
		graph[ci][cj] = graph[pos.lhs][pos.rhs] + 1;
		pos = { ci, cj };
		cantGoCnt = home;
	}

	return home;
}