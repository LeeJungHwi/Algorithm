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
#define dir vector<pii> checkDir = { {-1, 0}, {1, 0}, { 0, -1 }, { 0, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } }

#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()

const int MAX = 2147000000;
const int MIN = -2147000000;

// 1로 만들기 3
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	#endif

	// 1.X가 3으로 나누어떨어지면 3으로 나눈다
	// 2.X가 2로 나누어떨어지면 2로 나눈다
	// 3.1을 뺸다

	ll x;
	cin >> x;
	queue<ll> checkPos;
	unordered_map<ll, ll> dis;
	checkPos.push(x);
	dis[x] = 1;

	while (!checkPos.empty())
	{
		ll standard = checkPos.front();
		checkPos.pop();

		if (standard == 1) break;

		vector<ll> checkDir;
		if (!(standard % 3)) checkDir.push_back(standard / 3);
		if (!(standard % 2)) checkDir.push_back(standard / 2);
		checkDir.push_back(standard - 1);

		loop(i, home, checkDir.size())
		{
			if (checkDir[i] < 1) continue;
			if (dis.find(checkDir[i]) != dis.end() && dis[checkDir[i]] <= dis[standard] + 1) continue;

			checkPos.push(checkDir[i]);
			dis[checkDir[i]] = dis[standard] + 1;
		}
	}
	elp(dis[1] - 1);

	return home;
}