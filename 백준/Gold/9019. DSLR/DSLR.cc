#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

// DSLR
int DSLR(int num, char type)
{
	switch (type)
	{
		case 'D':
		{
			// n을 두배로
			int temp = 2 * num;

			// 9999보다 큰 경우 모듈러
			if (temp > 9999)
			{
				temp %= 10000;
			}

			return temp;
		}
		case 'S':
		{
			// n - 1
			int temp = num - 1;

			// 0이면 9999
			if (num == 0)
			{
				temp = 9999;
			}

			return temp;
		}
		case 'L':
		{
			// 왼쪽으로 회전
			int d1 = num / 1000;  // 천의 자리
			int d2 = (num % 1000) / 100;  // 백의 자리
			int d3 = (num % 100) / 10;  // 십의 자리
			int d4 = num % 10;  // 일의 자리

			if (d1 == 0 && d2 == 0 && d3 == 0) // 한 자릿수
			{
				return d4 * 10;
			}
			else if (d1 == 0 && d2 == 0) // 두 자릿수
			{
				return d3 * 100 + d4 * 10;
			}
			else if (d1 == 0) // 세 자릿수
			{
				return d2 * 1000 + d3 * 100 + d4 * 10;
			}
			else // 네 자릿수
			{
				return d2 * 1000 + d3 * 100 + d4 * 10 + d1;
			}
		}
		case 'R':
		{
			// 오른쪽으로 회전
			int d1 = num / 1000;  // 천의 자리
			int d2 = (num % 1000) / 100;  // 백의 자리
			int d3 = (num % 100) / 10;  // 십의 자리
			int d4 = num % 10;  // 일의 자리

			if (d1 == 0 && d2 == 0 && d3 == 0) // 한 자릿수
			{
				return d4 * 1000;
			}
			else if (d1 == 0 && d2 == 0) // 두 자릿수
			{
				return d4 * 1000 + d3;
			}
			else if (d1 == 0) // 세 자릿수
			{
				return d4 * 1000 + d2 * 10 + d3;
			}
			else // 네 자릿수
			{
				return d4 * 1000 + d1 * 100 + d2 * 10 + d3;
			}
		}
	}
}

// DSLR
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 3
	cin >> n;

	vector<char> dslr; // DSLR
	dslr.push_back('D');
	dslr.push_back('S');
	dslr.push_back('L');
	dslr.push_back('R');

	//	1234 3412
	//	1000 1
	//	1 16
	for (int i = 0; i < n; i++)
	{
		int A, B;
		cin >> A >> B;

		queue<pair<int, string>> checkPos; // 체크 할 위치와 명령어 순서 저장
		vector<bool> vis(10000); // 방문체크

		// 1234 부터 BFS 돌리기
		// 1000 부터 BFS 돌리기
		// 1 부터 BFS 돌리기
		checkPos.push({ A, "" });
		vis[A] = true;

		while (!checkPos.empty()) // 큐가 빌때까지
		{
			// 기준위치 꺼냄
			pair<int, string> standardPos = checkPos.front();
			checkPos.pop();

			// 종료조건 : B로 변환이 완료되었을때 명령어 순서 출력 후 종료
			if (standardPos.first == B)
			{
				cout << standardPos.second << '\n';
				break;
			}

			// DSLR
			int checkNum; // 체크 할 위치
			string checkCommand; // 명령어 순서

			for (int i = 0; i < 4; i++)
			{
				checkNum = DSLR(standardPos.first, dslr[i]);

				// 방문체크
				if (vis[checkNum])
				{
					continue;
				}

				// 경계체크
				if (checkNum < 0 || checkNum > 10000)
				{
					continue;
				}

				// 방문체크, 이전 명령어 순서 + 수행한 명령어로 명령어 갱신, 큐에 저장
				vis[checkNum] = true;
				checkCommand = standardPos.second + dslr[i];
				checkPos.push({ checkNum, checkCommand });
			}
		}
	}

	return 0;
}
