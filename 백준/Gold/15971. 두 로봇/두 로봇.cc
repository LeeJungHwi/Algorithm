#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

int n, firstRobot, secondRobot; // 방의개수, 첫번째로봇방, 두번째로봇방 9, 1, 9
vector<vector<pair<int, int>>> graph(100001); //  연결리스트방식으로 방 연결
vector<bool> vis(100001); //  방문체크
vector<int> path; // 첫번째로봇이 두번째로봇까지 가는데 거치는 정점 저장 1, 2, 5, 9

// DFS
void DFS(int L)
{
	if (L == secondRobot) // 종료조건 : 두로봇 방에 도착하는경우
	{
		vis[L] = true;
		path.push_back(L);
		return;
	}
	else
	{
		// 정점 방문 후 저장
		vis[L] = true;
		path.push_back(L);

		for (int i = 0; i < graph[L].size(); i++) // 방문한 정점으로부터 갈수있는 정점 중
		{
			if (!vis[graph[L][i].first]) // 아직 방문하지 않았다면
			{
				DFS(graph[L][i].first); // 다음 방문정점 재귀호출
				if (vis[secondRobot]) return;// 두번째로봇에 도착했으면 종료
				path.pop_back(); // 목적지로 못가면 해당 정점을 경로에서 제외
			}
		}
	}
}

// 두 로봇
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n >> firstRobot >> secondRobot;

	//	1 2 8
	//	2 3 6
	//	2 4 5
	//	2 5 10
	//	9 5 6
	//	6 5 14
	//	6 7 7
	//	8 6 7
	int v1, v2, c; // 정점 및 비용

	for (int i = 0; i < n - 1; i++)
	{
		cin >> v1 >> v2 >> c;

		// 양방향 연결
		graph[v1].push_back({ v2, c });
		graph[v2].push_back({ v1, c });
	}

	// 방이 하나인 경우와 두 로봇이 같은방에 있는 경우 0 출력 -> 바로 통신 가능
	if (n == 1 || firstRobot == secondRobot)
	{
		cout << 0 << '\n';

		return 0;
	}

	// 두로봇이 같은 통로 위에 있는 경우 0 출력 -> 바로 통신 가능
	for (int i = 0; i < graph[firstRobot].size(); i++)
	{
		if (graph[firstRobot][i].first == secondRobot)
		{
			cout << 0 << '\n';

			return 0;
		}
	}

	// DFS
	// 첫번째로봇에서 두번째로봇까지 거치는 정점 구하기
	DFS(firstRobot);

	// 첫로봇에서 두로봇까지 가는 비용 구하면서 최대통로길이 갱신
	int maxCost = 0;
	int minCost = 0;

	for (int i = 0; i < path.size() - 1; i++)
	{
		for (int j = 0; j < graph[path[i]].size(); j++)
		{
			if (graph[path[i]][j].first == path[i + 1])
			{
				// 첫로봇에서 두로봇까지 이동하는 비용 누적
				minCost += graph[path[i]][j].second;

				// 첫로봇에서 두로봇까지 이동하는 가장 큰 통로의 길이
				maxCost = max(maxCost, graph[path[i]][j].second);
			}
		}
	}

	// 가장 큰 통로의 길이를 빼줌
	minCost -= maxCost;

	// 두 로봇이 통신하기위한 최소비용 출력
	cout << minCost << '\n';

	return 0;
}

//// 두 로봇
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	ifstream cin;
//	cin.open("input.txt");
//
//	cin >> n >> firstRobot >> secondRobot;
//
//	// 시작부터 바로 통신가능하면 0 출력
//	if (abs(firstRobot - secondRobot) == 1)
//	{
//		cout << 0 << '\n';
//
//		return 0;
//	}
//
//	//	1 2 8
//	//	2 3 6
//	//	2 4 5
//	//	2 5 10
//	//	9 5 6
//	//	6 5 14
//	//	6 7 7
//	//	8 6 7
//	int v1, v2, c; // 정점 및 비용
//
//	for (int i = 0; i < n - 1; i++)
//	{
//		cin >> v1 >> v2 >> c;
//
//		// 양방향 연결
//		graph[v1].push_back({ v2, c });
//		graph[v2].push_back({ v1, c });
//	}
//
//	// DFS
//	// 첫번째로봇에서 두번째로봇까지 거치는 정점 구하기
//	DFS(firstRobot);
//
//	// 첫번째로봇이 0칸 이동했을때 16
//	// 첫번째로봇이 1칸 이동했을때 14
//	// 첫번째로봇이 2칸 이동했을때 18
//	// 따라서 최소값은 14
//	int minCost = 2147000000;
//
//	for (int i = 0; i < path.size() - 1; i++)
//	{
//		// 첫번째로봇 코스트
//		int firstCost = 0;
//
//		for (int j = 0; j < i; j++)
//		{
//			for (int k = 0; k < graph[path[j]].size(); k++)
//			{
//				if (graph[path[j]][k].first == path[j + 1])
//				{
//					firstCost += graph[path[j]][k].second; // 0, 8, 18
//				}
//			}
//		}
//
//		// 두번째로봇 코스트
//		int secondCost = 0;
//
//		for (int j = path.size() - 1; j > i + 1; j--)
//		{
//			for (int k = 0; k < graph[path[j]].size(); k++)
//			{
//				if (graph[path[j]][k].first == path[j - 1])
//				{
//					secondCost += graph[path[j]][k].second; // 16, 6, 0
//				}
//			}
//		}
//
//		// 첫로봇코스트 + 두로봇코스트
//		int sumCost = firstCost + secondCost;
//
//		// 최소값 갱신
//		minCost = min(minCost, sumCost);
//	}
//
//	// 두 로봇이 통신하기위한 최소비용 출력
//	cout << minCost << '\n';
//
//	return 0;
//}