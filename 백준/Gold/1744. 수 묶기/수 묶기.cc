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

// 수 묶기
int main()
{
	init;

	// 음수 => 작은 음수끼리 묶거나 음수와 0을 묶음
	// 양수 => 큰 수 끼리 묶음, 1은 안 묶는게 좋음 ex) 1 * 2 < 1 + 2

	int n; cin >> n;
	priority_queue<int, vector<int>, greater<int>> minusMinHeap;
	priority_queue<int> plusMaxHeap;

	int num, ans = home;
	loop(i, home, n)
	{
		cin >> num;

		if (num <= home) minusMinHeap.push(num);
		else if (num > 1) plusMaxHeap.push(num);
		else ans++;
	}

	// ans => 1
	// minusMinHeap => -1
	// plusMaxHeap => 2 3(top)

	while (plusMaxHeap.size() >= 2)
	{
		int num1 = plusMaxHeap.top(); plusMaxHeap.pop();
		int num2 = plusMaxHeap.top(); plusMaxHeap.pop();
		ans += num1 * num2;
	}
	while (!plusMaxHeap.empty())
	{
		ans += plusMaxHeap.top();
		plusMaxHeap.pop();
	}
	// ans => 7

	while (minusMinHeap.size() >= 2)
	{
		int num1 = minusMinHeap.top(); minusMinHeap.pop();
		int num2 = minusMinHeap.top(); minusMinHeap.pop();
		ans += num1 * num2;
	}
	while (!minusMinHeap.empty())
	{
		ans += minusMinHeap.top();
		minusMinHeap.pop();
	}
	// ans => 6

	elp(ans);

	return home;
}