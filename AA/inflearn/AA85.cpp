#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int n; // N 3
int maxValue = -1000000000; // 최댓값
int minValue = 1000000000; // 최솟값
vector<int> sequences; // 수열
vector<int> op; // 연산자

// DFS
void DFS(int i, int curVal)
{
	if (i == n) // 종료조건 : n일때 종료
	{
		if (curVal > maxValue) // 최대값 갱신
		{
			maxValue = curVal;
		}

		if (curVal < minValue) // 최소값 갱신
		{
			minValue = curVal;
		}
	}
	else
	{
		if (op[0] > 0) // 더하기 개수가 남았을때
		{
			op[0]--; // 더하기 한다
			DFS(i + 1, curVal + sequences[i]);
			op[0]++; // 더하기 안 한다
		}
		if (op[1] > 0) // 빼기 개수가 남았을때
		{
			op[1]--; // 빼기 한다
			DFS(i + 1, curVal - sequences[i]);
			op[1]++; // 빼기 안 한다
		}
		if (op[2] > 0) // 곱하기 개수가 남았을때
		{
			op[2]--; // 곱하기 한다
			DFS(i + 1, curVal * sequences[i]);
			op[2]++; // 곱하기 안 한다
		}
		if (op[3] > 0) // 나누기 개수가 남았을때
		{
			op[3]--; // 나누기 한다
			DFS(i + 1, curVal / sequences[i]);
			op[3]++; // 나누기 안 한다
		}
	}
}

// 수식만들기
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n;

	int num; // 숫자

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		sequences.push_back(num); // 5 3 8
	}

	for (int i = 0; i < 4; i++)
	{
		cin >> num;
		op.push_back(num); // 1 0 1 0
	}

	DFS(1, sequences[0]);

	cout << maxValue << '\n' << minValue << '\n';

	return 0;
}