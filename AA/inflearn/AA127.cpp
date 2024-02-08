#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

// ���ڿ� ���� ����
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	string inputString; // �Է¹��ڿ� 2(ab)(k)3(bc)
	cin >> inputString;

	stack<char> s; // ����

	string result = ""; // �������� ���ڿ�

	for (int i = 0; i < inputString.size(); i++)
	{
		// ���ÿ� �ݴ°�ȣ ������ ����
		// ���ÿ��� ���°�ȣ���� ������ ��ȣ�� ������ ���ڸ� ���ڿ��� ����
		// ����Ƚ����ŭ ���ڿ� �߰�(���ڰ� ���ٸ� �ѹ��� �߰�)

		if (inputString[i] == ')') // �ݴ°�ȣ�� ������
		{
			string temp = ""; // �ӽ� ���ڿ�

			while (s.top() != '(') // ���°�ȣ�� ���� ������ ������ ��Ҹ� ���ڿ��� ���� ab
			{
				temp = s.top() + temp;
				s.pop();
			}

			s.pop(); // ���°�ȣ ���ÿ��� ����

			// ���� Ȯ�� �� �ش� ���ڿ��� ���ڸ�ŭ �ݺ��ؼ� ���ڿ��� ����

			string repeatCntStr = ""; // �ݺ�Ƚ�� ���ڿ�

			// ���ڸ� ��� ���� ���ڿ� ���� 2
			while (!s.empty())
			{
				repeatCntStr = s.top() + repeatCntStr;
				s.pop();
			}

			int repeatCnt = 0; // �ݺ�Ƚ��

			if (!repeatCntStr.empty()) // �ݺ�Ƚ���� �ִٸ� ���ڿ��� ������ ��ȯ 2
			{
				repeatCnt = stoi(repeatCntStr);
			}
			else // ���ڰ� ���ٸ� �ѹ��� �ݺ�
			{
				repeatCnt = 1;
			}

			// �ݺ�Ƚ����ŭ �������� ���ڿ��� ���� abab
			for (int j = 0; j < repeatCnt; j++)
			{
				result.append(temp);
			}
		}
		else // �ݴ°�ȣ�� ������������ ���ÿ� ���� 2(ab
		{
			s.push(inputString[i]);
		}
	}

	// �������� ���ڿ� ���
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i];
	}

	return 0;
}
