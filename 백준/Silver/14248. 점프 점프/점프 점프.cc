#include <bits/stdc++.h>
using namespace std;

#define home 0

#define ll long long

#define pii pair<int, int>
#define pll pair<ll, ll>

#define loop(v, s, e) for(int v = (s); v < (e); v++)
#define rloop(v, s, e) for(int v = (s); v > (e); v--)
#define mloop(v, a) for(auto v = (a).begin(); v != (a).end(); v++)
#define mrloop(v, a) for(auto v = (a).rbegin(); v != (a).rend(); v++)
#define aloop(t, v, s, c, e, i) for(t v = (s); v c (e); i)

#define p(a) cout << (a)
#define elp(a) cout << (a) << '\n'
#define scp(a) cout << (a) << ' '

#define vec(t, v, r) vector<t> v((r))
#define mat(t, v, r, c) vector<vector<t> > v((r), vector<t>((c)))
#define gmat(t, v, r) vector<vector<t> > v((r))
#define dir vector<pii> checkDir = { {-1, 0}, {1, 0}, { 0, -1 }, { 0, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } }

#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX = 2147000000;
const int MIN = -2147000000;

// 점프 점프
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	#endif

	int n;
	cin >> n;
	vec(int, graph, n);
	vec(bool, vis, n);
	loop(i, home, n) cin >> graph[i];
	stack<int> checkPos;
	int m;
	cin >> m;
	checkPos.push(m - 1);
	vis[m - 1] = true;
	int ans = 1;
	while (!checkPos.empty())
	{
		int standard = checkPos.top();
		checkPos.pop();

		vector<int> checkDir;
		checkDir.push_back(standard + graph[standard]);
		checkDir.push_back(standard - graph[standard]);

		loop(i, home, checkDir.size())
		{
			if (checkDir[i] < home || checkDir[i] >= n) continue;
			if (vis[checkDir[i]]) continue;

			checkPos.push(checkDir[i]);
			vis[checkDir[i]] = true;
			ans++;
		}
	}
	elp(ans);

	return home;
}