#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// ��Ƽ�½�ŷ
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 3
	cin >> n;

	queue<pair<int, int> > processes; // �۾� ����

	int processTime; // �۾��ð�

	for (int i = 1; i < n + 1; i++)
	{
		cin >> processTime; // 1 2 3

		processes.push({ i, processTime }); // (i��°�۾�, �۾��ð�) -> (1, 1) (2, 2) (3, 3)
	}

	int k; // K 5
	cin >> k;

	// �۾� ó��
	while (k > 0 && !processes.empty())
	{
		// ���� �����ؾ� �� �۾� ����
		pair<int, int> curProcess = processes.front();
		processes.pop();

		// ���� �۾��� �۾��ð� ����
		curProcess.second -= 1;

		// k ����
		k--;

		// ���� �۾��ð��� 0�̸� ť�� �����ʰ� continue
		if (curProcess.second == 0)
		{
			continue;
		}

		// �۾��ð��� ���Ҵٸ� �ٽ� ť�� push
		processes.push(curProcess);
	}

	// ť�� ������� �� �̻� ó���� �۾��� ����
	if (processes.empty())
	{
		cout << -1 << '\n';

		return 0;
	}

	cout << processes.front().first << '\n';

	return 0;
}