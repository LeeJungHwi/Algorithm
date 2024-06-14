#include <bits/stdc++.h>
using namespace std;

#define home 0
#define ll long long
#define loop(v, s, e) for(int v = s; v < e; v++)
#define scprint(a) cout << a << ' '
#define cond(c, t, f) ((c) ? (t) : (f))

// 용액
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	// -99 -2 -1 4 98
	// -100 -2 -1 103
	int n;
	cin >> n;
	vector<ll> nums(n);
	loop(i, 0, n) cin >> nums[i];
	sort(nums.begin(), nums.end());

	int l = 0, r = n - 1, minL = 0, minR = 0;
	ll minSum = 2147000000;

	while (l < r)
	{
		ll standard = nums[l] + nums[r];

		// 절댓값 최소
		if (abs(standard) < abs(minSum))
		{
			minSum = standard;
			minL = l;
			minR = r;
		}

		// 음수면 더 큰 수로
		// 양수면 더 작은 수로
		cond(standard < 0, l++, r--);
	}

	scprint(nums[minL]);
	scprint(nums[minR]);

	return home;
}