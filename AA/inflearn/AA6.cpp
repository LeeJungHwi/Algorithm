#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// ���ڸ� ����
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	string input; // �Է� ���ڿ�
	cin >> input;

	string num; // ���� ���ڿ�
	int num_ = 0; // ���� ���ڿ��� ���ڷ�

	int pos = 1; // �ڸ���

	int cnt = 0; // ��� ����

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] - '0' >= 0 && input[i] - '0' <= 9) // ���ڹ��ڸ� ����
		{
			num.append(1, input[i]);
		}
	}

	int i = 0;
	//0 2 0 8
	while (true)
	{
		if (num[i] - '0' == 0) // ó�� 0�� �ƴ� ���ڰ� ���ö����� ����
		{
			i++;
			continue;
		}

		for (int j = num.size() - 1; j > i - 1; j--) // 1�� �ڸ�������
		{
			if (num[j] - '0' == 0) // 0�̳����� �ڸ����� ����
			{
				pos *= 10;
				continue;
			}

			num_ += (num[j] - '0') * pos; // ���� * �ڸ���
			pos *= 10; // �ڸ��� ����
		}

		break;
	}

	for (int j = 1; j < num_ + 1; j++) // ��� ����
	{
		if (num_ % j == 0)
		{
			cnt++;
		}
	}

	cout << num_ << '\n' << cnt << '\n';
	return 0;
}