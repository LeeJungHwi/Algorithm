#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int n; // N 3
int maxValue = -1000000000; // �ִ�
int minValue = 1000000000; // �ּڰ�
vector<int> sequences; // ����
vector<int> op; // ������

// DFS
void DFS(int i, int curVal)
{
	if (i == n) // �������� : n�϶� ����
	{
		if (curVal > maxValue) // �ִ밪 ����
		{
			maxValue = curVal;
		}

		if (curVal < minValue) // �ּҰ� ����
		{
			minValue = curVal;
		}
	}
	else
	{
		if (op[0] > 0) // ���ϱ� ������ ��������
		{
			op[0]--; // ���ϱ� �Ѵ�
			DFS(i + 1, curVal + sequences[i]);
			op[0]++; // ���ϱ� �� �Ѵ�
		}
		if (op[1] > 0) // ���� ������ ��������
		{
			op[1]--; // ���� �Ѵ�
			DFS(i + 1, curVal - sequences[i]);
			op[1]++; // ���� �� �Ѵ�
		}
		if (op[2] > 0) // ���ϱ� ������ ��������
		{
			op[2]--; // ���ϱ� �Ѵ�
			DFS(i + 1, curVal * sequences[i]);
			op[2]++; // ���ϱ� �� �Ѵ�
		}
		if (op[3] > 0) // ������ ������ ��������
		{
			op[3]--; // ������ �Ѵ�
			DFS(i + 1, curVal / sequences[i]);
			op[3]++; // ������ �� �Ѵ�
		}
	}
}

// ���ĸ����
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n;

	int num; // ����

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