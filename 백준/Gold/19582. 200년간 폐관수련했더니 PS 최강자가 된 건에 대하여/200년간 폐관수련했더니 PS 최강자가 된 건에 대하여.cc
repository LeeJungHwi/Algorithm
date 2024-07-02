#include <bits/stdc++.h>
using namespace std;

#define home 0

#define ll long long
#define ld long double

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
#define gmat(t, v, r) vector<vector<t> > v((r))
#define dir vector<pii> cd = { {-1, 0}, {1, 0}, { 0, -1 }, { 0, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } }

#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX = 2147000000;
const int MIN = -2147000000;

// 200년간 폐관수련했더니 PS 최강자가 된 건에 대하여
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	#endif

	int n; cin >> n;
	vec(pii, v, n);
	loop(i, home, n) cin >> v[i].lhs >> v[i].rhs;
	priority_queue<int> maxHeap;
	bool isPart1 = true;
	bool isPart2 = true;
	int tmp = home;
	int idx = -1;
	int cur = home;
	loop(i, home, n)
	{
		if (v[i].lhs < cur)
		{
			tmp = cur - maxHeap.top();
			idx = i;
			loop(j, i + 1, n)
			{
				if (v[j].lhs < cur)
				{
					isPart1 = false;
					break;
				}
				cur += v[j].rhs;
			}
			break;
		}
		cur += v[i].rhs;
		maxHeap.push(v[i].rhs);
	}

	if (!isPart1)
	{
		loop(i, idx, n)
		{
			if (v[i].lhs < tmp)
			{
				isPart2 = false;
				break;
			}
			tmp += v[i].rhs;
		}
	}

	cond(isPart1 || isPart2, elp("Kkeo-eok"), elp("Zzz"));

	return home;
}