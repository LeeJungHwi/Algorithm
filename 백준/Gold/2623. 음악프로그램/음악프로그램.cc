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

// 음악프로그램
int main()
{
	init;

	int n, m; cin >> n >> m;
	gmat(int, graph, n);
	vec(int, directPre, n);
	int k, v1, v2;
	loop(i, home, m)
	{
		cin >> k;

		if (k == home) continue;

		cin >> v1;

		loop(j, home, k - 1)
		{
			cin >> v2;

			graph[v1 - 1].push_back(v2 - 1);
			directPre[v2 - 1]++;

			v1 = v2;
		}
	}

	queue<int> noPre;
	loop(i, home, n) if (directPre[i] == home) noPre.push(i);

	vector<int> ans(n, 1);
	int cnt = home;
	while (!noPre.empty())
	{
		int s = noPre.front();
		noPre.pop();
		cnt++;

		loop(i, home, graph[s].size())
		{
			int c = graph[s][i];

			ans[c] = max(ans[c], ans[s] + 1);

			if (--directPre[c] == home) noPre.push(c);
		}
	}

	//loop(i, home, n) elp(ans[i]);

	// 순서를 정할 수 없으면 0
	if (cnt != n) { elp(home); return home; }

	map<int, vector<int>> order;
	loop(i, home, n) order[ans[i]].push_back(i);
	
	mloop(it, order)
	{
		loop(i, home, it->rhs.size())
		{
			elp(it->rhs[i] + 1);
		}
	}

	return home;
}