#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

vector<pair<int, int> > chicken; // 치킨집
vector<pair<int, int> > house; // 집
vector<int> vis(13); // 선택한 치킨집
int n, m; // N, M 5, 3
int minDis = 2147000000; // 도시 배달거리 최솟값
int chickenDis; // 각 집들의 배달거리
int cityDis; // 도시 배달거리

// DFS
void DFS(int L, int start)
{
	if (L == m) // 종료조건 : m개의 치킨집을 선택한 경우
	{
		// 각 집에 대해 선택된 치킨집 중 최단거리를 모두 더한값이 도시 배달거리

		cityDis = 0; // 도시 배달거리

		// 집 개수만큼 돌면서
		for (int i = 0; i < house.size(); i++)
		{
			// 집 위치
			int x1 = house[i].first; // 집 x좌표
			int y1 = house[i].second; // 집 y좌표

			// 집 최단거리
			chickenDis = 2147000000;

			// 선택된 치킨집만큼 돌면서 
			for (int j = 0; j < m; j++) 
			{
				// 치킨집 위치
				int x2 = chicken[vis[j]].first;
				int y2 = chicken[vis[j]].second;

				// 집 최단거리 갱신
				chickenDis = min(chickenDis, abs(x1 - x2) + abs(y1 - y2)); // 집 피자배달거리 최솟값 갱신
			}

			// 도시 배달거리
			cityDis += chickenDis;
		}

		// 도시 배달거리 갱신
		if (cityDis < minDis) minDis = cityDis;
	}
	else
	{
		// 치킨집 개수 중 m개 선택 -> 0 1 2 3, 0 1 2 4, ....
		for (int i = start; i < chicken.size(); i++)
		{
			vis[L] = i;
			DFS(L + 1, i + 1);
		}
	}
}

// 치킨배달
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n >> m;

	int num; // 숫자

	// 집, 치킨집 위치 저장
	// DFS로 치킨집 m개 선택
	// 각 집에대한 치킨 배달거리중 최단거리를 모두 더하고 도시 배달거리 갱신
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			cin >> num;

			if (num == 1) house.push_back({ i, j });
			else if (num == 2) chicken.push_back({ i, j });
		}
	}

	// DFS
	DFS(0, 0);

	cout << minDis << '\n';

	return 0;
}