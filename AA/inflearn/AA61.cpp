#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int n, m; // N, M
int elements[11]; // ��� ����
bool isElement[11]; // ��Ұ� �ִ��� üũ
bool isPlus[11]; // ��Ұ� �÷������� üũ
int caseCnt; // m�� ��������� ��� ����

// Ư�� �� �����
void MakeNum(int eleIndex, int n)
{
	if (eleIndex == n) // ���� ����
	{
		int result = 0;

		for (int i = 0; i < n; i++)
		{
			if (isElement[i]) // ��Ұ� �ִٸ�
			{
				result = isPlus[i] ? result + elements[i] : result - elements[i]; // �÷������� ���̳ʽ����� üũ
			}
		}

		if (m == result) // ��������� ���
		{
			caseCnt++;
		}
	}
	else
	{
		isElement[eleIndex] = true; // ��� ����
		isPlus[eleIndex] = true; // ��� �÷���
		MakeNum(eleIndex + 1, n);
		isPlus[eleIndex] = false; // ��� ���̳ʽ�
		MakeNum(eleIndex + 1, n);
		isElement[eleIndex] = false; // ��� ����
		MakeNum(eleIndex + 1, n);
	}
}

// Ư�� �� �����
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> elements[i];
	}

	// Ư�� �� �����
	MakeNum(0, n);

	if (caseCnt == 0)
	{
		cout << -1 << '\n';

		return 0;
	}

	cout << caseCnt << '\n';

	return 0;
}
// �ٽ�
// �÷��� ���̳ʽ� ��� �߰� -> �ð��ʰ� -> DFS �Ű������� ���������� ���� ���� ��� �迭 �Ἥ �ذ�

//#include <iostream>
//#include <vector>
//#include <fstream>
//using namespace std;
//
//// Ư�� �� �����
//void MakeNum(int eleIndex, vector<int> &elements, vector<bool> &isEle, vector<bool> &isPlus, int m, int &caseCnt)
//{
//	if (eleIndex == elements.size()) // ���� ����
//	{
//		int result = 0;
//
//		for (int i = 0; i < elements.size(); i++)
//		{
//			if (isEle[i]) // ��Ұ� �ִٸ�
//			{
//				result = isPlus[i] ? result + elements[i] : result - elements[i]; // �÷������� ���̳ʽ����� üũ
//			}
//		}
//
//		if (m == result) // ��������� ���
//		{
//			caseCnt++;
//		}
//	}
//	else
//	{
//		isEle[eleIndex] = true; // ��� ����
//		isPlus[eleIndex] = true; // ��� �÷���
//		MakeNum(eleIndex + 1, elements, isEle, isPlus, m, caseCnt);
//		isPlus[eleIndex] = false; // ��� ���̳ʽ�
//		MakeNum(eleIndex + 1, elements, isEle, isPlus, m, caseCnt);
//		isEle[eleIndex] = false; // ��� ����
//		MakeNum(eleIndex + 1, elements, isEle, isPlus, m, caseCnt);
//	}
//}
//
//// Ư�� �� �����
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	//ifstream cin;
//	//cin.open("input.txt");
//
//	int n, m; // N, M
//	cin >> n >> m;
//
//	vector<int> elements(n); // ��� ����
//	vector<bool> isElement(n); // ��Ұ� �ִ��� üũ
//	vector<bool> isPlus(n); // ��Ұ� �÷������� üũ
//	int caseCnt = 0; // m�� ��������� ��� ����
//
//	for (int i = 0; i < n; i++)
//	{
//		cin >> elements[i];
//	}
//
//	// Ư�� �� �����
//	MakeNum(0, elements, isElement, isPlus, m, caseCnt);
//
//	if (caseCnt == 0)
//	{
//		cout << -1 << '\n';
//
//		return 0;
//	}
//
//	cout << caseCnt << '\n';
//
//	return 0;
//}
//// �ٽ�
//// �÷��� ���̳ʽ� ��� �߰�