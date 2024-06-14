#include <bits/stdc++.h>
using namespace std;

#define home 0
#define loop(v, s, e) for(int v = s; v < e; v++)
#define elprint(a) cout << a << '\n'

// 집합 정보
vector<int> unf(500001);

// 정점 랭크
vector<int> rnk(500001);

// 정점이 속한 집합 번호 반환(루트)
int Find(int v)
{
	if (v == unf[v]) return v;
	return unf[v] = Find(unf[v]);
}

// 서로 다른 두 집합 결합
void Union(int v1, int v2)
{
	v1 = Find(v1);
	v2 = Find(v2);

	// 랭크가 높은 집합에 랭크가 낮은 집합을 붙임
	if (rnk[v1] > rnk[v2])
	{
		unf[v2] = v1;
		return;
	}

	if (rnk[v1] < rnk[v2])
	{
		unf[v1] = v2;
		return;
	}

	// 랭크가 같다면 => v1에 v2 붙이고 v1 랭크 증가
	unf[v2] = v1;
	rnk[v1]++;
}

// 사이클 게임
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m;
	cin >> n >> m;

	loop(i, 0, n) unf[i] = i;

	int v1, v2;
	loop(i, 1, m + 1)
	{
		cin >> v1 >> v2;

		int fV1 = Find(v1);
		int fV2 = Find(v2);

		// 사이클 감지
		if (fV1 == fV2)
		{
			elprint(i);
			return home;
		}

		Union(v1, v2);
	}

	// 사이클 감지 X
	elprint(0);

	return home;
}