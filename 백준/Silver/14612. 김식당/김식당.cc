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

bool comp(const pii & p1, const pii & p2)
{
	if(p1.second != p2.second) return p1.second < p2.second;
	return p1.first < p2.first;
}

// 김식당
int main()
{
	init;

	int n, m; cin >> n >> m;

	string command;
	int tableNum, orderTime;
	tvec(pii, post);
	loop(i, home, n)
	{
		cin >> command;

		switch (command[0])
		{
		case 'o':
			cin >> tableNum >> orderTime;
			post.push_back({ tableNum, orderTime });
			break;
		case 's':
			sort(post.begin(), post.end(), comp);
			break;
		case 'c':
			cin >> tableNum;
			loop(j, home, post.size())
			{
				if (post[j].first == tableNum)
				{
					post.erase(post.begin() + j);
				}
			}
			break;
		}

		if (post.empty()) cout << "sleep\n";
		else
		{
			loop(j, home, post.size())
			{
				cout << post[j].first << ' ';
			}
			cout << '\n';
		}
	}

	return home;
}