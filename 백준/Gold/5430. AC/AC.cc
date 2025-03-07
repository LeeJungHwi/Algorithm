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

// AC
int main()
{
	init;

	// R => 뒤집기
	// D => 첫 요소 버리기, 비어있는 경우 에러

	int tc; cin >> tc;
	
	while (tc--)
	{
		string p; cin >> p;
		int n; cin >> n;
		deque<int> d;
		string is; cin >> is;

		// , 또는 ]를 만나면 저장
		string temp = "";
		loop(i, 1, is.size())
		{
			if (is[i] == ',' || is[i] == ']')
			{
				if (temp.empty()) continue;
				d.push_back(stoi(temp));
				temp = "";
				continue;
			}

			temp += is[i];
		}

		// 명령어 수행
		bool isError = false; // 에러인지 체크
		bool isReverse = false; // 현재 뒤집은 상태인지 체크
		loop(i, home, p.size())
		{
			// R => 뒤집기 상태 변경
			if (p[i] == 'R') isReverse = !isReverse;
			// D => 뒤집지 않은 상태면 앞에서 빼고 뒤집은 상태면 뒤에서 뺌
			else
			{
				// 비어있는 경우 에러
				if (d.empty()) { isError = true; break; }

				// 뒤집지 않은 상태면 앞에서 빼고 뒤집은 상태면 뒤에서 뺌 
				cond(!isReverse, d.pop_front(), d.pop_back());
			}
		}

		// 에러 체크
		if (isError) { elp("error"); continue; }

		// 명령어 수행이 끝나고 뒤집지 않은 상태면 앞 부터 출력 뒤집은 상태면 뒤 부터 출력
		p('[');
		if (!d.empty())
		{
			if (!isReverse)
			{
				loop(i, home, d.size() - 1)
				{
					p(d[i]);
					p(',');
				}
				p(d.back());
			}
			else
			{
				rloop(i, d.size() - 1, home)
				{
					p(d[i]);
					p(',');
				}
				p(d.front());
			}
		}
		elp(']');
	}

	return home;
}