#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// 숨바꼭질2
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, k; // N, K 5, 17
	cin >> n >> k;

	// 수빈이는 걷기(+1 or -1) 또는 순간이동(*2) 할수있음
	// 수빈이가 동생을 찾는 최단시간 및 최단시간을 갖는 방법의 수 출력하기

	queue<int> checkPos; // 체크 할 위치
	vector<pair<int, int> > dis(100001); // 각 위치별 (시간, 방법 수) 쌍 저장

	// 수빈이 위치부터 BFS 돌리기
	// 큐가 빌때까지
	// -1+1*2 체크
	// 경계체크
	// 

	checkPos.push(n);
	dis[n] = { 1, 1 };

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

			// 아직 시간이 할당되지 않았다면
			// 해당위치로 최단시간으로 도착한 경우이므로
			// 기준위치의 시간 + 1, 기준위치의 방법 수, 큐에 저장
			if (dis[checkDir[i]].first == 0)
			{
				dis[checkDir[i]].first = dis[standardPos].first + 1;
				dis[checkDir[i]].second = dis[standardPos].second;
				checkPos.push(checkDir[i]);
			}
			else // 시간이 이미 할당된 경우
			{
				if (dis[checkDir[i]].first == dis[standardPos].first + 1) // 최단경로를 통해 들어 온 경우만
				{
					dis[checkDir[i]].second += dis[standardPos].second; // 방법 수 누적
				}
			}
		}
	}

	// 시간을 1로 시작했으므로 1 빼줌
	cout << dis[k].first - 1 << '\n' << dis[k].second << '\n';

	return 0;
}
