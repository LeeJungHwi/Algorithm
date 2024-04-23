#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

// 붐버맨 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// r by c 0-based
	// 각 요소에는 빈칸 또는 폭탄
	// 폭탄 : 3초 후에 폭발, 폭발 후 폭탄이 있던칸과 인접한 네방향의 칸이 빈칸이됨
	// 인접한 방향에 폭탄이 있으면 그건 폭발하지않고 빈칸이됨
	// 붐버맨은 모든칸을 자유롭게 아래처럼 이동함
	/*
	1.처음에 봄버맨이 일부 칸에 폭탄을 설치함
	2.다음 1초 동안 봄버맨은 아무것도 하지않음
	3.다음 1초 동안 폭탄이 설치되어있지않은 모든 칸에 폭탄을 설치함 -> 모든 칸이 폭탄을 가지게됨
	4.다음 1초 동안 3초전에 설치된 폭탄이 모두 폭발함
	5.3과 4를 반복함
	*/

	// N초가 지난 후 그래프 출력하기

	/*
	1.처음 폭탄 설치
	. . .
	. o .
	. . .

	2.n 1초 이전폭탄 1초
	. . .
	. o .
	. . .

	3.n 2초 이전폭탄 2초
	o o o
	o o o
	o o o

	4.n 3초 이전폭탄 3초 이전폭탄 1초
	o . o
	. . .
	o . o

	3.n 4초 이전폭탄 2초
	o o o
	o o o
	o o o

	4.n 5초 이전폭탄 3초 이전폭탄 1초
	. . .
	. o .
	. . .

	3.n 6초 이전폭탄 2초
	o o o
	o o o
	o o o

	4.n 7초 이전폭탄 3초 이전폭탄 1초
	o . o
	. . .
	o . o
	*/

	// 3초
	//	OOO.OOO
	//	OO...OO
	//	OOO...O
	//	..OO.OO
	//	...OOOO
	//	...OOOO

	// 4초
	//	OOOOOOO
	//	OOOOOOO
	//	OOOOOOO
	//	OOOOOOO
	//	OOOOOOO
	//	OOOOOOO

	// 5초
	//	.......
	//	...O...
	//	....O..
	//	.......
	//	OO.....
	//	OO.....

	// 6초
	//	OOOOOOO
	//	OOOOOOO
	//	OOOOOOO
	//	OOOOOOO
	//	OOOOOOO
	//	OOOOOOO

	// 7초
	//	OOO.OOO
	//	OO...OO
	//	OOO...O
	//	..OO.OO
	//	...OOOO
	//	...OOOO

	// 8초
	//	OOOOOOO
	//	OOOOOOO
	//	OOOOOOO
	//	OOOOOOO
	//	OOOOOOO
	//	OOOOOOO

	// 9초
	//	.......
	//	...O...
	//	....O..
	//	.......
	//	OO.....
	//	OO.....

	// 10초
	//	OOOOOOO
	//	OOOOOOO
	//	OOOOOOO
	//	OOOOOOO
	//	OOOOOOO
	//	OOOOOOO

	// 11초
	//	OOO.OOO
	//	OO...OO
	//	OOO...O
	//	..OO.OO
	//	...OOOO
	//	...OOOO

	// 12초
	//	OOOOOOO
	//	OOOOOOO
	//	OOOOOOO
	//	OOOOOOO
	//	OOOOOOO
	//	OOOOOOO

	// 13초
	//	.......
	//	...O...
	//	....O..
	//	.......
	//	OO.....
	//	OO.....

	// 1 => 초기 그래프랑 같음 => n == 1 인경우
	// 3, 7, 11 => 3초후 그래프랑 같음 => (n - 3) % 4 == 0 인경우
	// 2, 4, 6, 8, 10, 12 => 2초후 그래프랑 같음 => n % 2 == 0 인경우
	// 5, 9, 13 => 5초후 그래프랑 같음 => (n - 5 ) % 4 == 0 인경우

	int r, c, n; // R, C, N 6, 7, 3
	cin >> r >> c >> n;

	vector<vector<char> > graph(r, vector<char>(c)); // 그래프
	queue<pair<int, int> > checkPos; // 체크 할 위치
	vector<pair<int, int> > checkDir; // 상하좌우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	//	.......
	//	...O...
	//	....O..
	//	.......
	//	OO.....
	//	OO.....
	// 처음 폭탄위치 큐에 저장
	string inputString;

	for (int i = 0; i < r; i++)
	{
		cin >> inputString;

		for (int j = 0; j < c; j++)
		{
			graph[i][j] = inputString[j];

			if (graph[i][j] == 'O')
			{
				checkPos.push({ i, j });
			}
		}
	}

	// 만약 입력으로 1초가 들어오면 바로 그래프 출력하기
	if (n == 1)
	{
		for (int i = 0; i < r; i++)
		{
			string outputString = "";

			for (int j = 0; j < c; j++)
			{
				outputString += graph[i][j];
			}

			cout << outputString << '\n';
		}

		return 0;
	}

	int time = 4; // 2, 3, 5초 후 그래프를 알아야함, 현재 1초가 지난상태
	vector<vector<char> > graph2(r, vector<char>(c)); // 2초후 그래프
	vector<vector<char> > graph3(r, vector<char>(c)); // 3초후 그래프
	vector<vector<char> > graph5(r, vector<char>(c)); // 5초후 그래프

	while (time)
	{
		// 시간 감소
		time--;

		// 폭탄 설치
		// 빈칸을 만나면 폭탄 설치
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (graph[i][j] == '.')
				{
					graph[i][j] = 'O';
				}
			}
		}

		// 2초후 그래프 저장
		if (time == 3)
		{
			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < c; j++)
				{
					graph2[i][j] = graph[i][j];
				}
			}
		}

		// 시간 감소
		time--;

		// 폭탄 터짐
		while (!checkPos.empty()) // 큐가 빌때까지
		{
			// 이전에 설치된 폭탄 꺼냄
			pair<int, int> standardPos = checkPos.front();
			checkPos.pop();

			// 자기 칸 빈칸으로
			graph[standardPos.first][standardPos.second] = '.';

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

				// 인접한 네방향 빈칸으로
				graph[checkI][checkJ] = '.';
			}
		}

		// 3초후 그래프 저장
		if (time == 2)
		{
			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < c; j++)
				{
					graph3[i][j] = graph[i][j];
				}
			}
		}

		// 3초후 그래프 저장
		if (time == 2)
		{
			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < c; j++)
				{
					graph3[i][j] = graph[i][j];
				}
			}
		}

		// 5초후 그래프 저장
		if (time == 0)
		{
			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < c; j++)
				{
					graph5[i][j] = graph[i][j];
				}
			}
		}

		// 그래프 돌면서 다음에 터질 폭탄 큐에 추가
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (graph[i][j] == 'O')
				{
					checkPos.push({ i, j });
				}
			}
		}
	}

	// 3, 7, 11 => 3초후 그래프랑 같음 => (n - 3) % 4 == 0 인경우
	if ((n - 3) % 4 == 0)
	{
		for (int i = 0; i < r; i++)
		{
			string outputString = "";

			for (int j = 0; j < c; j++)
			{
				outputString += graph3[i][j];
			}

			cout << outputString << '\n';
		}

		return 0;
	}

	// 2, 4, 6, 8, 10, 12 => 2초후 그래프랑 같음 => n % 2 == 0 인경우
	if (n % 2 == 0)
	{
		for (int i = 0; i < r; i++)
		{
			string outputString = "";

			for (int j = 0; j < c; j++)
			{
				outputString += graph2[i][j];
			}

			cout << outputString << '\n';
		}

		return 0;
	}

	// 5, 9, 13 => 5초후 그래프랑 같음 => (n - 5 ) % 4 == 0 인경우
	for (int i = 0; i < r; i++)
	{
		string outputString = "";

		for (int j = 0; j < c; j++)
		{
			outputString += graph5[i][j];
		}

		cout << outputString << '\n';
	}

	return 0;
}