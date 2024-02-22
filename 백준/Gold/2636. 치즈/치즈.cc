#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// 치즈
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M 13, 12
	cin >> n >> m;

	vector<vector<int> > graph(n, vector<int>(m)); // 그래프
	vector<vector<bool> > vis(n, vector<bool>(m)); // 방문체크
	queue<pair<int, int> > checkPos; // 체크 할 위치
	vector<pair<int, int> > checkDir; // 상하좌우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	//	0 0 0 0 0 0 0 0 0 0 0 0
	//	0 0 0 0 0 0 0 0 0 0 0 0
	//	0 0 0 0 0 0 0 1 1 0 0 0
	//	0 1 1 1 0 0 0 1 1 0 0 0
	//	0 1 1 1 1 1 1 0 0 0 0 0
	//	0 1 1 1 1 1 0 1 1 0 0 0
	//	0 1 1 1 1 0 0 1 1 0 0 0
	//	0 0 1 1 0 0 0 1 1 0 0 0
	//	0 0 1 1 1 1 1 1 1 0 0 0
	//	0 0 1 1 1 1 1 1 1 0 0 0
	//	0 0 1 1 1 1 1 1 1 0 0 0
	//	0 0 1 1 1 1 1 1 1 0 0 0
	//	0 0 0 0 0 0 0 0 0 0 0 0
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> graph[i][j];
		}
	}

	// 1. 치즈 내부공기 판별하기
	// 그래프 돌면서 공기를만나면 BFS 돌리다가
	// 경계를 만나면 경계를 만났다고 체크
	// 만약 경계를 만난적이없다면 치즈내부공기이므로 저장

	// 2. 치즈가 모두녹기까지 걸리는시간++

	// 3. 녹아서 없어질 치즈좌표 구하기
	// 그래프를 돌다가 치즈를만나면 치즈개수++
	// 상하좌우 체크해서 치즈내부공기가 아닌 공기를 만나면
	// 녹아서 없어질 치즈좌표로 저장

	// 4.
	// 만약 녹아서없어질 치즈좌표개수와 치즈개수가 같으면 시간과 모두녹기전치즈개수 출력
	// 다르면 녹아서 없어질 치즈좌표 0으로

	int time = 0; // 모두녹는데 걸리는시간

	while (true)
	{
		vector<pair<int, int> > innerAir; // 치즈 내부공기 저장
		vector<pair<int, int> > meltCheese; // 녹아서 없어질 치즈좌표 저장

		// 1. 치즈 내부공기 판별하기
		for (int i = 1; i < n - 1; i++) // 어차피 가장자리는 0이므로 1~n-1
		{
			for (int j = 1; j < m - 1; j++) // 1~m-1 돌면서
			{
				if (graph[i][j] == 0) // 공기를 만나면
				{
					bool isBorder = false; // 가장자리를 만났는지 체크

					// 해당 공기부터 BFS 돌리기
					checkPos.push({ i,j });
					vis[i][j] = true;

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

							// 가장자리체크
							if (checkI < 1 || checkJ < 1 || checkI >= n - 1 || checkJ >= m - 1)
							{
								// 가장자리 만남
								isBorder = true;
								break;
							}

							// 방문체크
							if (vis[checkI][checkJ])
							{
								continue;
							}

							// 치즈체크
							if (graph[checkI][checkJ] == 1)
							{
								continue;
							}

							// 공기체크
							checkPos.push({ checkI, checkJ });
							vis[checkI][checkJ] = true;
						}

						 // 경계를만났다면 break
						if (isBorder)
						{
							break;
						}
					}

					// 만약 경계를 만난적이 없다면 치즈내부 공기이므로 저장
					if (!isBorder)
					{
						innerAir.push_back({ i, j });
					}

					// 큐 초기화
					while (!checkPos.empty())
					{
						checkPos.pop();
					}

					// vis 초기화
					for (int k = 0; k < n; k++)
					{
						for (int l = 0; l < m; l++)
						{
							vis[k][l] = false;
						}
					}
				}
			}
		}

		// 디버깅용
		//for (int i = 0; i < innerAir.size(); i++)
		//{
		//	cout << innerAir[i].first << ' ' << innerAir[i].second << ' ';
		//}
		//cout << '\n';

		// 2. 치즈가 모두녹기까지 걸리는시간++
		time++;

		// 3. 녹아서 없어질 치즈좌표 구하기
		// 그래프를 돌다가 치즈를만나면 치즈개수++
		// 상하좌우 체크해서 치즈내부공기가 아닌 공기를 만나면
		// 녹아서 없어질 치즈좌표로 저장
		int cheeseCnt = 0; // 치즈개수

		for (int i = 0; i < n; i++) // 그래프 돌다가
		{
			for (int j = 0; j < m; j++)
			{
				if (graph[i][j] == 1) // 치즈를 만나면
				{
					cheeseCnt++; // 치즈개수++

					// 상하좌우 체크
					for (int k = 0; k < 4; k++)
					{
						// 치즈 내부공기인지 체크
						bool isInner = false;

						// 체크 할 위치
						int checkI = i + checkDir[k].first;
						int checkJ = j + checkDir[k].second;

						// 공기를 만나면
						if (graph[checkI][checkJ] == 0)
						{
							// 치즈 내부공기 체크
							for (int l = 0; l < innerAir.size(); l++)
							{
								if (checkI == innerAir[l].first && checkJ == innerAir[l].second)
								{
									isInner = true;
									break;
								}
							}

							// 여기서 break해서 틀림 continue 해야함
							if (isInner)
							{
								continue;
							}

							// 치즈 내부공기가 아니면 없어질 치즈좌표에 저장
							meltCheese.push_back({ i, j });

							break;
						}
					}
				}
			}
		}

		// 디버깅용
		//for (int i = 0; i < meltCheese.size(); i++)
		//{
		//	cout << meltCheese[i].first << ' ' << meltCheese[i].second << ' ';
		//}
		//cout << '\n';

		// 4.
		// 만약 녹아서없어질 치즈좌표개수와 치즈개수가 같으면 시간과 모두녹기전치즈개수 출력 후 종료
		// 다르면 녹아서 없어질 치즈좌표 0으로

		// 만약 녹아서없어질 치즈좌표개수와 치즈개수가 같으면 시간과 모두녹기전치즈개수 출력 후 종료
		if (meltCheese.size() == cheeseCnt)
		{
			cout << time << '\n' << cheeseCnt << '\n';

			return 0;
		}
		
		// 다르면 녹아서 없어질 치즈좌표 0으로
		for (int i = 0; i < meltCheese.size(); i++)
		{
			graph[meltCheese[i].first][meltCheese[i].second] = 0;
		}
	}

	return 0;
}