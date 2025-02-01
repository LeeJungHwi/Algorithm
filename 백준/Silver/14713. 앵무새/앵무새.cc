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

// 앵무새
int main()
{
	init;

	int n; cin >> n;
	vec(queue<string>, q, n);
	string is;
	cin.ignore();
	loop(i, home, n)
	{
		getline(cin, is);
		is += ' ';
		//cout << is << '\n';
		string temp = "";
		queue<string> tempQ;
		loop(j, home, is.size())
		{
			if (is[j] == ' ')
			{
				tempQ.push(temp);
				temp = "";
				continue;
			}
			temp += is[j];
		}
		q[i] = tempQ;
	}

	//loop(i, home, n)
	//{
	//	//while (!q[i].empty())
	//	//{
	//	//	elp(q[i].front());
	//	//	q[i].pop();
	//	//}
	//}

	getline(cin, is);
	is += ' ';
	string temp = "";
	loop(i, home, is.size())
	{
		if (is[i] == ' ')
		{
			// 모든 큐의 front가 아니면 Impossible
			bool isPossible = false;
			loop(j, home, n)
			{
				if (q[j].empty()) continue;

				// 큐의 front에서 현재단어를 찾으면 해당 큐에서 팝
				if (q[j].front() == temp)
				{
					q[j].pop();
					isPossible = true;
					break;
				}
			}

			if (isPossible)
			{
				temp = "";
				continue;
			}

			if (!isPossible)
			{
				elp("Impossible");
				return home;
			}
		}

		temp += is[i];
	}

	// 마지막에 큐에 단어가 남아있으면 불가능
	loop(i, home, n)
	{
		if (!q[i].empty())
		{
			elp("Impossible");
			return home;
		}
	}

	elp("Possible");

	return home;
}