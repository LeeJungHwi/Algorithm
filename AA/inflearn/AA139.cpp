#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

int n, m, s, e; // N, M, S, E 5, 6, 1, 5
vector<pair<int, int> > graph[10001]; // 그래프

// 한번의 이동으로 옮길수있는 제품의 최대무게인지 체크하는 함수
bool IsMove(int maxWeight)
{
	vector<bool> vis(n + 1); // 방문체크
	queue<int> checkPos; // 체크 할 섬

	// 시작 공장이 있는 섬부터 BFS 돌리기
	vis[s] = true;
	checkPos.push(s);

	while (!checkPos.empty()) // 큐가 빌때까지
	{
		// 기준위치 꺼냄
		int standardPos = checkPos.front();
		checkPos.pop();

		for (int i = 0; i < graph[standardPos].size(); i++)
		{
			// 방문체크
			if (vis[graph[standardPos][i].first])
			{
				continue;
			}

			// 제품의 최대무게가 다리의 중량보다 크면 못 옮김
			if (graph[standardPos][i].second < maxWeight)
			{
				continue;
			}

			// 옮길수있는 무게이면 방문 체크 후 큐에 저장
			vis[graph[standardPos][i].first] = true;
			checkPos.push(graph[standardPos][i].first);
		}
	}

	return vis[e]; // 도착 공장이 있는 섬까지 옮길수있는지 리턴
}

// 제품 이동
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n >> m;

	int a, b, c; // A섬, B섬, A섬과 B섬을 잇는 다리를 이동할수있는 제품의 최대무게
	int high; // 한번의 이동으로 옮길수있는 제품의 최대무게는 c 중 최대값

	// 섬을 잇는 다리정보 초기화
	//	1 2 5
	//	1 3 3
	//	1 4 2
	//	2 4 2
	//	3 4 4
	//	4 5 3
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;

		// 그래프 양방향 연결
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));

		high = max(high, c);
	}

	cin >> s >> e;

	int first = 1; // 처음
	int last = high; // 마지막
	int result = 0; // 한번의 이동으로 옮길수있는 제품의 최대무게

	// 한번의 이동으로 옮길수있는 제품의 최대무게 찾아서 출력
	while (first <= last) // first와 last가 역전되면 종료
	{
		int avg = (first + last) / 2; // 한번의 이동으로 옮길수있는 제품의 최대무게

		if (IsMove(avg)) // 무게가 avg일때 s에서 e로 옮기는게 가능하다면
		{
			result = avg; // 한번의 이동으로 옮길수있는 제품의 최대무게 갱신
			first = avg + 1; // 처음 갱신 
		}
		else // 불가능한 제품의 최대무게
		{
			last = avg - 1; // 마지막 갱신
		}
	}

	cout << result;

	return 0;
}