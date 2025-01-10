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

// 스택 2
int main()
{
	init;

	stack<int> s;

	int n; cin >> n;
	int command;

	while (n--)
	{
		cin >> command;
		switch (command)
		{
			case 1:
				cin >> command;
				s.push(command);
				break;
			case 2:
				if (s.empty())
				{
					cout << -1 << '\n';
					break;
				}

				cout << s.top() << '\n';
				s.pop();
				break;
			case 3:
				cout << s.size() << '\n';
				break;
			case 4:
				cout << (s.empty() ? 1 : home) << '\n';
				break;
			case 5:
				if (s.empty())
				{
					cout << -1 << '\n';
					break;
				}

				cout << s.top() << '\n';
				break;
			}
	}

	return home;
}