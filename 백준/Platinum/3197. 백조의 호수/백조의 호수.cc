#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 백조의 호수
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int r, c; // R, C 8, 17
	cin >> r >> c;

	vector<vector<char> > graph(r, vector<char>(c)); // 그래프
	vector<vector<bool> > swanVis(r, vector<bool>(c)); // 백조 방문체크
	queue<pair<int, int> > swanPos; // 백조 체크 할 위치
	queue<pair<int, int> > nextSwanPos; // 다음날 백조 체크 할 위치
	queue<pair<int, int> > waterPos; // 물 체크 할 위치
	queue<pair<int, int> > nextWaterPos; // 다음날 물 체크 할 위치
	vector<pair<int, int> > checkDir; // 상하좌우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	string inputString; // 입력문자열
	pair<int, int> Lpos; // 백조 좌표

	//	...XXXXXX..XX.XXX
	//	....XXXXXXXXX.XXX
	//	...XXXXXXXXXXXX..
	//	..XXXXX.LXXXXXX..
	//	.XXXXXX..XXXXXX..
	//	XXXXXXX...XXXX...
	//	..XXXXX...XXX....
	//	....XXXXX.XXXL...
	// 백조 좌표 및 물 좌표 저장(백조도 물)
	for (int i = 0; i < r; i++)
	{
		cin >> inputString;

		for (int j = 0; j < c; j++)
		{
			graph[i][j] = inputString[j];

			if (graph[i][j] == 'L')
			{
				Lpos = { i, j };
				waterPos.push({ i, j });
			}
			else if (graph[i][j] == '.')
			{
				waterPos.push({ i, j });
			}
		}
	}

	int day = 0; // 걸린날짜

	// 초기 백조위치 설정(다른 백조를 찾아야니까 시작하는 백조는 빈칸으로 바꿈)
	swanPos.push(Lpos);
	graph[Lpos.first][Lpos.second] = '.';
	swanVis[Lpos.first][Lpos.second] = true;

	// 다른 백조를 만나면 종료
	while (true)
	{
		while (!nextSwanPos.empty()) // 다음날 체크할 백조 위치 가져와서 BFS 돌림
		{
			swanPos.push(nextSwanPos.front());
			nextSwanPos.pop();
		}

		while (!swanPos.empty()) // 큐가 빌때까지
		{
			// 기준위치 꺼냄
			pair<int, int> standardPos = swanPos.front();
			swanPos.pop();

			// 다른 백조를 만나면 걸린날짜 출력 후 종료
			if (graph[standardPos.first][standardPos.second] == 'L')
			{
				cout << day << '\n';

				return 0;
			}

			// 상하좌우
			for (int i = 0; i < 4; i++)
			{
				// 체크 할 위치
				int checkI = standardPos.first + checkDir[i].first;
				int checkJ = standardPos.second + checkDir[i].second;

				// 경계체크
				if (checkI < 0 || checkJ < 0 || checkI >= r || checkJ >= c)
				{
					continue;
				}

				// 방문체크
				if (swanVis[checkI][checkJ])
				{
					continue;
				}

				// 빙하체크
				if (graph[checkI][checkJ] == 'X')
				{
					swanVis[checkI][checkJ] = true;
					nextSwanPos.push({ checkI, checkJ });

					continue;
				}

				// 물 또는 백조
				swanPos.push({ checkI, checkJ });
				swanVis[checkI][checkJ] = true;
			}
		}

		// 백조를 만나지 못했으면
		// 물로 녹일수있는 빙하를 녹임

		while (!nextWaterPos.empty()) // 다음날 체크할 물 위치 가져와서 BFS 돌림
		{
			waterPos.push(nextWaterPos.front());
			nextWaterPos.pop();
		}

		while (!waterPos.empty()) // 큐가 빌때까지
		{
			// 기준위치 꺼냄
			pair<int, int> standardPos = waterPos.front();
			waterPos.pop();

			// 상하좌우
			for (int i = 0; i < 4; i++)
			{
				// 체크 할 위치
				int checkI = standardPos.first + checkDir[i].first;
				int checkJ = standardPos.second + checkDir[i].second;

				// 경계체크
				if (checkI < 0 || checkJ < 0 || checkI >= r || checkJ >= c)
				{
					continue;
				}

				// 빙하를 만나면 빈칸으로 바꾸고 다음날 물 체크 할 위치 저장
				if (graph[checkI][checkJ] == 'X')
				{
					graph[checkI][checkJ] = '.';
					nextWaterPos.push({ checkI, checkJ });
				}
			}
		}

		// 걸린날짜 카운팅
		day++;
	}

	return 0;
}

//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <string>
//#include <map>
//#include <fstream>
//using namespace std;
//
//// 백조의 호수
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	//ifstream cin;
//	//cin.open("input.txt");
//
//	int r, c; // R, C 8, 17
//	cin >> r >> c;
//
//	vector<vector<char> > graph(r, vector<char>(c)); // 그래프
//	vector<vector<bool> > vis(r, vector<bool>(c)); // 그래프
//	queue<pair<int, int> > checkPos; // 체크 할 위치
//	vector<pair<int, int> > checkDir; // 상하좌우
//	checkDir.push_back({ -1, 0 });
//	checkDir.push_back({ 1, 0 });
//	checkDir.push_back({ 0, -1 });
//	checkDir.push_back({ 0, 1 });
//
//	string inputString; // 입력문자열
//	pair<int, int> Lpos; // 백조 좌표
//
//	//	...XXXXXX..XX.XXX
//	//	....XXXXXXXXX.XXX
//	//	...XXXXXXXXXXXX..
//	//	..XXXXX.LXXXXXX..
//	//	.XXXXXX..XXXXXX..
//	//	XXXXXXX...XXXX...
//	//	..XXXXX...XXX....
//	//	....XXXXX.XXXL...
//	// 백조 좌표 저장
//	for (int i = 0; i < r; i++)
//	{
//		cin >> inputString;
//
//		for (int j = 0; j < c; j++)
//		{
//			graph[i][j] = inputString[j];
//
//			if (graph[i][j] == 'L')
//			{
//				Lpos = { i, j };
//			}
//		}
//	}
//
//	// 백조 위치부터 BFS 돌리다가 다른 백조를 만나면 걸린날짜 출력 후 종료
//	// 만약 BFS 가 끝났는데 다른 백조를 만나지못했다면
//	// 그래프를 돌면서 X를 만나면 자기주변에 .이 있으면 녹을빙하에 저장 하고 한번에 녹임
//	// 걸린날짜 카운팅, vis 초기화, Lpos 다시 L로
//
//	int day = 0; // 걸린날짜
//
//	while (true)
//	{
//		// 백조 위치부터 BFS 
//		checkPos.push(Lpos);
//		graph[Lpos.first][Lpos.second] = '.';
//		vis[Lpos.first][Lpos.second] = true;
//
//		while (!checkPos.empty()) // 큐가 빌때까지
//		{
//			// 기준위치 꺼냄
//			pair<int, int> standardPos = checkPos.front();
//			checkPos.pop();
//
//			// 백조를 만나면 걸린날짜 출력 후 종료
//			if (graph[standardPos.first][standardPos.second] == 'L')
//			{
//				cout << day << '\n';
//
//				return 0;
//			}
//
//			// 상하좌우
//			for (int i = 0; i < 4; i++)
//			{
//				// 체크 할 위치
//				int checkI = standardPos.first + checkDir[i].first;
//				int checkJ = standardPos.second + checkDir[i].second;
//
//				// 경계체크
//				if (checkI < 0 || checkJ < 0 || checkI >= r || checkJ >= c)
//				{
//					continue;
//				}
//
//				// 방문체크
//				if (vis[checkI][checkJ])
//				{
//					continue;
//				}
//
//				// 빙하체크
//				if (graph[checkI][checkJ] == 'X')
//				{
//					continue;
//				}
//
//				// 큐에 저장, 방문체크
//				checkPos.push({ checkI, checkJ });
//				vis[checkI][checkJ] = true;
//			}
//		}
//
//		// 만약 BFS 가 끝났는데 다른 백조를 만나지못했다면
//		// 그래프를 돌면서 X를 만나면 자기주변에 . 또는 L이 있으면 녹을빙하에 저장 하고 한번에 녹임
//
//		vector<pair<int, int> > meltPos; // 녹을 빙하
//
//		for (int i = 0; i < r; i++) // 그래프 돌면서
//		{
//			for (int j = 0; j < c; j++)
//			{
//				if (graph[i][j] == 'X') // X를 만나면
//				{
//					for (int k = 0; k < 4; k++) // 상하좌우
//					{
//						// 체크 할 위치
//						int checkI = i + checkDir[k].first;
//						int checkJ = j + checkDir[k].second;
//
//						// 경계체크
//						if (checkI < 0 || checkJ < 0 || checkI >= r || checkJ >= c)
//						{
//							continue;
//						}
//
//						// 빙하체크
//						if (graph[checkI][checkJ] == 'X')
//						{
//							continue;
//						}
//
//						// 여기는 물 또는 백조가 있으므로 녹을 빙하임
//						meltPos.push_back({ i, j });
//
//						break;
//					}
//				}
//			}
//		}
//
//		// 녹을 빙하 한번에 녹임
//		// 근데 백조는 빈칸으로 바꾸면 안됨
//		for (int i = 0; i < meltPos.size(); i++)
//		{
//			if (graph[meltPos[i].first][meltPos[i].second] != 'L')
//			{
//				graph[meltPos[i].first][meltPos[i].second] = '.';
//			}
//		}
//
//		// 걸린날짜 카운팅, vis 초기화, Lpos 다시 L로
//		day++;
//
//		for (int i = 0; i < r; i++)
//		{
//			for (int j = 0; j < c; j++)
//			{
//				vis[i][j] = false;
//			}
//		}
//
//		graph[Lpos.first][Lpos.second] = 'L';
//	}
//
//	return 0;
//}