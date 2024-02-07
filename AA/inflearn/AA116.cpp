#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <string>
#include <fstream>
using namespace std;

// ����ũ�� ���ڿ�
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 5
	cin >> n;

	char uniqueChar; // Ư������ b
	cin >> uniqueChar;

	uniqueChar = toupper(uniqueChar); // Ư������ �빮�ڷ� B

	string inputString; // �Է¹��ڿ� Queen Apple Best Remember Beer
	vector<bool> vis(100); // �湮üũ
	
	for (int i = 0; i < n; i++)
	{
		cin >> inputString;

		// QUEeN APpLE BEST REMemBer BEeR
		for (int j = 0; j < inputString.size(); j++)
		{
			if (vis[toupper(inputString[j])]) // �̹� �湮�� ���ڴ� �ҹ��ڷ� ���ܵ�
			{
				continue;
			}

			inputString[j] = toupper(inputString[j]); // �湮�� ���ڰ� �ƴϸ� �빮�ڷ�
			vis[inputString[j]] = true; // �湮üũ
		}

		// BEST REMemBer BEeR

		bool isUniqueString = false; // ����ũ ���ڿ����� üũ

		for (int j = 0; j < inputString.size(); j++)
		{
			if (inputString[j] == uniqueChar) // �ϳ��� Ư�����ڶ� ������ ����ũ ���ڿ�
			{
				isUniqueString = true;
				break;
			}
		}

		// BEST REMB BER
		if (isUniqueString)
		{
			string uniqueString = ""; // ����ũ ���ڿ�

			for (int j = 0; j < inputString.size(); j++) // �빮�ڸ� ����
			{
				if (isupper(inputString[j]))
				{
					uniqueString += inputString[j];
				}
			}

			cout << uniqueString << '\n';
		}

		fill(vis.begin(), vis.end(), false); // �湮üũ �ʱ�ȭ
	}

	return 0;
}
// �ٽ�
// isupper, islower, toupper, tolower