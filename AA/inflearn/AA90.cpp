#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
using namespace std;

// �ɹٰ� �����̴� ���� ����
struct State
{
	int x, y, dis; // x��ǥ, y��ǥ, �Ÿ�

	State(int curX, int curY, int curDis) // ������
	{
		x = curX;
		y = curY;
		dis = curDis;
	}
	
	bool operator<(const State &state) const // ���� ���� : 1.�Ÿ��� ����� �䳢 2. ���ʿ��ִ� �䳢 3. ���ʿ� �ִ� �䳢 
	{
		if (dis != state.dis)
		{
			return dis > state.dis;
		}

		if (x != state.x)
		{
			return x > state.x;
		}

		return y > state.y;
	}
};

// �ɹ�
struct Simba
{
	int x, y, s, ate; // x��ǥ, y��ǥ, ũ��, ����Ƚ��

	// �ɹ� ũ�� ����
	void sizeUp()
	{
		ate = 0;
		s++;
	}
};

// ���̾� ŷ �ɹ�
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N, 3
	cin >> n;

	Simba simba; // �ɹ�
	priority_queue<State> Q; // �켱������ ���� �䳢���� ����

	vector<vector<int> > graph(25, vector<int>(25)); // �׷���
	vector<vector<int> > vis(25, vector<int>(25)); // �湮üũ
	vector<pair<int, int> > checkDir; // �� �� �� ��
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	int goSka = 0; // �ɹٰ� ��ī���̿��� �����Ϸ����µ� �ɸ��� �ð�

	//	0 1 3
	//	1 9 1
	//	0 1 1
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			cin >> graph[i][j];

			// �ɹ� ��ġ
			if (graph[i][j] == 9)
			{
				simba.x = i;
				simba.y = j;
				graph[i][j] = 0;
			}
		}
	}

	// ó�� �ɹ� ��ġ �켱���� ť�� ����
	Q.push(State(simba.x, simba.y, 0));
	simba.s = 2;
	simba.ate = 0;

	// BFS
	while (!Q.empty()) // ť�� ��������
	{
		// �켱������ �°� �̵��� ��ġ ����
		State state = Q.top();
		Q.pop();

		int curX = state.x;
		int curY = state.y;
		int curDis = state.dis;

		if (graph[curX][curY] != 0 && graph[curX][curY] < simba.s) // �̵��� ��ġ�� ��ĭ�� �ƴϸ鼭 �ɹ��� ũ�Ⱑ �� Ŭ��
		{
			// �̵� �� �䳢�� ����
			simba.x = curX;
			simba.y = curY;
			simba.ate++;

			// �ɹ��� ũ�� Ƚ����ŭ �䳢�� �Ծ����� �ɹ� ������ ����
			if (simba.ate >= simba.s)
			{
				simba.sizeUp();
			}

			// ������ �䳢�� ��ĭ����
			graph[curX][curY] = 0;

			// �湮üũ �ʱ�ȭ -> ��Ƹ��� ��ġ���� �ٽ� BFS ����������
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					vis[i][j] = 0;
				}
			}

			// �켱���� ť �ʱ�ȭ
			while (!Q.empty())
			{
				Q.pop();
			}

			// ������� �ɹٰ� ������ �Ÿ� ����
			goSka = state.dis;
		}

		// �� �� �� ��
		for (int i = 0; i < 4; i++)
		{
			// üũ �� ��ǥ
			int checkX = curX + checkDir[i].first;
			int checkY = curY + checkDir[i].second;

			// ���üũ
			if (checkX < 1 || checkX > n || checkY < 1 || checkY > n)
			{
				continue;
			}

			// ������ üũ
			if (graph[checkX][checkY] > simba.s)
			{
				continue;
			}

			// �湮 üũ
			if (vis[checkX][checkY] > 0)
			{
				continue;
			}

			Q.push(State(checkX, checkY, curDis + 1)); // ť�� ����
			vis[checkX][checkY] = 1; // �湮üũ
		}
	}

	cout << goSka << '\n';
	return 0;
}
