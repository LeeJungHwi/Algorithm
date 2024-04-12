#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 랜선 자르기
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int k, n; // K, N 4, 11
	cin >> k >> n;

	// 랜선길이 802 743 347 539
	vector<long long> wires(k);

	for (int i = 0; i < k; i++)
	{
		cin >> wires[i];
	}

	sort(wires.begin(), wires.end());

	// 이진탐색

	long long first = 1; // 처음
	long long last = wires.back(); // 마지막
	long long maxLen = 0; // 최대길이

	while (first <= last) // 역전되면 종료
	{
		long long standard = (first + last) / 2; // 기준값

		bool isLen = false; // 기준값 길이의 랜선을 잘라서 n개를 만들수있는지 체크

		long long cnt = 0; // 잘려진 랜선 개수

		// 각 랜선길이 돌면서 잘려진 랜선 개수 체크
		for (int i = 0; i < wires.size(); i++)
		{
			cnt += wires[i] / standard;
		}

		// 잘려진 랜선 개수가 n개 이상이면 가능한 랜선길이
		if (cnt >= n)
		{
			isLen = true;
		}

		// 가능한 랜선길이면
		if (isLen)
		{
			maxLen = standard; // 최대길이 갱신
			first = standard + 1; // 처음 갱신
		}
		else // 불가능한 랜선길이면
		{
			last = standard - 1; // 마지막 갱신
		}
	}

	cout << maxLen << '\n';

	return 0;
}

//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <string>
//#include <map>
//#include <fstream>
//using namespace std;
//
//// 랜선 자르기
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	ifstream cin;
//	cin.open("input.txt");
//
//	int k, n; // K, N 4, 11
//	cin >> k >> n;
//
//	// 1.k 개의 랜선을 입력받고 랜선 길이중 최대값 구해놓기
//	// 2.first(0) last(랜선 길이중 최대값) 이진탐색
//	// 2-1.같으면 최대길이 갱신
//	// 2-2.크면 처음 갱신
//	// 2-3.작으면 마지막 갱신
//
//	// 1.k 개의 랜선을 입력받고 랜선 길이중 최대값 구해놓기
//	vector<long long> lan(k); // 랜선 저장 802 743 457 539
//	long long maxLan = 0; // 랜선 길이중 최대길이
//
//	for (int i = 0; i < k; i++)
//	{
//		cin >> lan[i];
//
//		maxLan = max(maxLan, lan[i]);
//	}
//
//	// 필요한 랜선이 1개면 랜선중 최대길이 출력 후 종료
//	if (n == 1)
//	{
//		cout << maxLan << '\n';
//
//		return 0;
//	}
//
//	// 2.first(0) last(랜선 길이중 최대값) 이진탐색
//	// 2-1.같으면 최대길이 갱신
//	// 2-2.크면 처음 갱신
//	// 2-3.작으면 마지막 갱신
//	long long first = 1;
//	long long last = maxLan;
//	long long maxLen = 0; // 랜선 최대길이
//
//	while (first <= last) // 역전되면 종료
//	{
//		int standard = (first + last) / 2; // 기준값
//
//		// 기준값으로 잘랐을때 만들 수 있는 랜선의 수 구하기
//		long long lanCnt = 0;
//
//		for (int i = 0; i < k; i++)
//		{
//			lanCnt += lan[i] / standard;
//		}
//
//		if (n == lanCnt) // 같으면 standard부터 last까지 돌면서 최대길이 갱신
//		{
//			for (int i = standard; i < last + 1; i++)
//			{
//				// 기준값으로 잘랐을때 만들 수 있는 랜선의 수 구하기
//				long long cnt = 0;
//
//				for (int j = 0; j < k; j++)
//				{
//					cnt += lan[j] / i;
//				}
//
//				// 개수가 같으면 최대길이 갱신하고 continue
//				if (cnt == n)
//				{
//					maxLen = i;
//
//					continue;
//				}
//
//				// 개수가 다르면 더이상 볼필요없어서 break
//				break;
//			}
//
//			// 구했으니 break
//			break;
//		}
//		else if (n < lanCnt) // 크면 처음갱신
//		{
//			first = standard + 1;
//		}
//		else if (n > lanCnt) // 작으면 마지막갱신
//		{
//			last = standard - 1;
//		}
//	}
//
//	cout << maxLen << '\n';
//
//	return 0;
//}