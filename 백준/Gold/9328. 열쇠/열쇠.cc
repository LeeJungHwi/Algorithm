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

// 열쇠
int main()
{
	init;

	// 종료 조건 => 더 이상 획득한 열쇠가 없을 때 까지
	// 시작 위치 => n + 2, m + 2 크기 그래프의 0,0에서 시작
	// 열쇠 관리 => 비트마스크
	// 1.대문자를 만나면 열쇠가 있으면 빈공간으로
	// 2.소문자를 만나면 열쇠 추가하고 빈공간으로
	// 3.문서를 만나면 획득한 문서 개수 카운팅하고 빈공간으로

	int tc; cin >> tc;

	queue<pii> cp; dir;
	while (tc--)
	{
		int n, m; cin >> n >> m;
		mat(char, graph, n + 2, m + 2);
		mat(bool, vis, n + 2, m + 2);
		int bitmask = home;
		loop(i, 1, n + 1) loop(j, 1, m + 1) cin >> graph[i][j];

		// 처음에 가지고 있는 열쇠 추가
		string is;
		cin >> is;
		loop(i, home, is.size())
		{
			if (is[i] == '0') break;
			bitmask |= (1 << (is[i] - 'a'));
		}

		int ans = home; // 획득한 문서 개수
		while (true)
		{
			bool isKey = false; // 열쇠를 획득했는지 체크

			cp.push({ home, home });
			vis[home][home] = true;

			while (!cp.empty())
			{
				int si = cp.front().lhs;
				int sj = cp.front().rhs;
				cp.pop();

				loop(i, home, 4)
				{
					int ci = si + cd[i].lhs;
					int cj = sj + cd[i].rhs;

					if (ci < home || cj < home || ci >= n + 2 || cj >= m + 2) continue;
					if (vis[ci][cj]) continue;
					if (graph[ci][cj] == '*') continue;

					// 문
					if (isupper(graph[ci][cj]))
					{
						// 열쇠가 없으면 X
						if ((bitmask & (1 << (graph[ci][cj] - 'A'))) == home) continue;

						// 열쇠가 있으면 빈공간으로
						graph[ci][cj] = '.';
					}
					// 열쇠
					else if (islower(graph[ci][cj]))
					{
						// 열쇠 추가
						bitmask |= 1 << (graph[ci][cj] - 'a');

						// 빈공간으로
						graph[ci][cj] = '.';

						// 열쇠 획득
						isKey = true;
					}
					// 문서
					else if (graph[ci][cj] == '$')
					{
						// 문서 개수 카운팅
						ans++;

						// 빈공간으로
						graph[ci][cj] = '.';
					}

					cp.push({ ci, cj });
					vis[ci][cj] = true;
				}
			}

			// 열쇠를 획득하지 못 했으면 종료
			if (!isKey) break;

			// 방문체크 초기화
			loop(i, home, n + 2) loop(j, home, m + 2) vis[i][j] = false;
		}

		// 획득한 문서 개수 출력
		elp(ans);
	}

	return home;
}