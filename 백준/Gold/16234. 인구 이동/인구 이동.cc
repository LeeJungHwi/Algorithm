#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// 인구이동
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, l, r; // N, L, R 4, 10, 50
	cin >> n >> l >> r;

	vector<vector<int>> graph(n, vector<int>(n)); // 그래프
	queue<pair<int, int>> unitePos; // 연합국 위치 저장
	vector<vector<int>> uniteNum(n, vector<int>(n)); // 연합국 번호 저장
	vector<vector<bool>> vis(n, vector<bool>(n)); // 방문체크
	queue<pair<int, int>> checkPos; // 체크 할 위치
	vector<pair<int, int> > checkDir; // 상하좌우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0 , -1 });
	checkDir.push_back({ 0, 1 });

	// Input
	// 10 100 20 90
	// 80 100 60 70
	// 70 20 30 40
	// 50 20 100 10
	// 첫 스텝 : 1은 20 90 80 100 60 70 70 20 30 40 50 20 10 = 660 / 13 = 50명 씩 
	// x x 1 1
	// 1 1 1 1
	// 1 1 1 1
	// 1 1 x 1
	// 10 100 50 50
	// 50 50 50 50
	// 50 50 50 50
	// 50 50 100 50
	// 두번째 스텝 : 1은 10 50 = 60 / 2 = 30명 씩 2는 100 50 50 = 200 / 3 = 66명 씩 3은 50 50 100 50 = 250 / 4 = 62명 씩
	// 1 2 2 x
	// 1 2 x x
	// x x 3 x
	// x 3 3 3
	// 30 66 66 50
	// 30 66 50 50
	// 50 50 62 50
	// 50 62 62 62
	// 세번째 스텝 : 1은 30 66 = 96 / 2 = 48명 씩 2는 66 50 30 66 50 50 50 62 50 50 62 62 = 648 / 12 = 54명 씩
	// 1 1 2 2
	// 2 2 2 x
	// 2 2 2 2
	// 2 2 x 2
	// 48 48 54 54
	// 54 54 54 50
	// 54 54 54 54
	// 54 54 62 54
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> graph[i][j];
		}
	}

	int result = 0; // 인구이동 일수

	while (true)
	{
		int index = 0; // 연합국 번호

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!vis[i][j])
				{
					unitePos.push({ i, j }); // 연합국 위치 저장
					index++; // 연합국 번호 갱신
					uniteNum[i][j] = index; // 연합국 번호 저장
					int peopleCnt = graph[i][j]; // 연합국 사람수
					int countryCnt = 1; // 연합국 나라수
					checkPos.push({ i, j }); // 큐에 저장
					vis[i][j] = true; // 방문체크

					while (!checkPos.empty()) // 큐가 빌때까지
					{
						// 기준위치 꺼냄
						pair<int, int> standardPos = checkPos.front();
						checkPos.pop();

						// 상하좌우
						for (int k = 0; k < 4; k++)
						{
							// 체크 할 위치
							int checkI = standardPos.first + checkDir[k].first;
							int checkJ = standardPos.second + checkDir[k].second;

							// 경계체크
							if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= n)
							{
								continue;
							}
							
							// 방문체크
							if (vis[checkI][checkJ])
							{
								continue;
							}

							// 인구수 차이 체크
							int peopleCntGap = abs(graph[checkI][checkJ] - graph[standardPos.first][standardPos.second]);

							if (peopleCntGap < l || peopleCntGap > r)
							{
								continue;
							}

							unitePos.push({ checkI, checkJ }); // 연합국 위치 저장
							uniteNum[checkI][checkJ] = index; // 연합국 번호 저장
							peopleCnt += graph[checkI][checkJ]; // 연합국 인구수 누적
							countryCnt++; // 연합국 나라수 누적
							checkPos.push({ checkI, checkJ }); // 큐에 저장
							vis[checkI][checkJ] = true; // 방문체크
						}
					}

					int avgPeopleCnt = peopleCnt / countryCnt; // 연합국의 평균 인구수

					// 연합국 위치에 평균 인구수로 재분배
					while (!unitePos.empty())
					{
						graph[unitePos.front().first][unitePos.front().second] = avgPeopleCnt;
						unitePos.pop();
					}
				}
			}
		}

		// 전체 나라의 수와 형성된 연합의 수가 같아지면
		// 더이상 새로운 연합이 형성되지 않으므로 종료
		if (index == n * n)
		{
			break;
		}

		// 인구이동 일수 증가
		result++;

		// 방문체크 초기화
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				vis[i][j] = false;
			}
		}

		// 연합국 번호 초기화
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				uniteNum[i][j] = 0;
			}
		}
	}

	cout << result << '\n';

	return 0;
}
