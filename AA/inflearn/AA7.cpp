#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// ����ܾ� ����
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	string input; // �Է� �ܾ�
	getline(cin, input); // ���� ���� ����

	string result; // ���� �ܾ�

	// �ҹ��ڴ� �״�� append
	// �빮�ڴ� �ҹ��ڷ� append
	int gap = 'A' - 'a'; // �빮�� �ҹ��� ����

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] >= 'a' && input[i] <= 'z') // �ҹ���
		{
			result.append(1, input[i]);
		}
		else if (input[i] >= 'A' && input[i] <= 'Z') // �빮��
		{
			result.append(1, input[i] - gap);
		}
	}

	cout << result << '\n';

	return 0;
}

// �ٽ�
// getling(cin, string) -> ������ ������ string�� ����
// string.append(n, 'a') -> string �ڿ� n���� a�� ����