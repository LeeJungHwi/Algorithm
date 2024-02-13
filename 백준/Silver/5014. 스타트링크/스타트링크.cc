#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// 스타트링크
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int f, s, g, u, d; // F, S, G, U, D 10, 1, 10, 2, 1
	cin >> f >> s >> g >> u >> d;
	
	vector<bool> vis(1000001); // 방문체크
	queue<pair<int, int> > checkPos; // 체크 할 위치와 누른 버튼 수 저장

	// s 부터 BFS 돌리기
	// 큐가 빌때까지
	// 경계체크, 방문체크, g층에 도착하면 누른 버튼 수 출력, 아직 도착하지 않았으면 큐에 저장 후 방문체크

	checkPos.push({ s, 0 });
	vis[s] = true;

	while (!checkPos.empty()) // 큐가 빌때까지
	{
		// 체크 할 횟수
		int checkCnt = checkPos.size();

		while (checkCnt != 0) // 체크 할 횟수가 남아있을때까지
		{
			// 기준위치 꺼냄
			pair<int, int> standardPos = checkPos.front();
			checkPos.pop();

			// G층에 도착하면 누른 버튼 수 출력
			if (standardPos.first == g)
			{
				cout << standardPos.second << '\n';

				return 0;
			}

			// UD
			vector<pair<int, int> > checkDir;
			checkDir.push_back({ standardPos.first + u, standardPos.second + 1 });
			checkDir.push_back({ standardPos.first - d, standardPos.second + 1 });

			// UD 체크
			for (int i = 0; i < 2; i++)
			{
				// 체크 할 위치와 누른 버튼 수
				int checkNum = checkDir[i].first;
				int buttonCnt = checkDir[i].second;

				// 경계체크
				if (checkNum < 1 || checkNum > f)
				{
					continue;
				}

				// 방문체크
				if (vis[checkNum])
				{
					continue;
				}

				// 큐에 저장 후 방문체크
				checkPos.push({ checkNum, buttonCnt });
				vis[checkNum] = true;
			}

			// 하나의 체크 할 위치에 대해 수행한 상태
			checkCnt--;
		}
	}

	// while 루프에서 종료되지않았으면 갈 수 없는 층
	cout << "use the stairs\n";

	return 0;
}