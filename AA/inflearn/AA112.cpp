#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

// ��� �Ƴ��׷�
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	string s, t;
	cin >> s >> t;

	vector<int> alphaT(26); // t�� ���ĺ� ���� ����
	vector<int> alphaS(26); // s�� �κй��ڿ� ���ĺ� ���� ����

	// t ���ڿ��� �� ���ĺ� ���� ����
	for (int i = 0; i < t.size(); i++)
	{
		alphaT[t[i] - '0' - 49]++;
	}

	int anaCnt = 0; // �Ƴ��׷� ����

	// �ʱ� �����̵� ������ ���ĺ� ���� ����
	for (int i = 0; i < t.size(); i++)
	{
		alphaS[s[i] - '0' - 49]++;
	}

	// ù ��° �������� �Ƴ��׷� ���� üũ
	bool isAnagram = true;

	for (int i = 0; i < 26; i++)
	{
		if (alphaT[i] != alphaS[i])
		{
			isAnagram = false;
			break;
		}
	}

	if (isAnagram)
	{
		anaCnt++;
	}

	// �����̵� ������ �̵��ϸ� �Ƴ��׷� ���� ����
	for (int i = t.size(); i < s.size(); i++)
	{
		alphaS[s[i - t.size()] - '0' - 49]--; // �����쿡�� ���ܵǴ� ������ ���� ����

		alphaS[s[i] - '0' - 49]++; // ���ο� ������ ���� ����

		// �������� �Ƴ��׷� ���� üũ
		isAnagram = true;

		for (int j = 0; j < 26; j++)
		{
			if (alphaT[j] != alphaS[j])
			{
				isAnagram = false;
				break;
			}
		}

		if (isAnagram)
		{
			anaCnt++;
		}
	}

	cout << anaCnt << '\n';

	return 0;
}
// �ٽ�
// �ð��ʰ� -> �����̵� ������� �ذ�

//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <string>
//#include <fstream>
//using namespace std;
//
//// ��� �Ƴ��׷�
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	ifstream cin;
//	cin.open("input.txt");
//
//	string s, t; // S, T eabcbacade, abc
//	cin >> s >> t;
//
//	vector<int> alpha(26); // ���ĺ� ���� ����
//
//	for (int i = 0; i < t.size(); i++)
//	{
//		alpha[t[i] - '0' - 49]++; // 1 1 1
//	}
//
//	// �κй��ڿ��� �Ƴ��׷����� üũ
//
//	int anaCnt = 0; // �Ƴ��׷� ����
//
//	for (int i = 0; i < s.size() - t.size() + 1; i++) // s�� ���鼭
//	{
//		if (alpha[s[i] - '0' - 49] > 0) // t�� ������ ���ĺ��� ������
//		{
//			vector<int> check(26);
//			bool isAnagram = true; // �Ƴ��׷����� üũ
//
//			for (int j = i; j < i + t.size(); j++) // �κ� ���ڿ� ���ĺ� ���� ����
//			{
//				check[s[j] - '0' - 49]++;
//			}
//
//			// �ϳ��� ������ �ٸ��� �Ƴ��׷� �ƴ�
//			for (int j = 0; j < t.size(); j++)
//			{
//				if (alpha[t[j] - '0' - 49] != check[t[j] - '0' - 49])
//				{
//					isAnagram = false;
//				}
//			}
//
//			// �κй��ڿ��� �Ƴ��׷��̸� �Ƴ��׷� ���� ī����
//			if (isAnagram)
//			{
//				anaCnt++;
//			}
//		}
//	}
//
//	cout << anaCnt << '\n';
//
//	return 0;
//}