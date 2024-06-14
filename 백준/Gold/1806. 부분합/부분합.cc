#include <bits/stdc++.h>
using namespace std;

#define home 0
#define ll long long
#define loop(v, s, e) for(ll v = s; v < e; v++)
#define elprint(a) cout << a << '\n'
#define cond(c, t, f) ((c) ? (t) : (f))

// 부분합
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m;
	cin >> n >> m;

	vector<int> num(n + 1);
	vector<int> dp(n + 1);

	// 누적합
	loop(i, 1, n + 1)
	{
		cin >> num[i];
		dp[i] = dp[i - 1] + num[i];
	}

	// 모든 j까지합 - i까지합에 대해 합이 m 이상이 되는 것 중 가장 짧은 부분수열의 길이
	ll minLen = LLONG_MAX;
	loop(i, 1, n + 1)
	{
		ll l = i, r = n;

		while (l <= r)
		{
			ll standard = (l + r) / 2;

			if (dp[standard] - dp[i - 1] >= m)
			{
				r = standard - 1;

				minLen = min(minLen, standard - i + 1);
				continue;
			}

			l = standard + 1;
		}
	}

	elprint(cond(minLen == LLONG_MAX, 0, minLen));

	return home;
}