#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// ���� ���ϱ�
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	int score; // ����

	vector<int> originScores(100, 0); // �Էµ� ������� ���� 
	vector<int> sortedScores(100, 0); // �������� ���� ����

	// ó�� ���� ����
	cin >> score;
	originScores[0] = score;
	sortedScores[0] = score;

	vector<int>::iterator it = sortedScores.begin(); // ���ͷ�����

	for (int i = 1; i < n; i++)
	{
		// �Էµ� ������� ����
		cin >> score;
		originScores[i] = score;

		// ���� �� ������ ���� ����
		// 5
		// 90 85 92 95 90 -> origin
		// sccore ���� �� �ε��� 0 ���� ���� ���ԵǾ���� �ε��� ���ϱ�
		// j - 1 ������ �Էµ� �������� ���ų� ũ�� �̵� X
		// j - 1��° ������ �Էµ� �������� ������ �̵�Ƚ��++
		// 85 -> 90 85
		// 92 -> 92 90 85
		// 95 -> 95 92 90 85
		// 90 -> 95 92 90 90 85 -> sorted

		// ���ԵǾ���� �ε��� ���ϱ�
		int insertIndex = i;
		for (int j = i - 1; j > -1; j--)
		{
			if (sortedScores[j] < score)
			{
				insertIndex = j;
			}
		}

		// ���� �������� �����ϱ�
		sortedScores.insert(it + insertIndex, 1, score);

		// ���ͷ����� �ʱ�ȭ
		it = sortedScores.begin();
	}

	// ����� ��¿�
	//for (int i = 0; i < originScores.size(); i++)
	//{
	//	cout << originScores[i] << ' ';
	//}

	//cout << '\n';

	//for (int i = 0; i < sortedScores.size(); i++)
	//{
	//	cout << sortedScores[i] << ' ';
	//}

	// ���� ���ϱ�
	// 90 85 92 95 90 -> origin
	// 95 92 90 90 85 -> sorted
	// origin ��Ҷ� ���� ������ sorted ���� ã�� �ε����� �����
	// ó�� �߰ߵ� ������ ã���Ƿ� ���� ������ ���� ������ �ڵ� ��µ�
	// ���� ������ ���ϼ����� ���͵� �ε����� ó���ϹǷ� �ڵ����� �� ���� �л��� ���ϼ��� �л� �� ��ŭ �� ����� �з���
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (originScores[i] == sortedScores[j]) // ã���� �ε��� ���
			{
				cout << j + 1 << ' ';
				break;
			}
		}
	}

	return 0;
}

// �ٽ�
// �ݺ��ڸ� �̿��� ����