#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// 사냥꾼
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// n마리 동물 m개 사대
	// 총 사정거리 L
	// 사냥꾼은 하나의 사대에서 거리가 L보다 작거나 같은 위치의 동물을 잡을수있음
	// 사대위치 xi와 동물위치 aj, bj 사이 거리는 | xi - aj | + bj로 계산함 
	// 사대위치와 동물위치가 주어졌을때 잡을수있는 동물의 수 출력하기

	int m, n, l; // M, N, L 4, 8, 4
	cin >> m >> n >> l;

	vector<pair<int, int> > firePlace; // 사대 위치 저장
	vector<pair<int, int> > animalPos; // 동물 위치 저장
	vector<bool> vis(n); // 각 동물을 잡았는지 체크

	int x, y; // 좌표

	// 사대 x
	for (int i = 0; i < m; i++)
	{
		cin >> x;

		firePlace.push_back({ 0, x }); // (0, 6), (0, 1), (0, 4), (0, 9)
	}
	
	// 동물 x, y
	//	7 2
	//	3 3
	//	4 5
	//	5 1
	//	2 2
	//	1 4
	//	8 4
	//	9 4
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;

		animalPos.push_back({ y, x }); // (2, 7), (3, 3), (5, 4), (1, 5), (2, 2), (4, 1), (4, 8), (4, 9)
	}

	// 잡을수있는 동물 수 체크하기

	int huntCnt = 0; // 잡은 동물 수

	for (int i = 0; i < firePlace.size(); i++) // 각 사대가
	{
		for (int j = 0; j < animalPos.size(); j++) // 각 동물을 잡을수있는지 체크, 이미 잡은 동물은 카운팅 x
		{
			// 이미 잡힌 동물이 아니면
			if (!vis[j])
			{
				// 사대와 동물 거리 체크
				int dis = abs(firePlace[i].second - animalPos[j].second) + animalPos[j].first;

				// 거리가 사정거리 이하면 잡음
				if (dis <= l)
				{
					huntCnt++;
					vis[j] = true;
				}
			}
		}
	}

	// 잡을 수 있는 동물 수 출력하기
	cout << huntCnt << '\n';

	return 0;
}