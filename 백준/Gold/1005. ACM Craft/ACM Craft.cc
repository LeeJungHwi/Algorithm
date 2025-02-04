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

// ACM Craft
int main()
{
	init;

	int tc; cin >> tc;

	while (tc--)
	{
		int n, k; cin >> n >> k;
		gmat(int, graph, n);
		vec(int, directPre, n);
		vec(int, buildTime, n);
		loop(i, home, n) cin >> buildTime[i];
		int v1, v2;
		loop(i, home, k)
		{
			cin >> v1 >> v2;
			graph[--v1].push_back(--v2);
			directPre[v2]++;
		}

		// 선행 건물이 필요없는 건물 추가
		queue<int> noPre;
		loop(i, home, n) if (directPre[i] == home) noPre.push(i);

		// i번째 건물을 짓는데 필요한 최소 시간
		vec(int, ans, n);
		loop(i, home, n) ans[i] = buildTime[i];

		while (!noPre.empty())
		{
			int s = noPre.front();
			noPre.pop();

			loop(i, home, graph[s].size())
			{
				// s를 선행 건물로 가지는 건물
				int c = graph[s][i];

				// 가장 늦게 지어지는 선행건물을 짓는데 걸리는 시간 + c를 짓는데 걸리는 시간
				ans[c] = max(ans[c], ans[s] + buildTime[c]);

				// 필요한 선행 건물을 모두 지었으면 추가
				if (--directPre[c] == home) noPre.push(c);
			}
		}

		cin >> v1;
		elp(ans[--v1]);
	}

	return home;
}