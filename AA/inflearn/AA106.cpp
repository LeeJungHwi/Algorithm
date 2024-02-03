#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

// ���빮�ڿ�
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N, 3
	cin >> n;

	vector<string> words(n); // �ܾ� ����

	//	long
	//	longtime
	//	longest
	for (int i = 0; i < n; i++)
	{
		cin >> words[i];
	}

	// �Էµ� ���ڿ� �� ���� ���� ���ڿ� ã��

	int minSize = 2147000000;

	for (int i = 0; i < n; i++)
	{
		if (words[i].size() < minSize)
		{
			minSize = words[i].size(); // 4
		}
	}

	// �Էµ� �ܾ��� �� �ε��� ���� ���� ���� üũ �� ���� ���λ� ã��

	string commonPrefix = ""; // �������λ�
	bool isFinish = false; // �������λ縦 ã�Ҵ��� üũ

	for (int i = 0; i < minSize; i++)
	{
		int ch = words[0][i]; // l -> o -> n -> g

		for (int j = 0; j < n; j++)
		{
			if (ch != words[j][i]) // ���ڰ� �ٸ��ٸ� ���� ���ڱ���
			{
				commonPrefix = words[0].substr(0, i); // �������λ� ����
				isFinish = true; // �������λ� ã��
				break;
			}
		}

		if (isFinish) // �������λ縦 ã������ ����
		{
			break;
		}
	}
	
	// ���� commonPrefix�� ����ִٸ� ���� ���� ���ڿ� ũ�⸸ŭ ��� ��������
	if (commonPrefix.empty())
	{
		commonPrefix = words[0].substr(0, minSize);
	}

	// �������λ� ���
	cout << commonPrefix << '\n';

	return 0;
}
// �ٽ�
// string.substr()