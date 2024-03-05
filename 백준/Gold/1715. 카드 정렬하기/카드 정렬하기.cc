#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 최소힙
struct Num
{
	int number; // 숫자

	// 생성자 
	Num() {}
	Num(int n) : number(n) {}

	// 최소힙
	bool operator<(const Num &num)const
	{
		return number > num.number;
	}
};

// 카드 정렬하기
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 3
	cin >> n;

	int num; // 숫자

	// 최소힙에 전부 저장
	// 두개숫자합을 compareCnt에 누적하고
	// 큐가 비었으면 break
	// 큐가 비지않았으면 두개숫자합을 큐에 저장

	priority_queue<Num> minHeap;

	//	10
	//	20
	//	40
	// 최소힙에 전부 저장
	for (int i = 0; i < n; i++)
	{
		cin >> num;

		minHeap.push(Num(num));
	}

	// n == 1이면 최소비교횟수 0 출력
	if (n == 1)
	{
		cout << 0 << '\n';

		return 0;
	}

	// 1 1 1 1
	// 2 1 1 compareCnt 2
	// 2 2 compareCnt 4
	// 4 compareCnt 8

	// 10 20 40
	// 30 40 compareCnt 30
	// 70 compareCnt 100

	// 50 60 70 80
	// 110 70 80 compareCnt 110
	// 110 150 compareCnt 260
	// 260 compareCnt 520

	// 두개숫자합을 compareCnt에 누적하고
	// 큐가 비었으면 break
	// 큐가 비지않았으면 두개숫자합을 큐에 저장

	long long compareCnt = 0;

	while (true)
	{
		int twoSum = 0; // 두개숫자합

		for (int i = 0; i < 2; i++)
		{
			if (!minHeap.empty())
			{
				twoSum += minHeap.top().number;
				minHeap.pop();
			}
		}

		compareCnt += twoSum;

		if (minHeap.empty())
		{
			break;
		}

		minHeap.push(twoSum);
	}

	cout << compareCnt << '\n';

	return 0;
}