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

// 가운데를 말해요 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 7
	cin >> n;

	int num; // 숫자

	priority_queue<int> maxHeap; // 중간값보다 작거나같은값을 저장
	priority_queue<Num> minHeap; // 중간값보다 큰값을 저장

	for (int i = 0; i < n; i++)
	{
		//	1
		//	5
		//	2
		//	10
		//	- 99
		//	7
		//	5
		cin >> num;

		// 두개힙 중 하나에 먼저 저장
		if (maxHeap.empty() || num <= maxHeap.top())
		{
			maxHeap.push(num);
		}
		else
		{
			minHeap.push(Num(num));
		}

		// 두개힙 크기 밸런싱
		if (maxHeap.size() > minHeap.size() + 1)
		{
			minHeap.push(Num(maxHeap.top()));
			maxHeap.pop();
		}
		else if (minHeap.size() > maxHeap.size())
		{
			maxHeap.push(minHeap.top().number);
			minHeap.pop();
		}

		// 중간값 출력
		if (maxHeap.size() == minHeap.size())
		{
			cout << min(maxHeap.top(), minHeap.top().number) << '\n';
		}
		else
		{
			cout << maxHeap.top() << '\n';
		}
	}

	return 0;
}
