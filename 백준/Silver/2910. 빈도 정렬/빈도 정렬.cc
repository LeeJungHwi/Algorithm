#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <tuple>
#include <fstream>
using namespace std;

// 정렬 기준
// 1.빈도수가 다르면 빈도수 내림차순
// 2.빈도수가 같으면 입력순 오름차순
bool comp(const pair<int, pair<int, int> > &p1, const pair<int, pair<int, int> > &p2)
{
	if (p1.second.second != p2.second.second)
	{
		return p1.second.second > p2.second.second;
	}

	return p1.second.first < p2.second.first;
}

// 빈도 정렬
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, c; // N, C 5, 2
	cin >> n >> c;

	vector<pair<int, pair<int, int> > > numVec; // 숫자들 저장
	int num; // 숫자
	int order = 1; // 입력순서
	map<int, pair<int, int> > numMap; // (숫자, (입력순서, 빈도수)) 맵핑

	// (숫자, (입력순서, 빈도수)) 맵핑
	for (int i = 0; i < n; i++)
	{
		cin >> num;

		if (numMap[num].second == 0) // 처음 나온 숫자면 입력순서 저장
		{
			numMap[num].first = order++;
		}

		numMap[num].second++;
	}

	// 맵 돌면서 숫자들 저장
	for (auto it = numMap.begin(); it != numMap.end(); it++)
	{
		numVec.push_back({ it->first, { it->second.first, it->second.second } });
	}

	// 정렬 후 출력
	sort(numVec.begin(), numVec.end(), comp);

	for (int i = 0; i < numVec.size(); i++)
	{
		for (int j = 0; j < numVec[i].second.second; j++)
		{
			cout << numVec[i].first << ' ';
		}
	}

	return 0;
}