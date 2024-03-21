#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 열쇠
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int tc; // TC 3
	cin >> tc;

	int h, w; // H, W 5, 17
	string inputString; // 입력문자열

	queue<pair<int, int> > checkPos; // 체크 할 위치
	vector<pair<int, int> > checkDir; // 상하좌우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	// TC 개수만큼 돌면서
	while (tc--)
	{
		cin >> h >> w;

		vector<vector<char> > graph(h, vector<char>(w)); // 그래프
		vector<pair<int, int> > borderPos; // 그래프의 경계 좌표
		map<char, int> keys; // 소유중인 열쇠
		int docuCnt = 0; // 훔친 문서 개수

		//	*****************
		//	.............**$*
		//	*B*A*P*C**X*Y*.X.
		//	*y*x*a*p**$*$**$*
		//	*****************
		// 상근이가 시작할수있는 위치 : 일단 경계 좌표이면서 벽이 아닌 좌표만 저장
		for (int i = 0; i < h; i++)
		{
			cin >> inputString;

			for (int j = 0; j < w; j++)
			{
				graph[i][j] = inputString[j];

				if ((i == 0 || j == 0 || i == h - 1 || j == w - 1) && graph[i][j] != '*')
				{
					borderPos.push_back({ i, j });
				}
			}
		}

		cin >> inputString;

		// cz
		for (int i = 0; i < inputString.size(); i++)
		{
			keys[inputString[i]]++;
		}

		// 상근이 시작위치부터 BFS 돌리면서 더이상 열쇠를 발견하지 못하면 종료
		while (true)
		{
			vector<vector<bool> > vis(h, vector<bool>(w)); // 방문체크
			int findKeyCnt = 0; // 열쇠를 찾은 횟수

			// 상근이가 시작할수있는 위치
			// 1. 경계의 벽이아닌곳에서 빈칸인곳
			// 2. 경계의 벽이아닌곳에서 대문자면 해당 열쇠를 가지고 있는곳
			// 3. 경계의 벽이아닌곳에서 소문자면 해당 열쇠 맵핑하고 빈칸으로
			// 4. 경계의 벽이아닌곳에서 문서면 훔친 문서 개수 카운팅 후 빈칸으로 
			for (int i = 0; i < borderPos.size(); i++)
			{
				// 일단 현재 경계의 문자를 가져옴
				char curChar = graph[borderPos[i].first][borderPos[i].second];

				if (isupper(curChar)) // 대문자면
				{
					if (keys[tolower(graph[borderPos[i].first][borderPos[i].second])] == 0)
					{
						continue;
					}
					else
					{
						graph[borderPos[i].first][borderPos[i].second] = '.';
					}
				}
				else if (islower(curChar)) // 소문자면
				{
					keys[graph[borderPos[i].first][borderPos[i].second]]++;
					graph[borderPos[i].first][borderPos[i].second] = '.';
					findKeyCnt++;
				}
				else if (curChar == '$') // 문서면
				{
					docuCnt++;
					graph[borderPos[i].first][borderPos[i].second] = '.';
				}

				checkPos.push(borderPos[i]);
				vis[borderPos[i].first][borderPos[i].second] = true;
			}

			while (!checkPos.empty()) // 큐가 빌때까지
			{
				// 기준위치 꺼냄
				pair<int, int> standardPos = checkPos.front();
				checkPos.pop();

				// 상하좌우
				for (int i = 0; i < 4; i++)
				{
					// 체크 할 위치
					int checkI = standardPos.first + checkDir[i].first;
					int checkJ = standardPos.second + checkDir[i].second;

					// 경계체크
					if (checkI < 0 || checkJ < 0 || checkI >= h || checkJ >= w)
					{
						continue;
					}

					// 방문체크
					if (vis[checkI][checkJ])
					{
						continue;
					}

					// 벽체크
					if (graph[checkI][checkJ] == '*')
					{
						continue;
					}

					// 알파벳 대문자를 만나면 해당 대문자를 열수있는 열쇠가 없으면 continue 있으면 빈칸으로
					if (isupper(graph[checkI][checkJ]))
					{
						if (keys[tolower(graph[checkI][checkJ])] == 0)
						{
							continue;
						}
						else
						{
							graph[checkI][checkJ] = '.';
						}
					}

					// 알파벳 소문자를 만나면 해당 열쇠를 맵핑하고 빈칸으로 바꿈
					if (islower(graph[checkI][checkJ]))
					{
						keys[graph[checkI][checkJ]]++;
						graph[checkI][checkJ] = '.';
						findKeyCnt++;
					}

					// 문서를 만나면 훔친 문서 카운팅하고 빈칸으로 바꿈
					if (graph[checkI][checkJ] == '$')
					{
						docuCnt++;
						graph[checkI][checkJ] = '.';
					}

					// 큐에저장 방문체크
					checkPos.push({ checkI, checkJ });
					vis[checkI][checkJ] = true;
				}
			}

			// 디버깅용
			//for (auto a : graph)
			//{
			//	for (auto b : a)
			//	{
			//		cout << b << ' ';
			//	}
			//	cout << '\n';
			//}

			// 열쇠를 발견한 횟수가 없으면 종료
			if (findKeyCnt == 0)
			{
				break;
			}
		}

		// 훔친 문서의 갯수 출력
		cout << docuCnt << '\n';
	}

	return 0;
}