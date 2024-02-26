#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <fstream>
using namespace std;

// 옥상 정원 꾸미기
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 빌딩관리인들은 다른빌딩의 옥상정원을 벤치마킹하고싶음
	// i번째 빌딩의 크기가 hi이고 모든 빌딩은 일렬로 서있고 오른쪽으로만 볼수있음
	// i번째 빌딩관리인이 볼수있는 다른 빌딩의 옥상정원은 i+1, i+2, ..., N
	// 그러나 자신의빌딩보다 높거나같은 빌딩이 있으면 그 다음에있는 모든 빌딩의 옥상은 못봄

	// 관리인들이 확인할수있는 빌딩 층수의 총 합 구하기

	int n; // N 6
	cin >> n;

	vector<int> heights(n); // 각 빌딩 높이 저장

	// 10 3 7 4 12 2
	for (int i = 0; i < n; i++)
	{
		cin >> heights[i];
	}

	stack<int> s;
	long long buildingCnt = 0; // 벤치마킹할수있는 빌딩 수

	for (int i = 0; i < n; i++)
	{
		// 볼수없는건물 pop
		while (!s.empty() && heights[s.top()] <= heights[i])
		{
			s.pop();
		}

		// 스택에 남아있는 건물은 볼수있음
		buildingCnt += s.size();

		// 현재빌딩 인덱스 저장
		s.push(i);
	}

	cout << buildingCnt << endl;

	return 0;
}
