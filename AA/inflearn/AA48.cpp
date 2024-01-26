#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;

// 각 행의 평균과 가장 가까운 값
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	vector<vector<float> > mat(9, vector<float>(9)); // 9by9에 자연수 저장

	for (int i = 0; i < 9; i++)
	{
		float columnSum = 0; // 각 행의 합
		float columnAvg = 0; // 각 행의 합의 평균
		float gapMin = 100; // 차이 최소값
		float closeElement = 0; // 평균과 가장 가까운 수

		for (int j = 0; j < 9; j++)
		{
			cin >> mat[i][j];
			columnSum += mat[i][j]; // 각 행의 합
		}

		columnAvg = round(floor((columnSum / 9.0f) * 10) / 10); // 각 행의 합의 평균

		for (int j = 0; j < 9; j++) // 차이 최소값 및 평균과 가장 가까운 수 갱신
		{
			if (abs(columnAvg - mat[i][j]) < gapMin)
			{
				gapMin = abs(columnAvg - mat[i][j]);
				closeElement = mat[i][j];
			}
			else if (abs(columnAvg - mat[i][j]) == gapMin) // 차이 최소값이 같으면 큰 수가 답
			{
				if (closeElement < mat[i][j])
				{
					closeElement = mat[i][j];
				}
			}
		}

		cout << columnAvg << ' ' << closeElement << '\n';
	}

	return 0;
}

// 핵심
// round -> 소수점 첫 째 자리에서 반올림
// floor -> 내림
// ceil -> 올림
// 반올림 하려는 자릿수 까지 10의 거듭제곱을 곱하고 floor 해준 뒤 10의 거듭제곱을 곱한만큼 나눠주고 round