#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

// ������ ��
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	string s;
	cin >> s;

	vector<string> nums; // ���ڿ����� �߰ߵ� ���ڸ� ����
	int sum = 0; // ������ ������ ��

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] - '0' > 0 && s[i] - '0' < 10) // 0�� �ƴ� ���ڸ� ������
		{
			string num = "";

			for (int j = i; j < s.size(); j++) // �߰��� ���ں��� ���ڸ� ���������� ���� �����
			{
				i = j + 1; // j + 1�� ���ں��� �ٽ� �о

				if (s[j] - '0' < 0 || s[j] - '0' > 9) // ���ڸ� ������ ����
				{
					break;
				}

				num.append(1, s[j]); // ���� �����
			}

			// ���ڿ����� �߰ߵ� ���� ����
			nums.push_back(num); // 50 33 17
		}
	}

	for (int i = 0; i < nums.size(); i++)
	{
		sum += stoi(nums[i]);
	}

	cout << sum << '\n';

	return 0;
}
// �ٽ�
// ��𼭺��� �ٽ� �������� ����
// stoi : ���ڿ��� ���ڷ� ��ȯ
// append(����, ����) : ���ڸ� ������ŭ ����