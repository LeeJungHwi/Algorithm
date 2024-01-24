#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

// ������(��������)
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M
	vector<bool> firstVec(21000000); // ù ���տ��� ���� �� üũ
	vector<int> crossVec; // ù ������ ��ҿ� �����ؼ� true�� ������ ���Ϳ� ����

	cin >> n;

	int num; // ����

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		firstVec[num] = true; // ù ���տ��� ���� �� üũ 2 7 10 5 3
	}

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> num; // 3 10 5 17 12
		if (firstVec[num])
		{
			crossVec.push_back(num); // 3 10 5
		}
	}

	sort(crossVec.begin(), crossVec.end());

	for (int i = 0; i < crossVec.size(); i++)
	{
		cout << crossVec[i] << ' ';
	}

	return 0;
}
// �ٽ�
// �˰��� ��� sort �Լ�
// ���Ҵ� int�� ���� ũ�� ����