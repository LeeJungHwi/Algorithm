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
	long long number; // 숫자

	// 생성자 
	Num() {}
	Num(long long n) : number(n) {}

	// 최소힙
	bool operator<(const Num &num)const
	{
		return number > num.number;
	}
};

// 파일합치기 3
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int t; // T 2
	cin >> t;

	// 최소힙에 전부 저장
	// 두개숫자합을 compareCnt에 누적하고
	// 큐가 비었으면 break
	// 큐가 비지않았으면 두개숫자합을 큐에 저장
	while (t--)
	{
		int k; // K 4
		cin >> k;

		int num; // 숫자
		priority_queue<Num> minHeap;

		// 40 30 30 50
		// 최소힙에 전부 저장
		for (int i = 0; i < k; i++)
		{
			cin >> num;

			minHeap.push(Num(num));
		}

		// k == 1이면 최소비교횟수 0 출력
		if (k == 1)
		{
			cout << 0 << '\n';

			continue;
		}

		// 두개숫자합을 compareCnt에 누적하고
		// 큐가 비었으면 break
		// 큐가 비지않았으면 두개숫자합을 큐에 저장

		long long compareCnt = 0;

		while (true)
		{
			long long twoSum = 0; // 두개숫자합

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
	}

	return 0;
}