#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

// ������ ���ϱ�
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, c; // N, C
	cin >> n >> c;

	int xi; // ������ ��ǥ
	vector<int> xiVec(n); // ������ ��ǥ ����

	for (int i = 0; i < n; i++)
	{
		cin >> xi;
		xiVec[i] = xi; // 1 2 8 4 9
	}

	sort(xiVec.begin(), xiVec.end()); // 1 2 4 8 9

	int first = xiVec[0]; // ó��
	int last = xiVec[n - 1]; // ������

	// �� �� ���� �Ÿ��� �ɼ��ִ� ������ 1 ~ 9
	// first standard last
	// 1     5        9
	// �� �� ���� �Ÿ��� 5 �̻��̾����
	// ù��° ���� 1�� ���� ���� ��ǥ���� 1�� ���鼭 5�̻��� �Ǵ� ������ 8�� �ι�° �� ����
	// �ι�° ������ ���� ��ǥ���� 1�� ���鼭 5�̻��� �Ǵ� ������ �����Ƿ� 5�� �ƴ�
	// 1     2        4
	// �� �� ���� �Ÿ��� 2 �̻��̾����
	// ù��° ���� 1�� ���� ���� ��ǥ���� 1�� ���鼭 2�̻��� �Ǵ� ������ 4�� �ι�° �� ����
	// �ι�° ������ ���� ��ǥ���� 1�� ���鼭 2�̻��� �Ǵ� ������ 8�� ����° �� ����
	// ����° ���� �������Ƿ� 2�� ����
	// 3     3        4
	// �� �� ���� �Ÿ��� 3 �̻��̾����
	// ù��° ���� 1�� ���� ���� ��ǥ���� 1�� ���鼭 3�̻��� �Ǵ� ������ 4�� �ι�° �� ����
	// �ι�° ������ ���� ��ǥ���� 1�� ���鼭 2�̻��� �Ǵ� ������ 8�� ����° �� ����
	// ����° ���� �������Ƿ� 3�� ����
	// 3�� 2���� ũ�Ƿ� �ִ밪 ����
	// 4    4         4
	// �� �� ���� �Ÿ��� 4 �̻��̾����
	// ù��° ���� 1�� ���� ���� ��ǥ���� 1�� ���鼭 4�̻��� �Ǵ� ������ 8�� �ι�° �� ����
	// �ι�° ������ ���� ��ǥ���� 1�� ���鼭 4�̻��� �Ǵ� ������ �����Ƿ� 4�� �ƴ�
	// 4    >         3
	// first�� last�� �����Ǿ����Ƿ� ����

	int maxCloseDis = 0; // �� �� ���� �Ÿ��� �ִ�

	while (first <= last) // first�� last�� �����Ǹ� ����
	{
		int standard = (first + last) / 2; // �� �� ���� �Ÿ��� standard �̻��̾����
		int horseIndex = 0; // ���� ��ġ�� �ε���
		int horseCnt = 1; // ��ġ�� ���� �� : ù �ε����� �̹� �Ѹ��� ��ġ�� ����

		// 1 2 4 8 9
		for (int i = 1; i < n; i++)
		{
			if (xiVec[i] - xiVec[horseIndex] >= standard) // �� ���� �Ÿ��� standard �̻��̸�
			{
				horseIndex = i; // ������ ��ġ
				horseCnt++;

				if (horseCnt == c) // ����° �� ��ġ������ ���̻� ��ġ���ʿ����
				{
					break;
				}
			}
		}

		//cout << horseCnt << '\n';

		if (horseCnt == c) // ������ ���
		{
			first = standard + 1;

			if (maxCloseDis < standard) // �ִ� �Ÿ� ����
			{
				maxCloseDis = standard;
			}
		}
		else // �Ұ����� ���
		{
			last = standard - 1;
		}
	}

	cout << maxCloseDis << '\n';

	return 0;
}
// �ٽ�
// ����Ž�� ������ first last ������ �� �ľ�
// ù �ε����� �̹� �Ѹ��� ��ġ�� �����̹Ƿ� 1�� �ʱ�ȭ