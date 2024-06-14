#include <bits/stdc++.h>
using namespace std;

#define home 0
#define ll long long
#define pll pair<ll, ll>
#define loop(v, s, e) for(ll v = s; v < e; v++)
#define elprint(a) cout << a << '\n'
#define cond(c, t, f) ((c) ? (t) : (f))
#define X first
#define Y second

bool comp(const pll &p1, const pll &p2) { return cond(p1.X != p2.X, p1.X < p2.X, p1.Y > p2.Y); }

// 보석 도둑
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	ll n, k;
	cin >> n >> k;

	// 보석 => 무게, 가치
	vector<pll> jewel(n);
	loop(i, 0, n) cin >> jewel[i].X >> jewel[i].Y;

	// 가방 => 담을 수 있는 최대 무게
	vector<ll> bag(k);
	loop(i, 0, k) cin >> bag[i];
	sort(bag.begin(), bag.end());

	// 보석 무게 오름차순
	// 보석 가치 내림차순
	sort(jewel.begin(), jewel.end(), comp);

	// 현재 가방에 넣을 수 있는 보석 중 가치가 가장 높은 보석 뽑아냄
	priority_queue<ll> maxHeap;
	ll maxValue = 0;
	ll curIdx = 0;

	loop(i, 0, k)
	{
		// 현재 가방에 넣을 수 있는 최대 무게
		ll maxWeight = bag[i];

		// 현재 가방에 넣을 수 있는 모든 보석 push
		while (curIdx < n && jewel[curIdx].X <= maxWeight) maxHeap.push(jewel[curIdx++].Y);

		// 그 중 가장 높은 가치의 보석 뽑아서 누적
		if (!maxHeap.empty())
		{
			maxValue += maxHeap.top();
			maxHeap.pop();
		}
	}

	elprint(maxValue);

	return home;
}