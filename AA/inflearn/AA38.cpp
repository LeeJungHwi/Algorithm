#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// �ι��� ����
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	vector<int> inversionVec(n); // �ι��� ���� ����
	vector<int> originVec(n); // ���� ����

	int inversionNum; // �ι��� ����

	// �ι��� ���� ���� �� ���� ���� �ʱ�ȭ
	for (int i = 0; i < n; i++)
	{
		cin >> inversionNum;
		inversionVec[i] = inversionNum; // 53402110 -> 48625137
		originVec[i] = n - i; // �������� �� �������� ���� : 87654321
	}

	// ���� ����
	// 87654321 : ������������ �ʱ�ȭ
	// 87654132 : 1 �� 1���� ū �� ������ 5���� �ǵ����ϴ� ��ġ�� ����
	// 87625143 : 2 �� 2���� ū �� ������ 3���� �ǵ����ϴ� ��ġ�� ����, ���κ��� �������� ���������� ����Ʈ��������
	// 87625134 : ....
	// 48726135 : ....
	// 48725136 : 5 �� 5���� ū �� ������ 2���� �ǵ����ϴ� ��ġ�� ����, ���κ��� �������� ���������� ����Ʈ��������
	// 48625137 : 6 �� 6���� ū �� ������ 1���� �ǵ����ϴ� ��ġ�� ����, ���κ��� �������� ���������� ����Ʈ��������

	for (int i = 0; i < n - 1; i++) // ���� ���� ���� �ι��� ���� ������ 0�̹Ƿ� �������ʿ����
	{
		int largeCnt = 0; // ���κ��� ū ��
		bool isSort = false; // ���ĵǾ����� üũ

		for (int j = n - 1; j > -1; j--) // ������ �ε������� ���鼭
		{
			if (originVec[j] == i + 1) // i + 1 ã�� : �����ؾ��� ��
			{
				// ã�� �ε��� ������ ���鼭 i + 1���� ū ���� ����� ����
				for (int k = j - 1; k > -1; k--)
				{
					if (originVec[k] > i + 1)
					{
						largeCnt++;
					}
				}

				// ���� i + 1���� ū ���� �ι��� ������ i��° ���� ���ٸ� ����
				// �����ʴٸ� largeCnt-- �ϸ鼭 ������ ��ġ ã��
				if (largeCnt == inversionVec[i])
				{
					isSort = true;
					break;
				}
				else
				{
					for (int k = j - 1; k > -1; k--) // ã�� �ε��� ������ ���鼭 largeCnt ����
					{
						if (originVec[k] > i + 1)
						{
							largeCnt--;
						}

						if (largeCnt == inversionVec[i]) // ������ �������� ���� ��ġ�� k
						{
							for (int l = n - 2; l > k - 1; l--) // ������ ������ k���� i + 1���� ū���� ������ ����Ʈ(����Ʈ �Ҷ� �������� ������ȵ�)
							{
								if (originVec[l] > i + 1) // ū ���� ������ ����Ʈ
								{
									// ������ ����Ʈ �Ϸ��µ� i + 1���� ���� ���� �ǳʶٸ鼭 ����Ʈ �ؾ���
									for (int m = l + 1; m < n; m++)
									{
										if (originVec[m] < i + 1) // ������ ���� i + 1���� ���� ���̸� continue
										{
											continue;
										}

										// ���⼭ m���� ����Ʈ�Ǿ� ����� �ε���
										originVec[m] = originVec[l];

										break;
									}
								}
							}

							// i + 1�� k�� ���� �� ����
							originVec[k] = i + 1;
							isSort = true;
							break;
						}
					}
				}
			}

			if (isSort)
			{
				break;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << originVec[i] << ' ';
	}

	return 0;
}

// �ٽ�
// break ��ġ