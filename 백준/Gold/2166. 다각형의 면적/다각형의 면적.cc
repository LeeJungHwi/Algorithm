#include <bits/stdc++.h>
using namespace std;

#define home 0
#define pll pair<long long, long long>
#define loop(v, s, e) for(int v = s; v < e; v++)
#define fixprint(a) cout << fixed << setprecision(1) << a << '\n'
#define cond(c, t, f) ((c) ? (t) : (f))

// 다각형의 면적
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	int n;
	cin >> n;

	long long x, y;
	map<long long, pll> pMap;
	loop(i, 0, n)
	{
		cin >> x >> y;
		pMap[i + 1] = { x, y };
	}
	long long lhs = 0, rhs = 0;
	loop(i, 0, n)
	{
		// 신발끈
		lhs += pMap[i + 1].first * cond(i == n - 1, pMap[1].second, pMap[i + 2].second);
		rhs += cond(i == n - 1, pMap[1].first, pMap[i + 2].first) * pMap[i + 1].second;
	}
	long double ans = abs(lhs - rhs) / 2.0L;
	fixprint(ans);

	return home;
}