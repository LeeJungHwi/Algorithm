#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <fstream>
using namespace std;

// 오아시스 재결합
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// N명이 한줄로 서서 기다리는데 자기가 볼수있는 사람 수가 궁금함
	// A와B가 서로볼수있으려면 둘사이에 둘보다큰사람이 없어야함
	// 줄에서있는 사람의 키가 주어졌을때 서로 볼수있는 쌍의 수 구하기

	int n; // N 7
	cin >> n;

	stack<pair<int, int>> heights; // (사람키, 해당키 수) 쌍 저장
	long long pairCnt = 0; // 서로 볼수있는 쌍의 수
	int height; // 사람키 2 4 1 2 2 5 1

	// (2,1) push
	// pairCnt 1, (2, 1) pop, (4, 1) push
	// pairCnt 2, (1, 1) push
	// pairCnt 3, (1, 1) pop, pairCnt 4, (2, 1) push
	// pairCnt 5, heightCnt 2, (2, 1) pop, pairCnt 6, (2, 2) push
	// pairCnt 8, (2, 2) pop, pairCnt 9, (4, 1) pop, (5, 1) push
	// pairCnt 10, (1, 1) push

	for (int i = 0; i < n; i++)
	{
		cin >> height;

		int heightCnt = 1; // 현재키 수

		// 현재키가 더큰사람 처리
		// 현재키가 스택탑보다 크면
		// 현재키는 스택탑이 볼수있는 사람
		while (!heights.empty() && heights.top().first < height)
		{
			pairCnt += heights.top().second;
			heights.pop();
		}

		// 키가 같은사람 처리
		// 현재키와 스택탑이 같으면
		// 현재키는 스택탑을 볼수있는 사람들을 볼수있음
		if (!heights.empty() && heights.top().first == height)
		{
			pairCnt += heights.top().second;
			heightCnt += heights.top().second;
			heights.pop();
		}

		// 스택에 요소가 있다면
		// 스택에 있는 키들은 현재키보다 작음
		// 현재키가 스택에 있는 키들을 모두 볼수있음

		// 스택에 있는 키의 수만큼 쌍 형성
		// 예를들어 스택에 3명이 남아있으면
		// 현재키는 스택 3명과 각각 볼수있으므로 총 3개 쌍 형성
		// pairCnt를 1증가시키면 스택 3명과의 모든쌍을 하나씩 카운팅하는것
		if (!heights.empty())
		{
			pairCnt++;
		}

		// (현재키, 현재키 수) 쌍 push
		heights.push({ height, heightCnt });
	}

	// 서로 볼수있는 쌍 수 출력
	cout << pairCnt << '\n';

	return 0;
}
