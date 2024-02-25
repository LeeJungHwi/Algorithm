#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <fstream>
using namespace std;

// �л� ����ü
struct Student
{
	int num; // �л� ��ȣ
	int atk; // �л� ���ݷ�
	char team; // �л��� ���� ��

	Student(int n, int a, char t) : num(n), atk(a), team(t) {} // ������

	bool operator<(const Student &student) const // ���ݷ� �������� ����
	{
		return atk < student.atk;
	}
};

// ��������
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ifstream cin;
	cin.open("input.txt");

	int n; // N, 7
	cin >> n;

	long long sumAtk = 0; // ������� ����
	vector<Student> student; // �л� ���� ����
	map<char, int> team; // ������� ���� �� ���� ���ݷ�
	vector<int> score(n); // �л��� ��� ���� ����

	//Input
	//a 17
	//b 12
	//a 10
	//c 11
	//b 24
	//a 25
	//b 12

	char t; // ��
	int a; // ���ݷ�

	for (int i = 0; i < n; i++)
	{
		cin >> t >> a;
		student.push_back(Student(i, a, t));
	}

	//���ݷ� ���� �������� ���� nlogn
	//num atk team
	// 2  10  a
	// 3  11  c
	// 1  12  b
	// 6  12  b
	// 0  17  a
	// 4  24  b
	// 5  25  a
	sort(student.begin(), student.end());

	int j = 0; // i�� j�� �Ѿư�

	for (int i = 1; i < n; i++) // ���ݷ��� ���峷�� �л��� ��������� �����Ƿ� i�� 1���� ���鼭
	{
		for ( ; j < n; j++) // j�� �� ���󰡸鼭
		{
			if (student[i].atk > student[j].atk) // i���� ���ݷ��� ������
			{
				sumAtk += student[j].atk; // j�� ������ ���� ����
				team[student[j].team] += student[j].atk; // ������� ���� j�� ���� ����

				continue;
			}

			// i �ڱ⺸�� ũ�� ������ break
			break;
		}

		// �� �л��� ��� ���� = �ڱ⺸�� ���ݷ��� �����ֵ� ��Ƽ� ���� ���� - ������� �ڱⰡ ���� ���� �л��� ��� ���� ����
		score[student[i].num] = sumAtk - team[student[i].team];
	}

	// �� �л��� ��� ���� ���
	for (int i = 0; i < n; i++)
	{
		cout << score[i] << "\n";
	}

	return 0;
}
// �ٽ�
// map ���

//#include <iostream>
//#include <vector>
//#include <queue>
//#include <map>
//#include <algorithm>
//#include <fstream>
//using namespace std;
//
//// ���� ����
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	//ifstream cin;
//	//cin.open("input.txt");
//
//	int n; // N 7
//	cin >> n;
//
//	vector<pair<char, int> > stuTeam(n + 1); // �� �л��� �������� ���ݷ� ����
//	map<char, vector<int> > atks; // �� ���� �����ִ� ���ݷµ� ����
//
//	char team; // ��
//	int atk; // ���ݷ�
//
//	for (int i = 1; i < n + 1; i++)
//	{
//		//a 17
//		//b 12
//		//a 10
//		//c 11
//		//b 24
//		//a 25
//		//b 12
//		cin >> team >> atk;
//
//		// (a,17) (b,12) (a,10) (c,11) (b,24) (a,25) (b,12)
//		stuTeam[i] = { team,atk };
//
//		//a -> 17 10 25
//		//b -> 12 24 12
//		//c -> 11
//		atks[team].push_back(atk);
//	}
//
//	// ���� �ٸ���� ���ݷ� �� �� ���� ����
//	for (int i = 1; i < n + 1; i++)
//	{
//		int score = 0; // ����
//
//		// �ٸ����� ���ݷ� �� �� ���� ����
//		for (auto it = atks.begin(); it != atks.end(); it++)
//		{
//			if (stuTeam[i].first != it->first) // ���� �ٸ����
//			{
//				for (auto a : it->second) // �� ���� �����ִ� ���ݷµ��� �ϳ��� �����ͼ�
//				{
//					if (stuTeam[i].second > a) // ���ݷ��� �� ���ٸ�
//					{
//						score += a; // ���� ����
//					}
//				}
//			}
//		}
//
//		cout << score << '\n';
//	}
//
//	return 0;
//}
//// �ٽ�
//// map ���