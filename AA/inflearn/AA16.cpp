#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// ���ĺ� ���� ī��Ʈ
// cout << 'a' - '0' << 'A' - '0' << 'z' - '0' << 'Z' - '0'; 49 17 74 42
// cout << 'a' - 97 << 'z' - 97 << 'A' - 39 << 'Z' - 39;
// a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z -> 26�� 0~25
// A ~ Z -> 26�� 26~51
vector<int> fcnts(52), scnts(52); // ���ĺ� ���� ī��Ʈ

// ���ĺ� ���� ī��Ʈ
void CountAlpha(string word, vector<int> &cnts)
{
	for (int i = 0; i < word.size(); i++) // �ܾ� ũ�⸸ŭ ���鼭
	{
		if (word[i] - '0' >= 49 && word[i] - '0' <= 74) // �ҹ���
		{
			cnts[word[i] - 97]++;
		}
		else // �빮��
		{
			cnts[word[i] - 39]++;
		}
	}
}

// �Ƴ��׷� üũ
// fcnts�� scnts�� ������ �Ƴ��׷�
void CheckAnagram()
{
	for (int i = 0; i < 52; i++) // ���ĺ� ��ҹ��� ������ŭ ���鼭
	{
		if (fcnts[i] != scnts[i]) // �ϳ��� ���ĺ��� ������ ���������� NO
		{
			cout << "NO" << '\n';
			return;
		}
	}
	
	cout << "YES" << '\n'; // ���ĺ� ������ ���ٸ� YES
}

// �Ƴ��׷�(����)
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	string fWord, sWord; // ù��° �ܾ�, �ι�° �ܾ�
	cin >> fWord >> sWord;

	CountAlpha(fWord, fcnts); // ù��° �ܾ� ���ĺ� ���� ī����
	CountAlpha(sWord, scnts); // �ι�° �ܾ� ���ĺ� ���� ī����
	CheckAnagram();

	return 0;
}

// �ٽ�
// ���͸� ���ڷ� �ѱ涧 ���Ͱ� ����Ǿ� �Ѱ����Ƿ� �������·� �ѱ�
// ���ĺ� ���� 26��
// ���ڸ� ���ڷ� -> ���� - '0'
// �ҹ��ڸ� ���ڷ� -> a 49 z 74
// �빮�ڸ� ���ڷ� ->  A 17 Z 42
// �ҹ��ڸ� 0���� ������ -> a - '0' - 49 -> a - 97
// �빮�ڸ� 26���� ������ -> A -'0' + 9 -> A - 39