#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


// �κ����� ����Լ�
void PrintSet(int num, int n, vector<bool> &isEle)
{
	if (num == n + 1) // �κ����� ���
	{
		for (int i = 0; i < n; i++)
		{
			if (isEle[i])
			{
				cout << i + 1 << ' ';
			}
		}

		cout << '\n';
	}
	else
	{
		// �� ��Ҹ� �����ϰų� ���ϰų��� ����
		isEle[num - 1] = true;
		PrintSet(num + 1, n, isEle);
		isEle[num - 1] = false;
		PrintSet(num + 1, n, isEle);
	}
}

// �κ�����
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	vector<bool> isElement(n); // �κ����տ� ��Ұ� �ִ��� üũ

	PrintSet(1, n, isElement);

	return 0;
}