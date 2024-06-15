#include <bits/stdc++.h>
using namespace std;

#define home 0
#define loop(v, s, e) for(int v = s; v < e; v++)
#define elprint(a) cout << a << '\n'
#define cond(c, t, f) ((c) ? (t) : (f))

// 펜 내림차순
bool comp(const int &n1, const int &n2) { return n1 > n2; }

// 제 2회 IUPC는 잘 개최될 수 있을까?
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m, k;
	cin >> n >> m >> k;
	int need = m * k; // 필요한~
	vector<int> cnt(n);
	loop(i, 0, n) cin >> cnt[i];
	sort(cnt.begin(), cnt.end(), comp);
	int ans = 0;
	loop(i, 0, n)
	{
		if (need < 1) break; // 다 빌렸으면
		need -= cnt[i];
		ans++;
	}

	elprint(cond(need < 1, to_string(ans), "STRESS"));

	return home;
}