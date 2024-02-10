#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// 송아지 찾기 2
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int s, e, k; // S, E, K 5, 14, 3
	cin >> s >> e >> k;

	queue<int> checkPos; // 체크 할 위치
	vector<bool> vis(10001); // 웅덩이 위치 체크 7 11 15

	// 웅덩이 위치 체크
	int kPos;
	for (int i = 0; i < k; i++)
	{
		cin >> kPos;
		vis[kPos] = true;
	}

	// 현수 위치부터 BFS 돌리기
	checkPos.push(s);

	int jumpCnt = 0; // 점프 횟수

	while (!checkPos.empty()) // 큐가 빌때까지
	{
		int sizeBackUp = checkPos.size(); // 큐 사이즈 백업 ??

		for (int i = 0; i < sizeBackUp; i++) // 백업된 큐 사이즈만큼 돌면서 ??
		{
			// 기준위치 꺼냄
			int standardPos = checkPos.front();
			checkPos.pop();

			// -1 +1 +5
			vector<int> checkDir;
			checkDir.push_back(standardPos - 1);
			checkDir.push_back(standardPos + 1);
			checkDir.push_back(standardPos + 5);

			for (int i = 0; i < 3; i++)
			{
				// 기준위치에서 -1 +1 +5 중 하나로 바로갈수있으면 점프횟수 + 1 출력 후 프로그램 종료
				if (checkDir[i] == e) 
				{
					cout << jumpCnt + 1;
					exit(0);
				}
				
				// 경계체크
				if (checkDir[i] < 1 || checkDir[i] > 10000)
				{
					continue;
				}

				// 웅덩이 체크
				if (vis[checkDir[i]])
				{
					continue;
				}

				// 큐에 저장 후 방문체크
				checkPos.push(checkDir[i]);
				vis[checkDir[i]] = 1;
			}
		}

		// 점프횟수 증가
		jumpCnt++;
	}

	return 0;
}