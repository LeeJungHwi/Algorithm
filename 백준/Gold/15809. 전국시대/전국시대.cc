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

vector<int> unf(100001), people(100001);

int Find(int v)
{
	if (unf[v] == v) return v;
	return unf[v] = Find(unf[v]);
}

void Union(int v1, int v2)
{
	v1 = Find(v1);
	v2 = Find(v2);
	if (v1 != v2)
	{
		unf[v1] = v2;
		
		// 병력 합침
		people[v2] += people[v1];
		people[v1] = home;
	}
}

// 전국시대
int main()
{
	init;

	// o => 1 동맹 2 전쟁
	// 동맹 => 병력 합침
	// 전쟁 => 병력이 많은 집합이 승리, 승리한 나라는 패배한 나라의 병력만큼 잃고 패배한 나라는 병력을 모두 잃고 속국이됨
	// 동맹과 속국은 같은 집합으로 처리
	// m개의 기록이 끝나고 병력이 남아있는 국가의 수와 해당 국가들의 병력 수 출력
	// 동맹끼리 다시 동맹을 맺거나 전쟁하는 입력은 주어지지 않는다 => p와 q가 같은집합인 입력은 없음

	int n, m; cin >> n >> m;
	loop(i, home, n) { unf[i] = i; cin >> people[i]; }

	int o, p, q;
	loop(i, home, m)
	{
		cin >> o >> p >> q;

		// 전쟁
		if(o == 2)
		{
			int rootP = Find(p - 1), rootQ = Find(q - 1);
			int pPeople = people[rootP], qPeople = people[rootQ];

			// 병력 처리
			if(pPeople == qPeople) people[rootP] = people[rootQ] = home;
			else
			{
				people[rootP] = cond(pPeople > qPeople, people[rootP] - qPeople, home);
				people[rootQ] = cond(pPeople > qPeople, home, people[rootQ] - pPeople);
			}
		}

		// 동맹, 승리, 패배 모두 같은집합으로 처리
		Union(p - 1, q - 1);
	}

	// 루트면서 병력이 남아있는 경우 살아남은 나라
	tvec(int, nation);
	loop(i, home, n) if (Find(i) == i && people[Find(i)] > home) nation.push_back(people[Find(i)]);
	sort(all(nation));
	elp(nation.size());
	loop(i, home, nation.size()) scp(nation[i]);

	return home;
}