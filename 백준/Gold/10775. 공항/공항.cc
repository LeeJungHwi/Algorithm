#include <bits/stdc++.h>
using namespace std;

#define home 0
#define loop(v, s, e) for(int v = s; v < e; v++)
#define elprint(a) cout << a << '\n'

// 집합 정보
vector<int> unf(100001);

// 정점이 속한 집합 번호 반환(루트)
int Find(int v)
{
	if (v == unf[v]) return v;
	return unf[v] = Find(unf[v]);
}

// 서로 다른 두 집합 결합
void Union(int v1, int v2) { unf[Find(v1)] = Find(v2); }

// 공항
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	int g, p;
	cin >> g >> p;

	loop(i, 1, g + 1) unf[i] = i;

	// 도킹 시킬 수 있는 최대 비행기 수
	int maxCnt = 0;

	// 현재 비행기가 도킹을 시도 할 최대 게이트 번호
	int gi;

	// p 개의 비행기에 대해
	loop(i, 0, p)
	{
		cin >> gi;

		// 도킹 가능한 가장 큰 게이트 번호 찾음
		int fgi = Find(gi);

		// 도킹 할 게이트 없음
		if (!fgi) break;

		// 도킹 할 게이트가 있다면
		// fgi 집합을 fgi - 1 집합에 합침
		// fgi 게이트를 사용 불가능하게 하고 다음 도킹 시 fgi - 1 게이트 사용
		Union(fgi, fgi - 1);
		maxCnt++;
	}

	elprint(maxCnt);

	return home;
}