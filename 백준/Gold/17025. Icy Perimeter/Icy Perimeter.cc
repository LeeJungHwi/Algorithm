#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// Icy Perimeter
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 6
	cin >> n;

	vector<vector<int> > graph(n, vector<int>(n)); // 그래프
	queue<pair<int, int> > checkPos; // 체크 할 위치
	vector<pair<int, int> > checkDir; // 상하좌우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	// 그래프 초기화
	// 라벨링 하기위해 #은 -1 .은 -2로 치환
	string inputString;
	for (int i = 0; i < n; i++)
	{
		cin >> inputString;
		for (int j = 0; j < n; j++)
		{
			if (inputString[j] == '#') graph[i][j] = -1;
			else if (inputString[j] == '.') graph[i][j] = -2;
		}
	}

	// 1.그래프 돌면서 BFS 돌리고 각 영역 라벨링
	// 2.각 라벨 영역에 해당하는 위치 맵핑
	// 3.영역크기와 영역크기에 해당하는 라벨들 맵핑
	// 3.가장 큰 영역을 가지는 라벨의 영역넓이 및 영역둘레 구하기 => 영역둘레는 라벨이 여러개면 그 중 최솟값

	map<int, vector<int> > maxLabelArea; // (영역 크기, 해당 영역 크기인 라벨) 맵핑 => 마지막 이터레이터 키가 영역넓이고 값에 해당하는 라벨의 둘레넓이 중 최솟값을 구해야함
	map<int, vector<pair<int, int> > > labelPos; // 각 라벨에 해당하는 영역 위치 맵핑
	int curLabel = 0; // 현재 라벨
	int maxLabelRound = 214700000; // 가장 큰 영역을 가지는 라벨의 둘레길이 => 가장 큰 영역을 가지는 라벨이 여러개면 그 중 최솟값

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (graph[i][j] == -1)
			{
				checkPos.push({ i, j });
				graph[i][j] = ++curLabel;
				int area = 1;
				labelPos[curLabel].push_back({ i, j });

				// 큐가 빌때까지
				while (!checkPos.empty())
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
						if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= n) continue;

						// 방문체크(라벨로)
						if (graph[checkI][checkJ] > 0) continue;

						// 벽체크
						if (graph[checkI][checkJ] == -2) continue;

						// 큐에저장, 라벨링, 영역넓이 누적, 위치 맵핑
						checkPos.push({ checkI, checkJ });
						graph[checkI][checkJ] = graph[i][j];
						area++;
						labelPos[curLabel].push_back({ checkI, checkJ });
					}
				}

				// (영역 크기, 해당 영역 크기인 라벨) 맵핑
				maxLabelArea[area].push_back(curLabel);
			}
		}
	}

	//for (auto a : graph)
	//{
	//	for (auto b : a)
	//	{
	//		cout << b << ' ';
	//	}
	//	cout << '\n';
	//}
	//cout << maxLabel << ' ' << maxLabelArea << '\n';

	// 가장 큰 영역 라벨 둘레길이 구하기
	// 1.가장 큰 영역 라벨들에 해당하는 영역 위치 돌면서
	// 2.각 위치에 대해 상하좌우 보면서 벽을 만나거나 경계를 만나면 카운팅 하고 둘레 최솟값 갱신

	auto endIt = --maxLabelArea.end();

	for (int i = 0; i < endIt->second.size(); i++)
	{
		int labelRound = 0;

		for (int j = 0; j < labelPos[endIt->second[i]].size(); j++)
		{
			// 영역 위치 꺼내와서
			pair<int, int> standardPos = labelPos[endIt->second[i]][j];

			// 상하좌우
			for (int k = 0; k < 4; k++)
			{
				// 체크 할 위치
				int checkI = standardPos.first + checkDir[k].first;
				int checkJ = standardPos.second + checkDir[k].second;

				// 경계체크
				if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= n)
				{
					labelRound++;
					continue;
				}

				// 벽체크
				if (graph[checkI][checkJ] == -2)
				{
					labelRound++;
					continue;
				}
			}
		}

		// 둘레 최솟값 갱신
		maxLabelRound = min(maxLabelRound, labelRound);
	}

	cout << endIt->first << ' ' << maxLabelRound << '\n';

	return 0;
}