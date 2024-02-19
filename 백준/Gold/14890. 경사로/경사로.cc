#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// 경사로
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// n by n에 각 칸의 높이가 적혀있음
	// 경사로를 놓아서 각각의 행 또는 열을 같은높이로 만들수있다면 지나갈수있는 길임
	// 경사로의 높이는 항상 1이며 길이는 입력으로 주어지는 L
	// 경사로는 아래 조건을 모두 만족해야 놓을수있음
	/*
	경사로는 낮은칸에 놓으며 L개의 연속된 칸에 경사로의 바닥이 모두 접해야함
	낮은칸과 높은칸의 높이차가 1이어야함
	경사로를 놓을 낮은칸의 높이는 모두같아야하고 L개의 칸이 연속되어 있어야함
	*/
	// 경사로를 놓을수없는 경우
	/*
	경사로를 놓은곳에 또 경사로를 놓는 경우
	낮은칸과 높은칸의 높이차가 1이 아닌경우
	낮은지점 칸들의 높이가 모두 같지않거나 L개가 연속되지않은경우
	경사로를 놓다가 범위를 벗어나는경우
	*/
	// 지나갈수있는 길의 총 개수 구하기 

	int n, l; // N, L 6, 2
	cin >> n >> l;

	vector<vector<int> > graph(n, vector<int>(n)); // 그래프
	vector<vector<int> > vis(n, vector<int>(n)); // 경사로를 놓았는지 체크

	//	3 3 3 3 3 3
	//	2 3 3 3 3 3
	//	2 2 2 3 2 3
	//	1 1 1 2 2 2
	//	1 1 1 3 3 1
	//	1 1 2 3 3 2
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> graph[i][j];
		}
	}

	// 0 행 : 3 3 3 3 3 3 -> 지나갈수있는길
	// 1 행 : 2 이므로 경사로 놓을수없음 -> 지나갈수없는길
	// 2 행 : 2 2 2 이므로 경사로 놓을수있음 -> 2 이므로 경사로 놓을수없음 -> 지나갈수없는길
	// 3 행 : 1 1 1 이므로 경사로 놓을수있음 -> 지나갈수있는길
	// 4 행 : 1 1 1 이지만 높이차가 2이므로 놓을수없음 -> 지나갈수없는길
	// 5 행 : 1 1 이므로 경사로 놓을수있음 -> 2 이므로 경사로 놓을수없음 -> 지나갈수없는길
	// 0 열 : 3 -> 2 2 이므로 경사로 놓을수있음 -> 1 1 1 이므로 경사로 놓을수있음 -> 지나갈수있는길
	// 1 열 : 3 3 -> 2 이므로 경사로 놓을수없음 -> 지나갈수없는길
	// 2 열 : 3 3 -> 2 이므로 경사로 놓을수없음 -> 지나갈수없는길
	// 3 열 : 3 3 3 -> 2 이므로 경사로 놓을수없음 -> 지나갈수없는길
	// 4 열 : 3 3 -> 2 2 이므로 경사로 놓을수있음 -> 3 3 이므로 경사로를 놓으면 경사로가 겹쳐짐 -> 지나갈수없는길
	// 5 열 : 3 3 3 -> 2 이므로 경사로 놓을수없음 -> 지나갈수없는길

	int resultCnt = 0; // 지나갈수있는길의 수

	// 행 체크
	for (int i = 0; i < n; i++)
	{
		int standardPos = graph[i][0]; // 기준위치 : 각 행의 첫 요소로 초기화
		int length = 1; // 길이
		bool isOk = true; // 지나갈수있는 행인지 체크

		for (int j = 1; j < n; j++) // 각 행의 두번째 요소부터 비교하면서
		{
			if (standardPos < graph[i][j]) // 기준위치보다 커지는 수를 만나면
			{
				// 높이 체크와 길이 체크
				// 높이차가 1이면서 길이가 L 이상이면 경사로를 놓아 지나갈수있으므로
				// 만약 경사로를 놓지 않은 상태라면 경사로를 놓았다고 체크
				// 만약 경사로를 이미 놓은 상태라면 지나갈수없는길
				// 여기 위치로 기준위치와 길이 초기화
				if (graph[i][j] - standardPos == 1 && length >= l)
				{
					for (int k = 1; k < 1 + l; k++) // 경사로를 놓을 자리가 이미 놓은적이 있는지 체크
					{
						if (j - k < 0) // 경계체크
						{
							isOk = false;
							break;
						}

						if (vis[i][j - k]) // 이미 놓은적이 있다면 지나갈수없는길
						{
							isOk = false;
							break;
						}

						// 경사로를 놓은적이 없다면 놓기
						vis[i][j - k] = true;
					}

					// 여기 위치로 기준위치와 길이 초기화
					standardPos = graph[i][j];
					length = 1;

					continue;
				}
				else // 높이차가 1보다 크거나 길이가 l 보다 짧으면 경사로를 못놓아서 지나갈수없음
				{
					isOk = false;
					break;
				}
			}
			else if (standardPos > graph[i][j]) // 기준위치보다 작아지는 수를 만나면
			{
				// 높이체크
				// 일단 높이차가 1이어야함
				if (standardPos - graph[i][j] == 1)
				{
					// 일단 경사로 놓기
					vis[i][j] = true;

					// 여기서 같은높이의 칸이 l개 있어야함
					for (int k = 1; k < l; k++)
					{
						if (j + k >= n) // 경계체크
						{
							isOk = false;
							break;
						}

						// 하나라도 높이가 다른칸이 있으면 못놓음
						// 여기는 이미 놓은자리인지 체크할필요없음
						if (graph[i][j] != graph[i][j + k])
						{
							isOk = false;
							break;
						}

						// 경사로 놓기
						vis[i][j + k] = true;
					}

					if (!isOk)
					{
						break;
					}

					// 여기 위치로 기준위치와 길이 초기화
					standardPos = graph[i][j];
					length = 1;

					continue;
				}
				else // 높이차가 1보다 크면 경사로를 못놓아서 지나갈수없음
				{
					isOk = false;
					break;
				}
			}

			length++; // 길이증가 : 아직 기준위치보다 높은칸, 낮은칸을 만나지 않았으므로
		}

		// 경사로 체크배열 초기화
		for (int j = 0; j < n; j++)
		{
			vis[i][j] = false;
		}

		// 지나갈수있는길이면 카운팅
		if (isOk)
		{
			resultCnt++;
		}
	}

	// 열 체크
	for (int i = 0; i < n; i++)
	{
		int standardPos = graph[0][i]; // 기준위치 : 각 열의 첫 요소로 초기화
		int length = 1; // 길이
		bool isOk = true; // 지나갈수있는 열인지 체크

		for (int j = 1; j < n; j++) // 각 열의 두번째 요소부터 비교하면서
		{
			if (standardPos < graph[j][i]) // 기준위치보다 커지는 수를 만나면
			{
				// 높이 체크와 길이 체크
				// 높이차가 1이면서 길이가 L 이상이면 경사로를 놓아 지나갈수있으므로
				// 만약 경사로를 놓지 않은 상태라면 경사로를 놓았다고 체크
				// 만약 경사로를 이미 놓은 상태라면 지나갈수없는길
				// 여기 위치로 기준위치와 길이 초기화
				if (graph[j][i] - standardPos == 1 && length >= l)
				{
					for (int k = 1; k < 1 + l; k++) // 경사로를 놓을 자리가 이미 놓은적이 있는지 체크
					{
						if (j - k < 0) // 경계체크
						{
							isOk = false;
							break;
						}

						if (vis[j - k][i]) // 이미 놓은적이 있다면 지나갈수없는길
						{
							isOk = false;
							break;
						}

						// 경사로를 놓은적이 없다면 놓기
						vis[j - k][i] = true;
					}

					// 여기 위치로 기준위치와 길이 초기화
					standardPos = graph[j][i];
					length = 1;

					continue;
				}
				else // 높이차가 1보다 크거나 길이가 l 보다 짧으면 경사로를 못놓아서 지나갈수없음
				{
					isOk = false;
					break;
				}
			}
			else if (standardPos > graph[j][i]) // 기준위치보다 작아지는 수를 만나면
			{
				// 높이체크
				// 일단 높이차가 1이어야함
				if (standardPos - graph[j][i] == 1)
				{
					// 일단 경사로 놓기
					vis[j][i] = true;

					// 여기서 같은높이의 칸이 l개 있어야함
					for (int k = 1; k < l; k++)
					{
						if (j + k >= n) // 경계체크
						{
							isOk = false;
							break;
						}

						// 하나라도 높이가 다른칸이 있으면 못놓음
						// 여기는 이미 놓은자리인지 체크할필요없음
						if (graph[j][i] != graph[j + k][i])
						{
							isOk = false;
							break;
						}

						// 경사로 놓기
						vis[j + k][i] = true;
					}

					if (!isOk)
					{
						break;
					}

					// 여기 위치로 기준위치와 길이 초기화
					standardPos = graph[j][i];
					length = 1;

					continue;
				}
				else // 높이차가 1보다 크면 경사로를 못놓아서 지나갈수없음
				{
					isOk = false;
					break;
				}
			}

			length++; // 길이증가 : 아직 기준위치보다 높은칸, 낮은칸을 만나지 않았으므로
		}

		// 경사로 체크배열 초기화
		for (int j = 0; j < n; j++)
		{
			vis[j][i] = false;
		}

		// 지나갈수있는길이면 카운팅
		if (isOk)
		{
			resultCnt++;
		}
	}

	cout << resultCnt << '\n';

	return 0;
}