#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <fstream>
using namespace std;

// ���� ����
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 7
	cin >> n;

	vector<pair<char, int> > stuTeam(n + 1); // �� �л��� �������� ���ݷ� ����
	map<char, vector<int> > atks; // �� ���� �����ִ� ���ݷµ� ����

	char team; // ��
	int atk; // ���ݷ�

	for (int i = 1; i < n + 1; i++)
	{
		//a 17
		//b 12
		//a 10
		//c 11
		//b 24
		//a 25
		//b 12
		cin >> team >> atk;

		// (a,17) (b,12) (a,10) (c,11) (b,24) (a,25) (b,12)
		stuTeam[i] = { team,atk };

		//a -> 17 10 25
		//b -> 12 24 12
		//c -> 11
		atks[team].push_back(atk);
	}

	// ���� �ٸ���� ���ݷ� �� �� ���� ����
	for (int i = 1; i < n + 1; i++)
	{
		int score = 0; // ����

		// �ٸ����� ���ݷ� �� �� ���� ����
		for (auto it = atks.begin(); it != atks.end(); it++)
		{
			if (stuTeam[i].first != it->first) // ���� �ٸ����
			{
				for (auto a : it->second) // �� ���� �����ִ� ���ݷµ��� �ϳ��� �����ͼ�
				{
					if (stuTeam[i].second > a) // ���ݷ��� �� ���ٸ�
					{
						score += a; // ���� ����
					}
				}
			}
		}

		cout << score << '\n';
	}

	return 0;
}
// �ٽ�
// map ���