#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 차집합
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M 4, 3
	cin >> n >> m;

	// A에 속하면서 B에 속하지않는 요소 구하기

	// A를 맵핑하고 B도 맵핑함
	// A맵 돌면서 B에 맵핑되지않은것만 카운팅하고 요소 저장

	map<int, int> A;
	map<int, int> B;
	vector<int> resultNum; // A에 속하면서 B에 속하지않는 요소
	int num; // 숫자
	int cnt = 0; // A에 속하면서 B에 속하지않는 요소 개수

	for (int i = 0; i < n; i++) // A 맵핑
	{
		cin >> num;

		A[num]++;
	}

	for (int i = 0; i < m; i++) // B 맵핑
	{
		cin >> num;

		B[num]++;
	}

	for (auto it = A.begin(); it != A.end(); it++) // A맵 돌면서 B에 맵핑되지않은것만 카운팅하고 요소 저장
	{
		if (B[it->first] == 0)
		{
			cnt++;
			resultNum.push_back(it->first);
		}
	}

	// 요소 개수와 요소 출력
	cout << cnt << '\n';

	for (int i = 0; i < resultNum.size(); i++)
	{
		cout << resultNum[i] << ' ';
	}

	return 0;
}