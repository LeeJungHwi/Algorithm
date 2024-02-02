#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// �ִ����� ���ϱ�(����)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M 5 20
	cin >> n >> m;

	vector<pair<int, int> > problems(n); // ����

	int score; // ���� ����
	int time; // �ɸ��� �ð�

	//	10 5
	//	25 12
	//	15 8
	//	6 3
	//	7 4
	for (int i = 0; i < n; i++)
	{
		cin >> score >> time;

		problems[i] = { score, time };
	}

	vector<int> scores(m + 1); // ���ѽð��� ���� �ְ����� ����, �� ������ ������ Ǯ �� ����

	for (int i = 0; i < n; i++)
	{
		for (int j = m; j > problems[i].second - 1; j--) // ���ѽð� m���� �����ð� ���� ���鼭 �ְ����� ����
		{
			if (scores[j] < scores[j - problems[i].second] + problems[i].first)
			{
				scores[j] = scores[j - problems[i].second] + problems[i].first;
			}
		}
	}

	cout << scores[m] << '\n';

	return 0;
}
// �ٽ�
// �������� �ƴϸ� ���̳��� �Ųٷ�