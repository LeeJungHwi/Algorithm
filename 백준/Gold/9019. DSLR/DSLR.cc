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
#define piii pair<int, pii>
#define pll pair<ll, ll>
#define plll pair<ll, pll>

#define loop(v, s, e) for(int v = (s); v < (e); v++)
#define rloop(v, s, e) for(int v = (s); v > (e); v--)
#define mloop(v, a) for(auto v = (a).begin(); v != (a).end(); v++)
#define mrloop(v, a) for(auto v = (a).rbegin(); v != (a).rend(); v++)

#define p(a) cout << (a)
#define elp(a) cout << (a) << '\n'
#define scp(a) cout << (a) << ' '

#define tvec(t, v) vector<t> v
#define vec(t, v, r) vector<t> v((r))
#define ivec(t, v, r, i) vector<t> v((r), i)
#define gmat(t, v, r) vector<vector<t> > v((r))
#define mat(t, v, r, c) vector<vector<t> > v((r), vector<t>((c)))
#define imat(t, v, r, c, i) vector<vector<t> > v((r), vector<t>((c), i))
#define smat(t, v, r, c, s) vector<vector<vector<t> > > v((r), vector<vector<t>>((c), vector<t>((s))))
#define ismat(t, v, r, c, s, i) vector<vector<vector<t> > > v((r), vector<vector<t>>((c), vector<t>((s), i)))
#define ssmat(t, v, r, c, s1, s2) vector<vector<vector<vector<t> > > > v((r), vector<vector<vector<t>>>((c), vector<vector<t>>((s1), vector<t>((s2)))))
#define issmat(t, v, r, c, s1, s2, i) vector<vector<vector<vector<t> > > > v((r), vector<vector<vector<t>>>((c), vector<vector<t>>((s1), vector<t>((s2), i))))
#define sssmat(t, v, r, c, s1, s2, s3) vector<vector<vector<vector<vector<t> > > > > v((r), vector<vector<vector<vector<t>>>>((c), vector<vector<vector<t>>>((s1), vector<vector<t>>((s2), vector<t>((s3))))))
#define isssmat(t, v, r, c, s1, s2, s3, i) vector<vector<vector<vector<vector<t> > > > > v((r), vector<vector<vector<vector<t>>>>((c), vector<vector<vector<t>>>((s1), vector<vector<t>>((s2), vector<t>((s3), i)))))

#define dir vector<pii> cd = { {-1, home}, {1, home}, { home, -1 }, { home, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } }
#define kdir vector<pii> kcd = { {-1, -2}, {-2, -1}, { -2, 1 }, { -1, 2 }, { 1, -2 }, { 2, -1 }, { 1, 2 }, { 2, 1 } }
#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX = 2147000000;
const int MIN = -2147000000;

// DSLR
int main()
{
	init;

	// D => 2 * n, n이 9999보다 크면 % 10000
	// S => n - 1, n이 0이면 9999
	// L => <<
	// R => >>

	int tc; cin >> tc;
	vector<bool> vis(10000);
	queue<pair<int, string>> cp; // (위치, 명령어)
	vector<int> d(4);
	map<int, char> dirMap = { {home, 'D'}, {1, 'S'}, {2, 'L'}, {3, 'R'} };

	while (tc--)
	{
		int sPos, ePos; cin >> sPos >> ePos;

		cp.push({ sPos, "" });
		vis[sPos] = true;

		while (!cp.empty())
		{
			int s = cp.front().lhs;
			string p = cp.front().rhs;
			cp.pop();

			// 도착
			if (s == ePos) { elp(p); break; }

			// 다음 위치 설정
			d[home] = (2 * s) % 10000;
			d[1] = cond(s == home, 9999, s - 1);

			// 자릿수
			int s1 = s % 10;
			int s2 = (s % 100) / 10;
			int s3 = (s % 1000) / 100;
			int s4 = s / 1000;

			// 한자리
			if (s4 == home && s3 == home && s2 == home)
			{
				d[2] = s1 * 10;
				d[3] = s1 * 1000;
			}
			// 두자리
			else if (s4 == home && s3 == home)
			{
				d[2] = s1 * 10 + s2 * 100;
				d[3] = s1 * 1000 + s2;
			}
			// 세자리
			else if (s4 == home)
			{
				d[2] = s1 * 10 + s2 * 100 + s3 * 1000;
				d[3] = s1 * 1000 + s2 + s3 * 10;
			}
			// 네자리
			else
			{
				d[2] = s1 * 10 + s2 * 100 + s3 * 1000 + s4;
				d[3] = s1 * 1000 + s2 + s3 * 10 + s4 * 100;
			}

			loop(i, home, 4)
			{
				int c = d[i];

				if (c < home || c > 10000) continue;
				if (vis[c]) continue;

				cp.push({ c, p + dirMap[i] });
				vis[c] = true;
			}
		}

		// 초기화
		while (!cp.empty()) cp.pop();
		loop(i, home, 10000) vis[i] = false;
	}

	return home;
}