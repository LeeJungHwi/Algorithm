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

int n;
string is;
bool isPermutation;

void DFS(int &L, vector<bool> &ch, vector<char> &ans)
{
	if (is.size() == ans.size())
	{
		// n번째 순열이 아닌경우 가지치기
		if (++L > n) return;

		if (L == n)
		{
			isPermutation = true;
			scp(is);
			scp(n);
			scp('=');
			loop(i, home, ans.size()) p(ans[i]);
			elp(' ');
		}
	}
	else
	{
		// L번째 요소를 추가할지 안할지 재귀
		loop(i, home, is.size())
		{
			if (!ch[i])
			{
				ch[i] = true;
				ans.push_back(is[i]);
				DFS(L, ch, ans);
				ch[i] = false;
				ans.pop_back();
			}
		}
	}
}

// 순열
int main()
{
	init;

	while (cin >> is)
	{
		cin >> n;

		int L = home;
		isPermutation = false;
		vec(bool, ch, n);
		tvec(char, ans);

		DFS(L, ch, ans);
		if (!isPermutation)
		{
			scp(is);
			scp(n);
			elp("= No permutation");
		}
	}

	return home;
}