#include <iostream>
#include <stack>
#include <string>
#include <fstream>
using namespace std;

// �ùٸ� ��ȣ
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");
	
	string input; // �Է� ��ȣ
	cin >> input;

	stack<char> p; // ��ȣ ����

	string result; // ���

	int pushCnt = 0; // push Ƚ��

	// 1. �ݴ°�ȣ�϶����� push
	// 2. �ݴ°�ȣ�϶� pop �ι�
	// 3. �Է°� ������ ������� YES
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] != ')') // �ݴ°�ȣ�� �ƴϸ�
		{
			p.push(input[i]);
			pushCnt++;
		}
		else // �ݴ°�ȣ
		{
			if (!p.empty())
			{
				p.push(input[i]);
				pushCnt++;
				p.pop();
				p.pop();
			}
		}
	}

	if (p.empty() && pushCnt == input.size()) // ������ ����ְ� �Է°�ȣ�� ��� �о�����
	{
		cout << "YES\n";
		return 0;
	}
	
	cout << "NO\n";
	return 0;
}

// �ٽ�
// �Է½�Ʈ���� ������ ��� ���� �ùٸ� ��ȣ