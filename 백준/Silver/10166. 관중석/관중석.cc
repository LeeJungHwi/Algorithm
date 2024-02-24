#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// 관중석
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	double d1, d2; // D1, D2 3, 6
	cin >> d1 >> d2;

	vector<double> useDegree; // 사용중인 각도 저장

	// 360도라고 했을때
	// 3 : 0도 120도 240도
	// 4 : 0도 90도 180도 270도
	// 5 : 0도 72도 144도 216도 288도
	// 6 : 0도 60도 120도 180도 240도 300도
	// 0 120 240 90 180 270 72 144 216 288 60 300 -> 12

	// 0도 자리 하나는 무조건 사용함
	int seatCnt = 1;
	useDegree.push_back(0);

	// 각 반지름으로 그린 원의 좌석배치에 따라 좌석사용여부 결정
	for (double i = d1; i < d2 + 1; i++)
	{
		// 처음 각도 초기화
		double degree = 360 / i;

		while (true)
		{
			// 만약 더한게 360 이상이면 종료
			if (degree >= 360)
			{
				break;
			}

			// 사용할수없는 좌석인지 체크
			bool isNotUse = false;

			// 이미 같은각도 자리가 앞에있어서 가려졌으면 사용할수없음, 각도만 더해줌
			for (int j = 0; j < useDegree.size(); j++)
			{
				if (useDegree[j] == degree)
				{
					degree += 360 / i;
					isNotUse = true;
					break;
				}
			}

			// 사용할수없는 자리면 continue
			if (isNotUse)
			{
				continue;
			}

			// 아니면 좌석으로 사용하고 각도 더해줌
			seatCnt++;
			useDegree.push_back(degree);
			degree += 360 / i;
		}
	}

	cout << seatCnt << '\n';

	return 0;
}