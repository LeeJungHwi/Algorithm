#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

vector<pair<int, int> > pizza; // 피자집
vector<pair<int, int> > house; // 집
vector<int> vis(20); // 선택된 피자집
int n, m; // N, M 4, 4
int minDis = 2147000000; // 도시 피자배달거리 최솟값
int pizzaDis; // 각 집들의 피자배달거리
int cityDis; // 도시 피자배달거리

void DFS(int level, int start)
{
	if (level == m) // 종료조건 : m개의 피자집을 선택했을때 각 집에 대해 선택된 피자집 중 최단거리를 모두 더한값이 도시 피자배달거리
	{
		cityDis = 0; // 도시 피자배달거리

		for (int i = 0; i < house.size(); i++) // 집 개수만큼 돌면서
		{
			int x1 = house[i].first; // 집 x좌표
			int y1 = house[i].second; // 집 y좌표
			pizzaDis = 2147000000; // 집 피자배달거리

			for (int j = 0; j < m; j++) // 선택된 피자집만큼 돌면서 
			{
				int x2 = pizza[vis[j]].first; // 피자집 x좌표
				int y2 = pizza[vis[j]].second; // 피자집 y좌표
				pizzaDis = min(pizzaDis, abs(x1 - x2) + abs(y1 - y2)); // 집 피자배달거리 최솟값 갱신
			}

			cityDis += pizzaDis; // 도시 피자배달거리
		}

		if (cityDis < minDis) // 도시 피자배달거리 갱신
		{
			minDis = cityDis;
		}
	}
	else
	{
		for (int i = start; i < pizza.size(); i++) // 피자집 개수 중 m개 조합 ->  0 1 2 3, 0 1 2 4, ....
		{
			vis[level] = i;
			DFS(level + 1, i + 1);
		}
	}
}

// 피자 배달 거리
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n >> m;

	int num; // 숫자

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			cin >> num;

			if (num == 1)
			{
				house.push_back({ i, j }); // (1, 2) (2, 1) (2,4) (3, 3) (4, 3)
			}
			else if (num == 2)
			{
				pizza.push_back({ i, j }); // (1, 3) (2, 3) (3, 2) (3, 4) (4, 1) (4, 4)
			}
		}
	}

	// house -> 집(1)을 만나면 집 좌표 저장 -> (1, 2) (2, 1) (2,4) (3, 3) (4, 3)
	// pizza -> 피자집(2)를 만나면 피자집 좌표 저장 -> (1, 3) (2, 3) (3, 2) (3, 4) (4, 1) (4, 4)
	// ch -> 피자집을 m개 뽑아 저장 -> 0 1 2 3, 0 1 2 4, ....
	// 각 집에 대해 선택된 피자집 중 최단거리를 모두 더한값이 도시 피자배달거리
	DFS(0, 0);
	cout << minDis;

	return 0;
}