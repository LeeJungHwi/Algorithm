#include <iostream>
#include <fstream>
using namespace std;

// 1���� N���� �� ���ϱ�
int Sum(int num)
{
	int result = 0;

	for (int i = 1; i < num + 1 ; i++) // 1���� N���� ��
	{
		result += i;
	}

	return result;
}

// ������ ����
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	int cardNum, resultNum; // ī�����, ��������

	for (int i = 0; i < n; i++)
	{
		cin >> cardNum >> resultNum;

		if (Sum(cardNum) == resultNum) // �������ڰ� �����̸�
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}
	}

	return 0;
}