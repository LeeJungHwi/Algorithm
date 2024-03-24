#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 시그널
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// .(0) #(1)
	// 시그널 길이가 항상 5의 배수
	// 시그널을 같은길이의 시그널 5개로 쪼개고 #을 흑 .을 백으로 표시하면 숫자를 나타냄
	// 시그널 규칙
	// 1.#과 .으로 이루어져있음
	// 2.해독시 반드시 숫자가 1개이상 존재함
	// 3.모든 #은 올바른 숫자 패턴에 포함됨
	// 4.숫자와 숫자 사이에는 1열 이상의 공백이 존재함, 공백은 열이 모두 .인 열을 의미함
	// 5.0부터 9는 문제의 그림처럼 표시됨
	// 숫자 1은 다른숫자들과 다르게 1열을 차지함

	int signalLength; // 시그널 길이 40
	cin >> signalLength;

	vector<vector<char> > graph(5, vector<char>(signalLength / 5)); // 그래프
	vector<vector<bool> > vis(5, vector<bool>(signalLength / 5)); // 그래프
	queue<pair<int, int> > checkPos; // 체크 할 위치
	vector<pair<int, int> > checkDir; // 상하좌우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });
	
	string signalString; // 시그널 문자열 ###..#..#.#..#..###..#..#.#..#..###..#..
	cin >> signalString;

	//# # # . . # . .
	//# . # . . # . .
	//# # # . . # . .
	//# . # . . # . .
	//# # # . . # . .
	for (int i = 0; i < 5; i++)
	{
		for (int j = i * signalLength / 5; j < i * signalLength / 5 + signalLength / 5; j++)
		{
			graph[i][j - i * signalLength / 5] = signalString[j];
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

	// 5 : 1
	// 7 : 7
	// 9 : 4
	// 11 : 2, 3, 5
	// -> 2는 시작한 # 위치의 아래 세칸에 방문체크가 되어있어야함
	// -> 5는 시작한 # 위치의 아래 한칸에 방문체크가 되어있어야함
	// -> 2도 아니고 5도 아니면 3임
	// 12 : 0, 6, 9
	// -> 0은 시작한 # 위치의 오른쪽 한칸 아래 세칸에 방문체크가 안 되어있어야함
	// -> 6은 시작한 # 위치의 아래 세칸에 방문체크가 되어있어야함
	// -> 0도 아니고 6도 아니면 9임
	// 13 : 8

	// 1.그래프의 0행을 돌면서 #을 만나면 BFS 돌림
	// 2.# 개수에 따라 어떤숫자인지 확인함
	// 3.# 개수가 같은 숫자는 각 숫자의 특징에 따라 구분함

	string interpretString; // 해석한 문자열

	for (int i = 0; i < signalLength / 5; i++) // 0행 돌면서
	{
		if (graph[0][i] == '#' && !vis[0][i]) // #을 만나면
		{
			// BFS 돌림
			checkPos.push({ 0, i });
			vis[0][i] = true;
			int sharpCnt = 1;

			while (!checkPos.empty()) // 큐가 빌때까지
			{
				// 기준위치 꺼냄
				pair<int, int> standardPos = checkPos.front();
				checkPos.pop();

				// 상하좌우
				for (int j = 0; j < 4; j++)
				{
					// 체크 할 위치
					int checkI = standardPos.first + checkDir[j].first;
					int checkJ = standardPos.second + checkDir[j].second;

					// 경계체크
					if (checkI < 0 || checkJ < 0 || checkI >= 5 || checkJ >= signalLength / 5)
					{
						continue;
					}

					// 방문체크
					if (vis[checkI][checkJ])
					{
						continue;
					}
					
					// 0 체크
					if (graph[checkI][checkJ] == '.')
					{
						continue;
					}

					// 큐에저장, 방문체크, #개수증가
					checkPos.push({ checkI, checkJ });
					vis[checkI][checkJ] = true;
					sharpCnt++;
				}
			}

			// 2.# 개수에 따라 어떤숫자인지 확인함
			// 3.# 개수가 같은 숫자는 각 숫자의 특징에 따라 구분함
			// 5 : 1
			// 7 : 7
			// 9 : 4
			// 11 : 2, 3, 5
			// -> 2는 시작한 # 위치의 아래 세칸에 방문체크가 되어있어야함
			// -> 5는 시작한 # 위치의 아래 한칸에 방문체크가 되어있어야함
			// -> 2도 아니고 5도 아니면 3임
			// 12 : 0, 6, 9
			// -> 6은 시작한 # 위치의 오른쪽 두칸 아래 한칸에 방문체크가 안 되어있어야함
			// -> 9는 시작한 # 위치의 아래 세칸에 방문체크가 안 되어있어야함
			// -> 6도 아니고 9도 아니면 0임
			// 13 : 8
			if (sharpCnt == 5)
			{
				interpretString += '1';
			}
			else if (sharpCnt == 7)
			{
				interpretString += '7';
			}
			else if (sharpCnt == 9)
			{
				interpretString += '4';
			}
			else if (sharpCnt == 13)
			{
				interpretString += '8';
			}
			else if (sharpCnt == 11)
			{
				if (vis[3][i])
				{
					interpretString += '2';
				}
				else if (vis[1][i])
				{
					interpretString += '5';
				}
				else
				{
					interpretString += '3';
				}
			}
			else if (sharpCnt == 12)
			{
				if (!vis[1][i + 2])
				{
					interpretString += '6';
				}
				else if (!vis[3][i])
				{
					interpretString += '9';
				}
				else
				{
					interpretString += '0';
				}
			}
		}
	}

	cout << interpretString << '\n';

	return 0;
}