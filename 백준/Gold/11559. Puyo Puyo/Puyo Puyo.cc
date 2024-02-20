#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

// Puyo Puyo
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 퍼즐게임
	// 같은색 뿌요가 4개이상 연결되어있으면 한꺼번에 없어짐 
	// 뿌요들이 없어지고 위에 다른색의 뿌요가있으면 아래로 내려옴
	// 연쇄가 몇번 일어나는지 출력하기

	vector<vector<char> > graph(12, vector<char>(6)); // 그래프
	vector<vector<char> > vis(12, vector<char>(6)); // 방문체크
	queue<pair<int, int> > checkPos; // 체크 할 위치
	vector<pair<int, int> > checkDir; // 상하좌우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	//	......
	//	......
	//	......
	//	......
	//	......
	//	......
	//	......
	//	......
	//	.Y....
	//	.YG...
	//	RRYG..
	//	RRYGG.
	string inputString;

	for (int i = 0; i < 12; i++)
	{
		cin >> inputString;

		for (int j = 0; j < 6; j++)
		{
			graph[i][j] = inputString[j];
		}
	}

	// 1.그래프를 정방향으로 탐색하면서 같은색깔 4개이상이 되는 영역을 찾으면 빈칸으로 없앰
	// 2.그래프를 역방향으로 탐색하면서 뿌요뿌요를 만나면 뿌요뿌요나 경계를 만날때까지 아래로 이동시킴
	// 1, 2를 반복하다가 연쇄가 일어나지않았다면 반복종료

	int comboCnt = 0; // 연쇄 횟수

	while (true)
	{
		bool isCombo = false; // 연쇄가 일어났는지 체크

		// 1.그래프를 정방향으로 탐색하면서 같은색깔 4개이상이 되는 영역을 찾으면 빈칸으로 없앰
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (graph[i][j] != '.' && !vis[i][j])
				{
					// 그래프를 돌면서 뿌요뿌요를 만나면서 방문하지 않았으면 BFS 돌리기

					vector<pair<int, int> > removePuyo; // 없앨 푸요푸요 저장
					int sameColorPuyoCnt = 1; // 같은색깔 뿌요뿌요 개수
					checkPos.push({ i, j });
					vis[i][j] = true;
					removePuyo.push_back({ i, j });

					while (!checkPos.empty()) // 큐가 빌때까지
					{
						// 뿌요뿌요 꺼냄
						pair<int, int> standardPos = checkPos.front();
						checkPos.pop();

						// 상하좌우
						for (int k = 0; k < 4; k++)
						{
							// 체크 할 위치
							int checkI = standardPos.first + checkDir[k].first;
							int checkJ = standardPos.second + checkDir[k].second;

							// 경계체크
							if (checkI < 0 || checkJ < 0 || checkI >= 12 || checkJ >= 6)
							{
								continue;
							}

							// 방문체크
							if (vis[checkI][checkJ])
							{
								continue;
							}

							// 빈칸체크
							if (graph[checkI][checkJ] == '.')
							{
								continue;
							}

							// 다른색깔 뿌요뿌요 체크
							if (graph[checkI][checkJ] != graph[standardPos.first][standardPos.second])
							{
								continue;
							}

							// 같은색깔 뿌요뿌요를 만났으면 큐에저장, 방문체크, 같은색뿌요카운팅, 없앨 푸요푸요에 저장
							checkPos.push({ checkI, checkJ });
							vis[checkI][checkJ] = true;
							sameColorPuyoCnt++;
							removePuyo.push_back({ checkI, checkJ });
						}
					}

					// 같은색 뿌요뿌요가 4개이상이면 빈칸으로 바꿔서 없애고 연쇄가 일어났음 체크
					if (sameColorPuyoCnt >= 4)
					{
						for (int k = 0; k < removePuyo.size(); k++)
						{
							graph[removePuyo[k].first][removePuyo[k].second] = '.';
						}

						isCombo = true;
					}
				}
			}
		}

		// 2.그래프를 역방향으로 탐색하면서 뿌요뿌요를 만나면 뿌요뿌요나 경계를 만날때까지 아래로 이동시킴
		for (int i = 10; i > -1; i--)
		{
			for (int j = 0; j < 6; j++)
			{
				if (graph[i][j] != '.') // 뿌요뿌요를 만나면
				{
					for (int k = i; k < 11; k++) // 경계 전까지
					{
						if (graph[k + 1][j] != '.') // 뿌요뿌요를 만날때까지
						{
							break;
						}

						// 아래로 이동시키고 기존 뿌요뿌요는 빈칸으로
						graph[k + 1][j] = graph[k][j];
						graph[k][j] = '.';
					}
				}
			}
		}

		// 연쇄가 일어나지않았으면 종료
		if (!isCombo)
		{
			break;
		}

		// 연쇄가 일어난 횟수 증가
		// 동시에 여러 그룹이 터져도 하나의 연쇄로 취급하므로
		// 여기서 증가시켜줘야함
		comboCnt++;

		// vis 초기화
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				vis[i][j] = false;
			}
		}
	}

	// 연쇄가 몇번 일어나는지 출력하기
	cout << comboCnt << '\n';

	return 0;
}