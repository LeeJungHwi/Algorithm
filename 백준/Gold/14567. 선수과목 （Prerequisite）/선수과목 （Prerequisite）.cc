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

// 선수과목 (Prerequisite)
int main()
{
	init;

	int n, m; cin >> n >> m;
	gmat(int, graph, n);
	vec(int, directPre, n); // 각 과목의 직접적으로 연결된 선행과목 개수
	int v1, v2;
	loop(i, home, m)
	{
		cin >> v1 >> v2;
		graph[--v1].push_back(--v2);
		directPre[v2]++;
	}

	// 더 이상 들어야 할 선행과목이 없으면 추가
	queue<int> noPre;
	loop(i, home, n) if (directPre[i] == home) noPre.push(i);

	vector<int> ans(n, 1); // 각 과목을 듣기위한 최소 학기
	while (!noPre.empty())
	{
		int s = noPre.front();
		noPre.pop();

		loop(i, home, graph[s].size())
		{
			// s를 선행과목으로 가지는 과목
			int c = graph[s][i];

			// 가장 늦게 끝나는 선행과목을 듣는데 걸리는 학기 + 1로 업데이트
			ans[c] = max(ans[c], ans[s] + 1);

			// 모든 선행과목을 들었으면 추가
			if (--directPre[c] == home) noPre.push(c);
		}
	}
	loop(i, home, n) elp(ans[i]);

	return home;
}