#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 숫자 카드
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 10
	cin >> n;

	vector<int> haveCard(n); // 상근이가 가지고 있는 카드

	for (int i = 0; i < n; i++)
	{
		cin >> haveCard[i]; // 6 3 2 10 10 10 -10 -10 7 3
	}

	sort(haveCard.begin(), haveCard.end()); // -10 -10 2 3 3 6 7 10 10 10

	int m; // M 8
	cin >> m;

	int findCard; // 찾을 카드 10 9 -5 2 3 4 5 -10

	map<int, int> haveCnt; // (숫자, 횟수) 맵핑

	for (int i = 0; i < m; i++)
	{
		cin >> findCard;

		int first = 0; // 처음
		int last = n - 1; // 마지막
		int findCnt = 0; // 찾은횟수

		while (first <= last) // 역전되면 종료
		{
			int standard = (first + last) / 2; // 기준값

			if (haveCard[standard] == findCard) // 같으면
			{
				if (haveCnt[findCard] > 0) // 이전에 구한적이 있으면 재사용
				{
					findCnt = haveCnt[findCard];

					break;
				}

				for (int i = standard; i > -1; i--) // 기준값부터 왼쪽을 보면서 찾은횟수 카운팅
				{
					if (haveCard[i] < findCard) // 찾고자 하는 카드 숫자보다 작으면 종료
					{
						break;
					}

					findCnt++;
				}

				for (int i = standard; i < n; i++) // 기준값부터 오른쪽을 보면서 찾은횟수 카운팅
				{
					if (haveCard[i] > findCard) // 찾고자 하는 카드 숫자보다 크면 종료
					{
						break;
					}

					findCnt++;
				}

				haveCnt[findCard] = findCnt; // 처음 구한거면 메모

				break;
			}
			else if (haveCard[standard] < findCard) // 크면
			{
				first = standard + 1; // 처음 갱신
			}
			else if (haveCard[standard] > findCard) // 작으면
			{
				last = standard - 1; // 마지막 갱신
			}
		}

		// 찾은횟수가 카운팅되지않았으면 0 출력
		// 찾은횟수가 카운팅되었으면 기준값을 두 번 카운팅하므로 1빼줌 
		cout << (findCnt == 0 ? 0 : findCnt - 1) << ' ';
	}

	return 0;
}