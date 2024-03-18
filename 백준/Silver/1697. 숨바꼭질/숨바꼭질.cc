#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// 숨바꼭질
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, k; // N, K 5, 17
	cin >> n >> k;

	// 수빈이는 걷기(+1 or -1) 또는 순간이동(*2) 할수있음
	// 수빈이가 동생을 찾는 최단시간 구하기

	queue<int> checkPos; // 체크 할 위치
	vector<int> dis(100001); // 거리저장

	// 수빈이 위치부터 BFS 돌리기
	// 큐가 빌때까지
	// -1+1*2 체크
	// 경계체크
	// 방문체크(거리로)
	// 큐에저장 거리저장

	checkPos.push(n);
	dis[n] = 1;

	while (!checkPos.empty()) // 큐가 빌때까지
	{
		// 기준위치 꺼냄
		int standardPos = checkPos.front();
		checkPos.pop();

		// +1-1*2
		vector<int> checkDir;
		checkDir.push_back(standardPos + 1);
		checkDir.push_back(standardPos - 1);
		checkDir.push_back(standardPos * 2);

		for (int i = 0; i < 3; i++)
		{
			// 경계체크
			if (checkDir[i] < 0 || checkDir[i] > 100000)
			{
				continue;
			}

			// 방문체크(거리로)
			if (dis[checkDir[i]] > 0)
			{
				continue;
			}

			// 큐에저장 거리저장
			checkPos.push(checkDir[i]);
			dis[checkDir[i]] = dis[standardPos] + 1;
		}
	}

	// 시간을 1로 시작했으므로 1 빼줌
	cout << dis[k] - 1 << '\n';

	return 0;
}
