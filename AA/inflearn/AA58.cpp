#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// ����Ʈ�� ��ȸ
// child(1) : �����ڽ� ���ȣ�� �������ڽ� ���ȣ��
// 7�������� ����
void Traversal(int rootNode)
{
	if (rootNode > 7)
	{
		return;
	}
	else
	{
		//cout << rootNode << ' '; // ������ȸ
		Traversal(rootNode * 2);
		//cout << rootNode << ' '; // ������ȸ
		Traversal(rootNode * 2 + 1);
		//cout << rootNode << ' '; // ������ȸ
	}
}

// ����Ʈ�� ���̿켱Ž��
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// ����Ʈ�� ���� �ڽĳ�� = �θ��� * 2
	// ����Ʈ�� ������ �ڽĳ�� = �θ��� * 2 + 1
	// ������ȸ : �θ� ���� ������
	// ������ȸ : ���� �θ� ������
	// ������ȸ : ���� ������ �θ�

	// ����Ʈ�� ����
	Traversal(1);

	return 0;
}