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

// N번째 큰 수
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 5
	cin >> n;

	// 최소힙에 저장
	// 힙 크기가 n을 초과하면 pop
	// top 출력

	int num; // 숫자
	priority_queue<Num> minHeap;

	//	12 7 9 15 5
	//	13 8 11 19 6
	//	21 10 26 31 16
	//	48 14 28 35 25
	//	52 20 32 41 49
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> num;

			minHeap.push(num);

			if (minHeap.size() > n)
			{
				minHeap.pop();
			}
		}
	}

	cout << minHeap.top().number << '\n';

	return 0;
}