#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

// 숨바꼭질4
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, k; // N, K 5, 17
	cin >> n >> k;

	// 수빈이는 걷기(+1 or -1) 또는 순간이동(*2) 할수있음
	// 수빈이가 동생을 찾는 최단시간 및 경로 출력하기

	queue<int> checkPos; // 체크 할 위치
	vector<pair<int, int> > dis(100001); // 각 위치별 (시간, 이전 위치) 쌍 저장

	// 수빈이 위치부터 BFS 돌리기
	// 큐가 빌때까지
	// -1+1*2 체크
	// 경계체크, 방문체크, 아직 시간이 할당되지 않았다면 시간 증가, 이전 위치 저장, 큐에 저장
	// 동생을 찾으면 최단시간 및 경로 출력 후 종료

	checkPos.push(n);
	dis[n] = { 1, n };

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

			// 방문체크(시간으로)
			if (dis[checkDir[i]].first > 0)
			{
				continue;
			}

			// 시간 증가, 이전 위치 저장, 큐에 저장
			dis[checkDir[i]].first = dis[standardPos].first + 1;
			dis[checkDir[i]].second = standardPos;
			checkPos.push(checkDir[i]);

			// 동생을 찾으면 최단시간 및 경로 출력 후 종료
			if (dis[k].first > 0)
			{
				// 최단시간 출력
				cout << dis[k].first - 1 << '\n';

				vector<int> path; // 경로

				for (int j = k; j != n; j = dis[j].second)
				{
					path.push_back(j); // 이전 경로 추가
				}

				path.push_back(n); // 처음 경로 추가

				reverse(path.begin(), path.end()); // 경로 뒤집기

				for (int j = 0; j < path.size(); j++) // 경로 출력하기
				{
					cout << path[j] << ' ';
				}

				return 0;
			}
		}
	}

	return 0;
}

