#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

// 뮤직비디오
int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");
	//freopen("input.txt", "rt", stdin);

	int n, m; // N, M
	//cin >> n >> m;
	scanf_s("%d %d", &n, &m);

	int minute; // 곡의 길이
	vector<int> minutes(n); // 곡의 길이 저장

	int first = 0; // 처음
	int last = 0; // 마지막

	for (int i = 0; i < n; i++)
	{
		//cin >> minute;
		scanf_s("%d", &minute);
		minutes[i] = minute; // 6 5 8 5 6 8 7 6 6 7

		last += minute; // 64
	}

	//sort(minutes.begin(), minutes.end()); // 5 5 6 6 6 6 7 7 8 8

	first = minutes[0]; // 5

	// DVD 용량 범위는 5 ~ 64
	// DVD 최소 용량 구하기
	// first		avg				last
	// 5			34	O			64
	// 5			19	X			33
	// 20			26	O			33
	// 20			22  X			25
	// 23			24	O			25
	// 23			23  O			23
	// 23			>				22 -> first와 last가 역전되므로 종료
	// DVD 최소 용량 : 23

	int least = (first + last) / 2; // DVD 최소용량

	while (first <= last) // first와 last가 역전되면 종료
	{
		int avg = (first + last) / 2; // DVD 용량
		int dvdCnt = 0; // dvd 개수
		int sumMinute = 0; // dvd 길이 합

		for (int i = 0; i < n; i++)
		{
			sumMinute += minutes[i]; // dvd 길이 더하기

			if (sumMinute > avg) // dvd 용량을 초과하면 처리
			{
				sumMinute = minutes[i]; // 초과한 인덱스의 길이로 초기화
				dvdCnt++;
			}

			if (dvdCnt == m) // dvd 개수가 m이 된순간 m + 1번째 dvd에 minutes[i]가 있으므로 개수를 초과한 상태로 종료
			{
				break;
			}
		}

		if (sumMinute != 0) // 마지막 dvd
		{
			dvdCnt++;
		}

		if (dvdCnt <= m) // 가능한 용량
		{
			last = avg - 1; // 마지막 갱신

			if (least > avg) // 최소길이 갱신
			{
				least = avg;
			}
		}
		else // 불가능한 용량
		{
			first = avg + 1; // 처음 갱신
		}
	}

	//cout << least << '\n';
	printf("%d\n", least);

	return 0;
}

// 핵심
// 곡의 순서를 바꾸지 말아야하므로 정렬 X -> 이진탐색은 정렬된상태에서만 적용가능한 고정관념 버리기