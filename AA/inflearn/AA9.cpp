#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// ����� ���
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // �ڿ��� N
	cin >> n;

	vector<int> cnts(50001); // ��� ����

	for (int i = 1; i < n + 1; i++) // 1~N ����
	{
		for (int j = i; j < n + 1; j = j + i) // i�� ����϶� ī��Ʈ
		{
			cnts[j - 1]++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << cnts[i] << " ";
	}

	return 0;
}

// �ٽ�
// �� ���� ����� ���ϴ°��� �ƴ� ����� �Ǵ� ���� ����� ī��Ʈ