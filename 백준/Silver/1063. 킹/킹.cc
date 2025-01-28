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

#define dir vector<pii> cd = { {1, home}, {-1, home}, { home, -1 }, { home, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } }
#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX = 2147000000;
const int MIN = -2147000000;

// 킹
int main()
{
	init;

	//mat(int, graph, 8, 8);
	map<char, int> m = { {'A', home}, {'B', 1}, {'C', 2}, {'D', 3}, {'E', 4}, {'F', 5}, {'G', 6}, {'H', 7} };
	char km, sm;
	int kn, sn;
	cin >> km >> kn >> sm >> sn;
	pii kPos, sPos;
	kPos = { --kn, m[km] };
	sPos = { --sn, m[sm] };
	//cout << kPos.lhs << ' ' << kPos.rhs << '\n' << sPos.lhs << ' ' << sPos.rhs << '\n';
	int n; cin >> n;
	map<string, pii> d = { {"T", {1, home}}, {"B", {-1, home}}, {"L", {home, -1}}, {"R", {home, 1}},
							{"LT", {1, -1}}, {"RT", {1, 1}}, {"LB", {-1, -1}}, {"RB", {-1, 1}} };
	map<int, char> pos = { {home, 'A'}, {1, 'B'}, {2, 'C'}, {3, 'D'}, {4, 'E'}, {5, 'F'}, {6, 'G'}, {7, 'H'} };
	while (n--)
	{
		string c; cin >> c;
		int ci = kPos.lhs + d[c].lhs;
		int cj = kPos.rhs + d[c].rhs;

		if (ci < home || cj < home || ci >= 8 || cj >= 8) continue;
		if (ci == sPos.lhs && cj == sPos.rhs)
		{
			// 이동 방향에 돌이 있으면
			// 돌이 체스판 밖으로 나가면 이동X
			// 나가지않으면 킹과 돌 모두 이동
			int sci = sPos.lhs + d[c].lhs;
			int scj = sPos.rhs + d[c].rhs;

			if (sci < home || scj < home || sci >= 8 || scj >= 8) continue;
			kPos = { ci, cj };
			sPos = { sci, scj };
			continue;
		}

		// 이동 방향에 돌이 없으면
		// 킹만 이동
		kPos = { ci, cj };
	}
	cout << pos[kPos.rhs] << ++kPos.lhs << '\n' << pos[sPos.rhs] << ++sPos.lhs << '\n';

	return home;
}