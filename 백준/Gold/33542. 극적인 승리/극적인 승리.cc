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
#define piii pair<pii, int>
#define pll pair<ll, ll>
#define plll pair<pll, ll>

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

#define dir vector<pii> cd = { {-1, home}, {1, home}, { home, -1 }, { home, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } }
#define kdir vector<pii> kcd = { {-1, -2}, {-2, -1}, { -2, 1 }, { -1, 2 }, { 1, -2 }, { 2, -1 }, { 1, 2 }, { 2, 1 } }
#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX = 2147000000;
const int MIN = -2147000000;

// 극적인 승리
int main()
{
	init;

	// (양손 점수 쌍, 과녁 번호) 저장 후 오름차순
	// (0 0, 0)
	// (1 5, 1)
	// (3 3, 2)
	// (8 4, 3)
	// 과녁 돌면서
	// curScore => m + 현재 오른손 점수
	// l => home, h => k
	// s와 현재 오른손 과녁 번호가 같은 인덱스면 X
	// curScore + score[s].lhs > n 이면 가능한 경우 이므로 재탐색

	ll n, m, k; cin >> n >> m >> k;
	vec(plll, round, k + 1);
	loop(i, 1, k + 1)
	{
		round[i].rhs = i;
		cin >> round[i].lhs.lhs >> round[i].lhs.rhs;
	}
	sort(all(round));

	ll minGap = LLONG_MAX, leftHand = -1, rightHand = -1;

	// 두 손 모두 사용하지 않았을 때
	// 더해봤자 차이가 더 커지므로 바로 출력
	if (m > n)
	{
		scp(-1); elp(-1);
		return home;
	}

	// (0 0, 0)
	// (1 5, 1)
	// (3 3, 2)
	// (8 4, 3)
	loop(i, home, k + 1)
	{
		// 기본 점수 + 현재 오른손 점수
		ll curScore = m + round[i].lhs.rhs;

		// 오른손만 사용했을 때
		// 더해봤자 차이가 더 커지므로 최솟값 업데이트
		if (curScore > n)
		{
			if (minGap > curScore - n)
			{
				minGap = curScore - n;
				leftHand = -1;
				rightHand = cond(i == home, -1, round[i].rhs);
			}
			continue;
		}

		// 왼손만 사용했을 때 + 양손을 사용했을 때
		// 같은 인덱스 제외
		// home ~ i - 1
		// i + 1 ~ k
		ll l = home, h = i - 1;
		while (l <= h)
		{
			ll s = (l + h) / 2;

			if (curScore + round[s].lhs.lhs > n)
			{
				if (minGap > curScore + round[s].lhs.lhs - n)
				{
					minGap = curScore + round[s].lhs.lhs - n;
					leftHand = cond(s == home, -1, round[s].rhs);
					rightHand = cond(i == home, -1, round[i].rhs);
				}
				h = s - 1;
			}
			else l = s + 1;
		}

		l = i + 1, h = k;
		while (l <= h)
		{
			ll s = (l + h) / 2;

			if (curScore + round[s].lhs.lhs > n)
			{
				if (minGap > curScore + round[s].lhs.lhs - n)
				{
					minGap = curScore + round[s].lhs.lhs - n;
					leftHand = cond(s == home, -1, round[s].rhs);
					rightHand = cond(i == home, -1, round[i].rhs);
				}
				h = s - 1;
			}
			else l = s + 1;
		}
	}

	// 이길 수 없는 경우 No
	if (minGap == LLONG_MAX) { elp("No"); return home; }

	// 이길 수 있으면 각 손이 맞춘 과녁 번호 출력
	scp(leftHand); elp(rightHand);

	return home;
}