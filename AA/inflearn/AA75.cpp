#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// 구조체 스케쥴링
struct LectureSort
{
	int m, d;

	LectureSort(int money, int day) // 생성자
	{
		m = money;
		d = day;
	}

	bool operator<(LectureSort &lectureSort) // 정렬기준 : 기한이 많이남은 순서로 정렬 -> 마지막 날 강연부터 첫 날 강연 순으로 스케쥴링 하기위해
	{
		return d > lectureSort.d;
	}
};

// 최대 수입 스케줄
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	int m, d; // m, d
	int maxD = 0; // 현수가 강의하는 마지막 날

	vector<LectureSort> lectureSort; // 강의 정렬
	priority_queue<int> schedule; // 스케쥴링 수행
	int pushCnt = 0; // 강연을 큐에 넣은 횟수
	int income = 0; // 수입

	//	50 2
	//	20 1
	//	40 2
	//	60 3
	//	30 3
	//	30 1
	// maxD = 3
	for (int i = 0; i < n; i++)
	{
		cin >> m >> d;

		lectureSort.push_back(LectureSort(m, d));

		if (maxD < d)
		{
			maxD = d;
		}
	}

	// 60 3
	// 30 3
	// 50 2
	// 40 2
	// 20 1
	// 30 1
	sort(lectureSort.begin(), lectureSort.end());

	
	for (int i = maxD; i > 0; i--) // 세번째 날에 할수있는 강의 -> 두번째 날에 할수있는 강의 -> 첫 날에 할수있는 강의
	{
		for (int j = pushCnt; j < n; j++) // 강의 중에
		{
			if (lectureSort[j].d < i) // 현재 날짜보다 작다면 강의할수없음
			{
				break;
			}

			// 큐에 추가
			schedule.push(lectureSort[j].m);
			pushCnt++;
		}

		// 스텝1 : maxHeap에 60, 30이 저장되고 최대값 추출 -> 수입이 60 생기고 큐에 30 남음
		// 스텝2 : maxHeap에 50, 40이 저장되고 최대값 추출 -> 수입이 50 생기고 큐에 40 30 남음
		// 스텝3 : maxHeap에 20, 30이 저장되고 최대값 추출 -> 수입이 40 생기고 큐에 30 20 남음
		if (!schedule.empty()) // maxHeap에 요소가 있다면 강연하기
		{
			income += schedule.top();
			schedule.pop();
		}
	}

	cout << income << '\n';

	return 0;
}
// 핵심
// 구조체를 이용한 정렬
// 기한이 많이 남은 가의 순으로 정렬
// 마지막 날 강연부터 첫 날 강연 순으로 스케쥴링