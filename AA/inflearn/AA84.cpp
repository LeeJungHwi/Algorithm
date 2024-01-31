#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<pair<int, int> > consulting; // T, P �� ����
int n; // N 7
int maxPay; // �ִ� �޿�

void GetMaxPay(int i, int sumPay)
{
	if (i == n) // �������� : n�� �϶� ����
	{
		if (sumPay > maxPay)
		{
			maxPay = sumPay;
		}
	}
	else
	{
		if (i + consulting[i].first < n + 1) // ��㳯¥�� �������� �ް��������� ����
		{
			GetMaxPay(i + consulting[i].first, sumPay + consulting[i].second); // ����� �Ѵ�
		}

		GetMaxPay(i + 1, sumPay); // ����� �� �Ѵ�
	}
}

// �ް�
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n;

	int t, p; // T, P

	//  T P
	//	4 20
	//	2 10
	//	3 15
	//	3 20
	//	2 30
	//	2 20
	//	1 10
	for (int i = 0; i < n; i++)
	{
		cin >> t >> p;
		consulting.push_back({ t, p });
	}

	// �����층
	// �������� : n�� �϶� ����
	// ����� �Ѵ� ���Ѵٷ� ����
	GetMaxPay(0, 0);

	cout << maxPay << '\n';

	return 0;
}