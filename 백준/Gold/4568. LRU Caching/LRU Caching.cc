#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// LRU Caching
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt"); 

	// LRU 캐시 구현

	// 데이터 돌면서
	// 맵핑된 문자가 아니면
	// 캐시가 가득 찼으면 맵 첫키 삭제하고 (들어온순서, 들어온문자) 맵핑
	// 캐시가 가득차지않았으면 (들어온순서, 들어온문자) 맵핑
	// 맵핑된 문자면
	// 기존에 맵핑된 키 삭제하고 (들어온순서, 들어온문자) 맵핑

	int cacheSize; // 캐시 크기 5
	string data; // 데이터 ABC!DEAF!B!
	int curSimul = 1; // 현재 시뮬레이션

	while (true)
	{
		cin >> cacheSize;

		// 캐시크기가 0이면 종료
		if (cacheSize == 0)
		{
			break;
		}

		map<int, char> cache; // (들어온순서, 들어온문자) 맵핑

		// Simulation 1
		cout << "Simulation " << curSimul++ << '\n';

		cin >> data;

		// 데이터 돌면서
		for (int i = 0; i < data.size(); i++)
		{
			// !를 만나면 캐시내부 출력하고 개행
			if (data[i] == '!')
			{
				for (auto it = cache.begin(); it != cache.end(); it++)
				{
					cout << it->second;
				}

				cout << '\n';
				continue;
			}

			bool isCache = false; // 맵핑된 문자인지 체크
			int order = 0; // 맵핑된 키

			// 맵핑된 문자면 체크
			for (auto it = cache.begin(); it != cache.end(); it++)
			{
				if (it->second == data[i])
				{
					isCache = true;
					order = it->first;

					break;
				}
			}

			// 맵핑된 문자면
			if (isCache)
			{
				// 기존에 맵핑된 키 삭제하고 (들어온순서, 들어온문자) 맵핑
				cache.erase(order);
				cache[i + 1] = data[i];
				continue;
			}

			// 맵핑된 문자가 아니면

			// 캐시가 가득 찼으면 맵 첫키 삭제하고 (들어온순서, 들어온문자) 맵핑
			if (cache.size() == cacheSize)
			{
				cache.erase(cache.begin());
				cache[i + 1] = data[i];

				continue;
			}

			// 캐시가 가득차지않았으면 (들어온순서, 들어온문자) 맵핑
			cache[i + 1] = data[i];
		}
	}

	return 0;
}