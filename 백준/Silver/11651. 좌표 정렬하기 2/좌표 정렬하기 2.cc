#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 정렬기준
// y가 다르면 y 오름차순
// y가 같으면 x 오름차순
bool comp(const pair<int, int> &pos1, const pair<int, int> &pos2)
{
	if (pos1.second != pos2.second)
	{
		return pos1.second < pos2.second;
	}

	return pos1.first < pos2.first;
}

// 좌표 정렬하기 2
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 5
	cin >> n;

	vector<pair<int, int> > posVec; // 좌표들 저장
	pair<int, int> pos; // 좌표

	for (int i = 0; i < n; i++)
	{
		cin >> pos.first >> pos.second;

		posVec.push_back(pos); // 3 4, 1 1, 1 -1, 2 2, 3 3
	}

	// 정렬 후 출력
	sort(posVec.begin(), posVec.end(), comp);

	for (int i = 0; i < posVec.size(); i++)
	{
		cout << posVec[i].first << ' ' << posVec[i].second << '\n';
	}

	return 0;
}