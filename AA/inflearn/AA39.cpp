#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// �� �迭 ��ġ��
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M
	int num; // ����
	vector<int> firstVec(200); // ù �迭
	vector<int> secondVec(200); // �ι�° �迭

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		firstVec[i] = num; // 1 3 5
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> num;
		secondVec[i] = num; // 2 3 6 7 9
	}		

	// �� �迭 ��ġ��
	// �ι�° �迭�� ù �迭 ��Ҹ� �ϳ��� ������ġ ã�Ƽ� ����
	// ������ġ�� ù�迭 ����� ������ ũ�ų� ���� ���� �ι�° �迭���� ã�� �ش� �ε����� ����

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m + i; j++)
		{
			if (firstVec[i] <= secondVec[j]) // ù �迭 ��� ������ ũ�ų� ���� ���� �ι�° �迭���� ã��
			{
				for (int k = m + i - 1; k > j - 1; k--) // ������ ����Ʈ ��
				{
					secondVec[k + 1] = secondVec[k];
				}

				// ù �迭 ��Ұ� �ι�° �迭�� ����
				secondVec[j] = firstVec[i];
				break;
			}
		}
	}

	for (int i = 0; i < n + m; i++)
	{
		cout << secondVec[i] << ' ';
	}

	return 0;
}