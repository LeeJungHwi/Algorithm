#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// 거리 두기
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 10
	cin >> n;

	/*
	0이 1개 : 거리 1
	0이 2개 : 거리 1
	0이 3개 : 거리 2
	0이 4개 : 거리 2
	0이 5개 : 거리 3
	....
	*/
	// max(최대연속 0의 개수, 첫자리가 빈자리일때 연속 0의 개수, 마지막자리가 빈자리일때 연속 0의 개수) 출력

	int maxZeroCnt = 0; // 최대연속 0의 개수
	int zeroCnt = 0; // 연속 0의 개수

	int num; // 빈자리(0) 인지 이미앉은자리 (1) 인지

	bool isFirst = false; // 첫자리가 빈자리인지 체크
	bool isLast = false; // 마지막자리가 빈자리인지 체크

	int firstZeroCnt = 0; // 첫자리가 빈자리일때 연속 0의 개수 저장
	int lastZeroCnt = 0; // 마지막자리가 빈자리일때 연속 0의 개수 저장

	vector<int> seats(n); // 좌석 정보

	// 1 0 0 0 1 0 0 1 0 1
	for (int i = 0; i < n; i++)
	{
		cin >> num;

		seats[i] = num;

		if (i == 0 && num == 0)
		{
			isFirst = true;
		}

		if (i == n - 1 && num == 0)
		{
			isLast = true;
		}

		if (num == 0) // 빈자리면 연속 0의 개수 증가
		{
			zeroCnt++;

			// 최대연속 0의 개수 갱신
			if (maxZeroCnt < zeroCnt)
			{
				maxZeroCnt = zeroCnt;
			}
		}
		else // 이미 앉은자리면 연속 0의 개수 초기화
		{
			zeroCnt = 0;
		}
	}

	// 첫자리가 빈자리일때 연속 0의 개수 구하기
	if (isFirst)
	{
		for (int i = 0; i < n; i++)
		{
			if (seats[i] == 0) // 빈자리 만나면 연속 0의 개수 증가
			{
				firstZeroCnt++;
			}
			else // 앉은자리 만나면 종료
			{
				break;
			}
		}
	}

	// 마지막자리가 빈자리일때 연속 0의 개수 구하기
	if (isLast)
	{
		for (int i = n - 1; i > -1; i--)
		{
			if (seats[i] == 0) // 빈자리 만나면 연속 0의 개수 증가
			{
				lastZeroCnt++;
			}
			else // 앉은자리 만나면 종료
			{
				break;
			}
		}
	}

	// 0이 홀수개 : 최대연속 0의 개수 / 2 + 1
	// 0이 짝수개 : 최대연속 0의 개수 / 2
	if (maxZeroCnt % 2 == 1)
	{
		maxZeroCnt = maxZeroCnt / 2 + 1;
	}
	else
	{
		maxZeroCnt = maxZeroCnt / 2;
	}

	// max(최대연속 0의 개수, 첫자리가 빈자리일때 연속 0의 개수, 마지막자리가 빈자리일때 연속 0의 개수) 출력
	maxZeroCnt = max(maxZeroCnt, firstZeroCnt);
	maxZeroCnt = max(maxZeroCnt, lastZeroCnt);

	cout << maxZeroCnt;

	return 0;
}