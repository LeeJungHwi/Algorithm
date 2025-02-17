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

// 공주님의 정원
int main()
{
	init;

	// 3.1 ~ 11.30까지 매일 꽃이 한 가지 이상 피어있도록 할 때 선택한 꽃들의 최소 개수

	int n; cin >> n;
	vec(pii, flower, n);
	int m1, d1, m2, d2;
	loop(i, home, n)
	{
		cin >> m1 >> d1 >> m2 >> d2;
		flower[i] = { m1 * 100 + d1, m2 * 100 + d2 };
	}
	sort(all(flower));

	//loop(i, home, n)
	//{
	//	scp(flower[i].lhs);
	//	elp(flower[i].rhs);
	//}

	int curEnd = 301, maxEnd = 301, ans = home, idx = home;

	while (curEnd <= 1130)
	{
		bool isFlower = false;

		// curEnd 이전에 피면서 가장 늦게 지는 꽃 선택
		while (idx < n && flower[idx].lhs <= curEnd)
		{
			maxEnd = max(maxEnd, flower[idx++].rhs);
			isFlower = true;
		}

		// 선택한 꽃이 없으면 X
		if (!isFlower) { elp(home); return home; }

		curEnd = maxEnd;
		ans++;
	}
	elp(ans);

	return home;
}