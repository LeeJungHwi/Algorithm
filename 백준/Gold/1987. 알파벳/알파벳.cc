#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

int r, c; // R, C 2, 4
vector<vector<char> > graph(20, vector<char>(20)); // 그래프
vector<bool> isAlpha(100); // 기존 알파벳인지 체크
int alphaCnt; // 알파벳 개수
int maxAlphaCnt; // 최대 알파벳 개수
vector<pair<int, int>> checkDir = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; // 상하좌우

void DFS(int i, int j)
{
	if (i < 0 || j < 0 || i >= r || j >= c || isAlpha[graph[i][j]]) // 종료조건 : 경계를 넘어가거나 기존에 있는 알파벳인 경우
	{
		// 최대 알파벳 개수 갱신
		maxAlphaCnt = max(maxAlphaCnt, alphaCnt);

		return;
	}
	else
	{
		isAlpha[graph[i][j]] = true; // 기존알파벳체크
		alphaCnt++; // 새로운 알파벳 개수 카운팅

		// 상하좌우 체크
		for (int k = 0; k < 4; k++)
		{
			int checkI = i + checkDir[k].first;
			int checkJ = j + checkDir[k].second;

			DFS(checkI, checkJ);
		}

		isAlpha[graph[i][j]] = false; // 기존알파벳해제
		alphaCnt--; // 새로운 알파벳 개수 감소
	}
}

// 알파벳
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> r >> c;

	string inputString; // 입력문자열

	//	CAAB
	//	ADCB
	for (int i = 0; i < r; i++)
	{
		cin >> inputString;

		for (int j = 0; j < c; j++)
		{
			graph[i][j] = inputString[j];
		}
	}

	// DFS
	DFS(0, 0);

	cout << maxAlphaCnt << '\n';

	return 0;
}
// BFS -> 경로막힘 -> DFS로 해결

//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <string>
//#include <fstream>
//using namespace std;
//
//// 알파벳
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	ifstream cin;
//	cin.open("input.txt");
//
//	int r, c; // R, C 2, 4
//	cin >> r >> c;
//
//	vector<vector<char> > graph(r, vector<char>(c)); // 그래프
//	vector<bool> vis(100); // 방문체크
//	queue<pair<int, int> > checkPos; // 체크 할 위치
//	vector<pair<int, int> > checkDir; // 상하좌우
//	checkDir.push_back({ -1, 0 });
//	checkDir.push_back({ 1, 0 });
//	checkDir.push_back({ 0, -1 });
//	checkDir.push_back({ 0, 1 });
//
//	string inputString; // 입력문자열
//
//	//	CAAB
//	//	ADCB
//	for (int i = 0; i < r; i++)
//	{
//		cin >> inputString;
//
//		for (int j = 0; j < c; j++)
//		{
//			graph[i][j] = inputString[j];
//		}
//	}
//
//	// (0, 0)에서 BFS 돌리기
//	// 큐가 빌때까지
//	// 경계체크, 방문체크, 새로운알파벳을 만나면 큐에 저장 후 방문체크, 알파벳 개수 카운팅
//
//	checkPos.push({ 0, 0 });
//	vis[graph[0][0]] = true;
//
//	int alphaCnt = 1; // 알파벳 개수
//
//	while (!checkPos.empty()) // 큐가 빌때까지
//	{
//		// 기준위치 꺼냄
//		pair<int, int> standardPos = checkPos.front();
//		checkPos.pop();
//
//		// 상하좌우
//		for (int i = 0; i < 4; i++)
//		{
//			// 체크 할 위치
//			int checkI = standardPos.first + checkDir[i].first;
//			int checkJ = standardPos.second + checkDir[i].second;
//
//			// 경계체크
//			if (checkI < 0 || checkJ < 0 || checkI >= r || checkJ >= c)
//			{
//				continue;
//			}
//
//			// 방문체크
//			if (vis[graph[checkI][checkJ]])
//			{
//				continue;
//			}
//
//			// 새로운알파벳을 만나면 큐에 저장 후 방문체크, 알파벳 개수 카운팅
//			checkPos.push({ checkI, checkJ });
//			vis[graph[checkI][checkJ]] = true;
//			alphaCnt++;
//		}
//	}
//
//	cout << alphaCnt << '\n';
//
//	return 0;
//}

