#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

// 교집합(투포인터)
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M
	vector<bool> firstVec(21000000); // 첫 집합에서 나온 수 체크
	vector<int> crossVec; // 첫 집합의 요소에 접근해서 true면 교집합 벡터에 저장

	cin >> n;

	int num; // 숫자

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		firstVec[num] = true; // 첫 집합에서 나온 수 체크 2 7 10 5 3
	}

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> num; // 3 10 5 17 12
		if (firstVec[num])
		{
			crossVec.push_back(num); // 3 10 5
		}
	}

	sort(crossVec.begin(), crossVec.end());

	for (int i = 0; i < crossVec.size(); i++)
	{
		cout << crossVec[i] << ' ';
	}

	return 0;
}
// 핵심
// 알고리즘 헤더 sort 함수
// 원소는 int형 변수 크기 범위