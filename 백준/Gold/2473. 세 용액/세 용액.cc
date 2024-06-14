#include <bits/stdc++.h>
using namespace std;

#define home 0
#define ll long long
#define loop(v, s, e) for(ll v = s; v < e; v++)
#define scprint(a) cout << a << ' '
#define cond(c, t, f) ((c) ? (t) : (f))

// 세 용액
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	ll n;
	cin >> n;
	vector<ll> nums(n);
	loop(i, 0, n) cin >> nums[i];
	sort(nums.begin(), nums.end());

	ll minL = 0, minS = 0, minR = 0;
	ll minSum = LLONG_MAX;

	// 한 용액 고정 => 나머지 두 용액 이진탐색
	loop(i, 0, n - 2)
	{
		ll l = i + 1, r = n - 1;

		while (l < r)
		{
			ll standard = nums[i] + nums[l] + nums[r];

			// 절댓값 최소
			if (abs(standard) < abs(minSum))
			{
				minSum = standard;
				minL = i;
				minS = l;
				minR = r;
			}

			// 음수면 더 큰 수로
			// 양수면 더 작은 수로
			cond(standard < 0, l++, r--);
		}
	}

	vector<ll> ans = { nums[minL], nums[minS], nums[minR] };
	sort(ans.begin(), ans.end());
	loop(i, 0, ans.size()) scprint(ans[i]);

	return home;
}
