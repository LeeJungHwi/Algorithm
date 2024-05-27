#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <fstream>
using namespace std;

// Cache Control
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m;
	cin >> n >> m;

	map<int, int> cache;
	map<int, int> idMap;

	int num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;

		//bool isCache = false;
		int order = 0;

		// 캐시에 있는지 체크
		if (idMap[num] > 0) order = idMap[num];

		// 캐시에 있는 경우 => 기존 키 삭제하고 (순서, 숫자) 맵핑
		if (order > 0) cache.erase(order);

		// 캐시에 없는 경우

		// 캐시가 가득 찬 경우 맵 첫키 삭제하고 (순서, 숫자) 맵핑
		if (cache.size() == m) cache.erase(cache.begin());

		// 캐시가 가득 차지 않은 경우 (순서, 숫자) 맵핑
		idMap[num] = i + 1;
		cache[i + 1] = num;
	}

	for (auto it = cache.rbegin(); it != cache.rend(); it++) cout << it->second << '\n';

	return 0;
}