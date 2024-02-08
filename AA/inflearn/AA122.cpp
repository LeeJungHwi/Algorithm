#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <fstream>
using namespace std;

// �ߺ��� ���� ����
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	string inputString; // �Է¹��ڿ� CbDBEaCEb
	cin >> inputString;

	map<char, int> alphaCnt; // ���ĺ� ����
	map<char, bool> vis; // ���� �湮üũ

	string result = ""; // ��� ���ڿ�

	for (int i = 0; i < inputString.size(); i++)
	{
		// �Է¹��ڿ��� �빮�ڷ�
		if (islower(inputString[i]))
		{
			inputString[i] = toupper(inputString[i]); // CBDBEACEB
		}

		alphaCnt[inputString[i]]++; // �� ������ ���� ī��Ʈ
	}

	for (int i = 0; i < inputString.size(); i++)
	{
		if (!vis[inputString[i]]) // �湮���� ���� ������ ���
		{
			// ������ڿ��� ������������鼭
			// ������ڿ��� ���������ڰ� ���繮�ں��� ���������� �ڿ� �����鼭
			// �����ص� �ڿ� ���� ���ڰ� ��� 1���� �����ִ°��
			// ������ڿ��� ���������� �湮üũ ���� �� ����
			while (!result.empty() && result.back() > inputString[i] && alphaCnt[result.back()] > 0)
			{
				vis[result.back()] = false;
				result.pop_back();
			}

			// ���繮�� ������ڿ��� �߰� �� �湮üũ
			result.push_back(inputString[i]);
			vis[inputString[i]] = true;
		}

		// ó���� ������ ���� ����
		alphaCnt[inputString[i]]--;
	}

	cout << result; // BDACE

	return 0;
}
