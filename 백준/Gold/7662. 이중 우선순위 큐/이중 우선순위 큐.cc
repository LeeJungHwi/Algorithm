#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 이중 우선순위 큐
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 저장 -> 그냥저장
	// 삭제 -> 두가지
	// 1.우선순위가 가장 높은값
	// 2.우선순위가 가장 낮은값
	// Input
	// I -> 저장
	// D 1 -> 최댓값 삭제
	// D -1 -> 최솟값 삭제
	// 맵이 비었으면 삭제연산은 무시함
	// -2^31 ~ 2^31 -> long long 해야할듯?

	int tc; // TC 2
	cin >> tc;
	
	int opCnt; // 연산수 7
	char op; // 연산 I or D
	long long number; // 숫자 16

	// TC 수만큼
	while (tc--)
	{
		cin >> opCnt;

		map<long long, long long> m; // (숫자, 개수) 맵핑

		// 연산수만큼
		for (int i = 0; i < opCnt; i++)
		{
			cin >> op;

			// 맵핑
			if (op == 'I')
			{
				cin >> number;

				m[number]++;

				continue;
			}

			// 최솟값이면 맵 첫요소--
			// 최댓값이면 맵 막요소--

			cin >> number;

			if (number == -1)
			{
				if(!m.empty()) m.begin()->second--;
				else continue;
				if (m.begin()->second == 0) m.erase(m.begin());
				continue;
			}

			if (!m.empty())
			{
				auto it = m.end();
				it--;
				it->second--;
				if (it->second == 0) m.erase(it);
			}
		}

		if (m.empty())
		{
			cout << "EMPTY" << '\n';

			continue;
		}

		auto it = m.end();
		it--;

		cout << it->first << ' ' << m.begin()->first << '\n';
	}

	return 0;
}

//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <string>
//#include <map>
//#include <fstream>
//using namespace std;
//
//// 최소힙
//struct Num
//{
//	long long num;
//
//	// 생성자
//	Num() {}
//	Num(long long n) : num(n) {}
//
//	// 최소힙
//	bool operator<(const Num &other) const
//	{
//		return num > other.num;
//	}
//};

//// 이중 우선순위 큐
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	//ifstream cin;
//	//cin.open("input.txt");
//
//	// 저장 -> 그냥저장
//	// 삭제 -> 두가지 우선순위큐
//	// 1.우선순위가 가장 높은값
//	// 2.우선순위가 가장 낮은값
//	// Input
//	// I -> 저장
//	// D 1 -> 최댓값 삭제
//	// D -1 -> 최솟값 삭제
//	// 큐가 비었으면 삭제연산은 무시함
//	// -2^31 ~ 2^31 -> long long 해야할듯?
//
//	priority_queue<long long> maxHeap; // 최대힙
//	priority_queue<Num> minHeap; // 최소힙
//
//	int tc; // TC 2
//	cin >> tc;
//
//	int opCnt; // 연산수 7
//	char op; // 연산 I or D
//	long long number; // 숫자 16
//	int qFlag = 1; // 1(최소) 2(최대)
//
//	// TC 수만큼
//	while (tc--)
//	{
//		cin >> opCnt;
//
//		// 연산수만큼
//		for (int i = 0; i < opCnt; i++)
//		{
//			cin >> op;
//
//			// 이전에 연산했던 우선순위큐에 저장
//			if (op == 'I')
//			{
//				cin >> number;
//
//				if (qFlag == 1)
//				{
//					minHeap.push(Num(number));
//
//					continue;
//				}
//
//				maxHeap.push(number);
//
//				continue;
//			}
//
//			// 최솟값이면 최소힙으로 옮겨서 pop
//			// 최댓값이면 최대힙으로 옮겨서 pop
//
//			cin >> number;
//
//			if (number == -1)
//			{
//				while (!maxHeap.empty())
//				{
//					minHeap.push(Num(maxHeap.top()));
//					maxHeap.pop();
//				}
//
//				if (!minHeap.empty()) minHeap.pop();
//
//				qFlag = 1;
//
//				continue;
//			}
//
//			while (!minHeap.empty())
//			{
//				maxHeap.push(minHeap.top().num);
//				minHeap.pop();
//			}
//
//			if (!maxHeap.empty()) maxHeap.pop();
//
//			qFlag = 2;
//		}
//
//		// 마지막에 최소힙을 사용했으면
//		if (qFlag == 1)
//		{
//			// 최소힙이 비었으면
//			if (minHeap.empty())
//			{
//				cout << "EMPTY" << '\n';
//
//				continue;
//			}
//
//			// 비어있지않으면
//			long long minVal = minHeap.top().num;
//
//			while (!minHeap.empty())
//			{
//				maxHeap.push(minHeap.top().num);
//				minHeap.pop();
//			}
//
//			cout << maxHeap.top() << ' ' << minVal << '\n';
//
//			continue;
//		}
//
//		// 마지막에 최대힙을 사용했으면
//		// 최대힙이 비었으면
//		if (maxHeap.empty())
//		{
//			cout << "EMPTY" << '\n';
//
//			continue;
//		}
//
//		// 비어있지않으면
//		long long maxVal = maxHeap.top();
//
//		while (!maxHeap.empty())
//		{
//			minHeap.push(Num(maxHeap.top()));
//			maxHeap.pop();
//		}
//
//		cout << maxVal << ' ' << minHeap.top().num << '\n';
//	}
//
//	return 0;
//}