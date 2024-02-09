#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

// 정사각형 그리기
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M 6, 8
	cin >> n >> m;

	vector<vector<int> > graph(n, vector<int>(m)); // 그래프
	vector<int> cnts(1001); // 정사각형 개수 저장
	queue<pair<int, int> > checkPos; // 체크할 위치
	int recSize = 1; // 현재 사각형 크기
	
	// 입력이 string으로 들어옴;;
	// 크기가 1인 정사각형 좌표 및 개수 저장
	//	00001010
	//	00011110
	//	00011000
	//	00011110
	//	11111110
	//	11111110
	for (int i = 0; i < n; i++)
	{
		string inputString;
		cin >> inputString;

		for (int j = 0; j < m; j++)
		{
			graph[i][j] = inputString[j] - '0';

			if (inputString[j] - '0' == 1)
			{
				checkPos.push({ i, j });
				cnts[recSize]++;
			}
		}
	}
	
	// 큐가 빌때까지 : 큐가 비었다는것은 더이상 다음 정사각형을 만들수없다는것
	// 이전 크기 사각형 개수만큼 돌면서 큐에서 꺼내면서 : 이전 크기 사각형 개수 좌표에서만 다음 정사각형을 만들수있는지 체크하면 되므로
	// 꺼낸 좌표부터 정사각형을 만들수있으면 좌표 및 개수 저장
	// for문 끝나면 현재 정사각형 사이즈 증가 : 다음 크기의 정사각형 개수를 구하기위해
	while (!checkPos.empty())
	{
		for (int i = 0; i < cnts[recSize]; i++) // 이전 크기 사각형의 개수만큼 돌면서
		{
			// 꺼내면서
			pair<int, int> standardPos = checkPos.front();
			checkPos.pop();

			// 경계를 벗어나면 정사각형을 만들수없음
			if (standardPos.first + recSize + 1 > n || standardPos.second + recSize + 1 > m)
			{
				continue;
			}

			// 정사각형을 만들수있는지 체크
			bool isSquare = true;

			for (int j = standardPos.first; j < standardPos.first + recSize + 1; j++)
			{
				for (int k = standardPos.second; k < standardPos.second + recSize + 1; k++)
				{
					if (graph[j][k] != 1) // 하나라도 1이 아니면 정사각형을 만들수없음
					{
						isSquare = false;
						break;
					}
				}

				if (!isSquare)
				{
					break;
				}
			}

			// 정사각형을 만들수있다면 좌표 및 다음 정사각형 개수 증가
			if (isSquare) 
			{
				checkPos.push(standardPos);
				cnts[recSize + 1]++;
			}
		}

		// for문이 끝나면 다음 정사각형의 개수를 구하기위해 사이즈 증가
		recSize++;
	}

	// 정사각형 크기와 개수 출력
	for (int i = 1; i < recSize; i++)
	{
		cout << i << ' ' << cnts[i] << '\n';
	}

	return 0;
}