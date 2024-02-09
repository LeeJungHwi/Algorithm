#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

// �ִ� ���� �κ� ���ڿ�
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	string first; // ù ���ڿ� acbehf
	cin >> first;

	string second; // �ι�° ���ڿ� abefc
	cin >> second;

	// lengths[i][j] : ù��° ���ڿ� i��° ���̱����� �ι�° ���ڿ� j��° ���̱��� �ִ���빮�ڿ� ����
	vector<vector<int> > lengths(first.size() + 1, vector<int>(second.size() + 1));

	// DP
	// �� �κй��ڿ��� ������ ���ڰ� ������ : lengths[i][j] = lengths[i - 1][j - 1] + 1
	// �� �κй��ڿ��� ������ ���ڰ� �ٸ��� : lengths[i][j] = max(lengths[i - 1][j], lengths[i][j - 1])
	for (int i = 1; i < first.size() + 1; i++)
	{
		for (int j = 1; j < second.size() + 1; j++)
		{
			if (first[i - 1] == second[j - 1]) // �� �κй��ڿ��� ������ ���ڰ� ���ٸ�
			{
				lengths[i][j] = lengths[i - 1][j - 1] + 1; // �� �κй��ڿ��� ������ ���ڸ� �� �ִ���� + 1
			}
			else // �� �κй��ڿ��� ������ ���ڰ� �ٸ��ٸ�
			{
				lengths[i][j] = max(lengths[i - 1][j], lengths[i][j - 1]); // max(ù���ڿ��� ���������� �� �ִ����, �ι�°���ڿ��� ���������� �� �ִ����)
			}
		}
	}

	cout << lengths[first.size()][second.size()] << '\n';

	return 0;
}