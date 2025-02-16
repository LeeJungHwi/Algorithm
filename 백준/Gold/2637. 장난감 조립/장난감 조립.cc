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

// 장난감 조립
int main()
{
	init;

	// 기본 부품만 출력
	int n, m; cin >> n >> m;
	gmat(pii, graph, n);
	vec(int, directPre, n);
	mat(int, need, n, n); // need[i][j] => 중간 부품 i를 만드는데 필요한 기본 부품 j의 개수
	map<int, int> notBase; // 중간 부품 카운팅
	int v1, v2, c;
	loop(i, home, m)
	{
		cin >> v1 >> v2 >> c;
		graph[--v2].push_back({ --v1, c });
		directPre[v1]++;
		notBase[v1]++;
	}

	// 완제품 제외
	queue<int> noPre;
	loop(i, home, n - 1) if (directPre[i] == home)
	{
		noPre.push(i);
		need[i][i] = 1;
	}

	while (!noPre.empty())
	{
		int s = noPre.front();
		noPre.pop();

		loop(i, home, graph[s].size())
		{
			int c = graph[s][i].lhs;
			int sCnt = graph[s][i].rhs;

			// 다음 부품 c를 만들기 위해 현재 부품 s가 sCnt개 필요함
			// need[s][j] => s 하나를 만드는데 필요한 기본 부품 j 개수
			// 완제품(n - 1) 제외 0 ~ n - 2까지 돌면서 각 기본 부품의 필요 개수 누적
			loop(j, home, n - 1) need[c][j] += need[s][j] * sCnt;

			if (--directPre[c] == home) noPre.push(c);
		}
	}

	// 중간 부품과 완제품을 제외한 기본 부품만 출력
	loop(i, home, n) if (notBase[i] == home) { scp(i + 1); elp(need[n - 1][i]); }

	return home;
}