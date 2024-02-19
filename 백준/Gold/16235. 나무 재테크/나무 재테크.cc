#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <fstream>
using namespace std;

// 나무재테크
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// n by n 1-based 
	// 모든 칸에 초기양분 5
	// m개의 묘목을 심음
	// 봄 : 심어진 나무의 나이만큼 양분을 먹고 나이가 1증가함
	// 해당 나무가 심어진 칸의 양분만 먹을수있음
	// 하나의 칸에 여러개의 나무가 있다면 어린나무부터 양분을 먹음
	// 만약 자신의 나이만큼 양분을 먹을수없는 나무는 죽음
	// 여름 : 봄에 죽은 나무가 양분으로 변함
	// 각 죽은 나무마다 나이를 2로 나눈값이 해당 나무가 있던칸의 양분으로 추가되고 소수점 아래는 버림
	// 가을 : 나무가 번식함
	// 번식 가능한 나무는 나이가 5의 배수이며 인접한 8개의 칸에 나이가 1인 나무가 생김
	// 경계를 벗어나는 칸에는 나무가 생기지않음
	// 겨울 : 로봇이 땅을 돌아다니면서 땅에 양분을 추가함
	// 각 칸에 추가되는 양분의 양은 A[r][c]로 입력을 통해 주어짐

	// K년이 지난 후 상도의 땅에 살아있는 나무의 개수 구하기

	int n, m, k; // N, M, K 5, 2, 1
	cin >> n >> m >> k;

	vector<pair<int, int> > checkDir; // 인접한 8개 칸
	checkDir.push_back({ -1, -1 });
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ -1, 1 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });
	checkDir.push_back({ +1, -1 });
	checkDir.push_back({ +1, 0 });
	checkDir.push_back({ 1, 1 });

	//  각 칸에 남아있는 현재 양분의 양
	vector<vector<int> > food(n + 1, vector<int>(n + 1, 5));

	//  겨울에 로봇이 땅을 돌아다니면서 각 칸에 추가하는 양분의 양
	vector<vector<int> > addFood(n + 1, vector<int>(n + 1));

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			cin >> addFood[i][j];
		}
	}

	// m개의 묘목 심기
	// 2 1 3 -> (2,1)에 나이가 3인 나무 push
	// 3 2 3 -> (3,2)에 나이가 3인 나무 push
	// 각 칸에 심어져있는 나무의 나이 저장
	// 덱을 이용해 나이가 적은 순서대로 뽑아냄
	vector<vector<deque<int>>> tree(n + 1, vector<deque<int>>(n + 1));

	int iPos, jPos, treeAge;

	for (int i = 0; i < m; i++)
	{
		cin >> iPos >> jPos >> treeAge;

		tree[iPos][jPos].push_front(treeAge);
	}

	// 가을에 각 칸마다 번식하는 나무의 수 카운팅
	vector<vector<int> > addTree(n + 1, vector<int>(n + 1));

	// K년이 지나면 종료
	while (k != 0)
	{
		for (int i = 1; i < n + 1; i++)
		{
			for (int j = 1; j < n + 1; j++)
			{
				if (!tree[i][j].empty()) // 해당칸에 심어진 나무가 있다면
				{
					vector<int> liveTree; // 봄에 살아남은 나무의 나이 저장
					int addFood = 0; // 여름에 추가될 양분의 양

					while (!tree[i][j].empty()) // 해당칸에 심어진 나무를 모두 체크해서
					{
						// 봄
						// 해당 칸에 심어진 나무의 나이만큼 해당 칸의 양분을 먹고 나이가 1증가함
						// 하나의 칸에 나무가 여러개 있다면 어린나무부터 양분을 먹음
						// 자기 나이만큼 양분을 못먹는 나무는 죽음
						if (food[i][j] >= tree[i][j].front())
						{
							// 칸의 양분과 꺼낸 나무의 나이를 비교해서
							// 만약 꺼낸 나무의 나이만큼 양분을 먹을수있다면
							// 칸의 양분을 꺼낸 나무의 나이만큼 감소
							// 꺼낸 나무의 나이를 1증가시켜 liveTree에 저장
							food[i][j] -= tree[i][j].front();
							liveTree.push_back(tree[i][j].front() + 1);
							tree[i][j].pop_front();
						}
						else
						{
							// 여름
							// 만약 꺼낸 나무의 나이만큼 양분을 먹을수없다면
							// 죽은 나무가되고 나이 / 2 만큼의 양분이 추가되어야함
							addFood += tree[i][j].front() / 2;
							tree[i][j].pop_front();
						}
					}

					// 살아남은 나무를 다시 칸에 심어진 나무로 저장
					for (int l = 0; l < liveTree.size(); l++)
					{
						tree[i][j].push_back(liveTree[l]);

						// 가을에 번식하는 나무 개수 카운팅
						if (liveTree[l] % 5 == 0)
						{
							addTree[i][j]++;
						}
					}

					// 여름에 추가될 양분 추가
					food[i][j] += addFood;
				}
			}
		}

		// 가을
		// 나무가 번식
		// 번식 가능한 나무는 나이가 5의 배수
		// 인접한 8개의 칸에 나이가 1인 나무 추가
		// 경계를 벗어나는 칸에는 나무가 생기지않음
		for (int i = 1; i < n + 1; i++)
		{
			for (int j = 1; j < n + 1; j++)
			{
				if (addTree[i][j] > 0) // 가을에 번식가능한 나무가 있다면
				{
					for (int l = 0; l < 8; l++) // 8개 인접한 칸 체크
					{
						// 체크 할 위치
						int checkI = i + checkDir[l].first;
						int checkJ = j + checkDir[l].second;

						// 경계체크
						if (checkI < 1 || checkJ < 1 || checkI >= n + 1 || checkJ >= n + 1)
						{
							continue;
						}

						// 번식할수있는 나무개수만큼 8개 인접칸에 추가
						for (int p = 0; p < addTree[i][j]; p++)
						{
							tree[checkI][checkJ].push_front(1);
						}
					}
				}

				// 가을에 추가되는 나무 수 다시 초기화
				addTree[i][j] = 0;

				// 겨울
				// 로봇이 땅을 돌아다니면서 땅에 양분을 추가함
				// 각 칸에 추가되는 양분의 양은 add 그래프의 값
				food[i][j] += addFood[i][j];
			}
		}

		// 1년 지남
		k--;
	}

	// K년이 지난 후 상도의 땅에 살아있는 나무의 개수 구하기
	int treeCnt = 0;

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			treeCnt += tree[i][j].size();
		}
	}

	cout << treeCnt << '\n';

	return 0;
}

//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <fstream>
//using namespace std;
//
//// 나무재테크
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	//ifstream cin;
//	//cin.open("input.txt");
//
//	// n by n 1-based 
//	// 모든 칸에 초기양분 5
//	// m개의 묘목을 심음
//	// 봄 : 심어진 나무의 나이만큼 양분을 먹고 나이가 1증가함
//	// 해당 나무가 심어진 칸의 양분만 먹을수있음
//	// 하나의 칸에 여러개의 나무가 있다면 어린나무부터 양분을 먹음
//	// 만약 자신의 나이만큼 양분을 먹을수없는 나무는 죽음
//	// 여름 : 봄에 죽은 나무가 양분으로 변함
//	// 각 죽은 나무마다 나이를 2로 나눈값이 해당 나무가 있던칸의 양분으로 추가되고 소수점 아래는 버림
//	// 가을 : 나무가 번식함
//	// 번식 가능한 나무는 나이가 5의 배수이며 인접한 8개의 칸에 나이가 1인 나무가 생김
//	// 경계를 벗어나는 칸에는 나무가 생기지않음
//	// 겨울 : 로봇이 땅을 돌아다니면서 땅에 양분을 추가함
//	// 각 칸에 추가되는 양분의 양은 A[r][c]로 입력을 통해 주어짐
//
//	// K년이 지난 후 상도의 땅에 살아있는 나무의 개수 구하기
//
//	int n, m, k; // N, M, K 5, 2, 1
//	cin >> n >> m >> k;
//
//	vector<pair<int, int> > checkDir; // 인접한 8개 칸
//	checkDir.push_back({ -1, -1 });
//	checkDir.push_back({ -1, 0 });
//	checkDir.push_back({ -1, 1 });
//	checkDir.push_back({ 0, -1 });
//	checkDir.push_back({ 0, 1 });
//	checkDir.push_back({ +1, -1 });
//	checkDir.push_back({ +1, 0 });
//	checkDir.push_back({ 1, 1 });
//
//	//	5 5 5 5 5
//	//	5 5 5 5 5
//	//	5 5 5 5 5
//	//	5 5 5 5 5
//	//	5 5 5 5 5
//	//  각 칸에 남아있는 현재 양분의 양
//	vector<vector<int> > food(n + 1, vector<int>(n + 1, 5));
//
//	//	2 3 2 3 2
//	//	2 3 2 3 2
//	//	2 3 2 3 2
//	//	2 3 2 3 2
//	//	2 3 2 3 2
//	// 겨울에 로봇이 땅을 돌아다니면서 각 칸에 추가하는 양분의 양
//	vector<vector<int> > addFood(n + 1, vector<int>(n + 1));
//
//	for (int i = 1; i < n + 1; i++)
//	{
//		for (int j = 1; j < n + 1; j++)
//		{
//			cin >> addFood[i][j];
//		}
//	}
//
//	// m개의 묘목 심기
//	// 2 1 3 -> (2,1)에 나이가 3인 나무 push
//	// 3 2 3 -> (3,2)에 나이가 3인 나무 push
//	// 각 칸에 심어져있는 나무의 나이 저장
//	// 우선순위 큐를 이용해 나이가 적은 순서대로 뽑아냄
//	vector<vector<priority_queue<int, vector<int>, greater<int> > > > tree(n + 1, vector<priority_queue<int, vector<int>, greater<int> > >(n + 1));
//
//	int iPos, jPos, treeAge;
//
//	for (int i = 0; i < m; i++)
//	{
//		cin >> iPos >> jPos >> treeAge;
//
//		tree[iPos][jPos].push(treeAge);
//	}
//
//	// 가을에 각 칸마다 번식하는 나무의 수 카운팅
//	vector<vector<int> > addTree(n + 1, vector<int>(n + 1));
//
//	// K년이 지나면 종료
//	while (k != 0)
//	{
//		for (int i = 1; i < n + 1; i++)
//		{
//			for (int j = 1; j < n + 1; j++)
//			{
//				if (!tree[i][j].empty()) // 해당칸에 심어진 나무가 있다면
//				{
//					vector<int> liveTree; // 봄에 살아남은 나무의 나이 저장
//					int addFood = 0; // 여름에 추가될 양분의 양
//
//					while (!tree[i][j].empty()) // 해당칸에 심어진 나무를 모두 체크해서
//					{
//						// 봄
//						// 해당 칸에 심어진 나무의 나이만큼 해당 칸의 양분을 먹고 나이가 1증가함
//						// 하나의 칸에 나무가 여러개 있다면 어린나무부터 양분을 먹음
//						// 자기 나이만큼 양분을 못먹는 나무는 죽음
//						if (food[i][j] >= tree[i][j].top())
//						{
//							// 칸의 양분과 꺼낸 나무의 나이를 비교해서
//							// 만약 꺼낸 나무의 나이만큼 양분을 먹을수있다면
//							// 칸의 양분을 꺼낸 나무의 나이만큼 감소
//							// 꺼낸 나무의 나이를 1증가시켜 liveTree에 저장
//							food[i][j] -= tree[i][j].top();
//							liveTree.push_back(tree[i][j].top() + 1);
//							tree[i][j].pop();
//						}
//						else
//						{
//							// 여름
//							// 만약 꺼낸 나무의 나이만큼 양분을 먹을수없다면
//							// 죽은 나무가되고 나이 / 2 만큼의 양분이 추가되어야함
//							addFood += tree[i][j].top() / 2;
//							tree[i][j].pop();
//						}
//					}
//
//					// 살아남은 나무를 다시 칸에 심어진 나무로 저장
//					for (int l = 0; l < liveTree.size(); l++)
//					{
//						tree[i][j].push(liveTree[l]);
//
//						// 가을에 번식하는 나무 개수 카운팅
//						if (liveTree[l] % 5 == 0)
//						{
//							addTree[i][j]++;
//						}
//					}
//
//					// 여름에 추가될 양분 추가
//					food[i][j] += addFood;
//				}
//			}
//		}
//
//		// 가을
//		// 나무가 번식
//		// 번식 가능한 나무는 나이가 5의 배수
//		// 인접한 8개의 칸에 나이가 1인 나무 추가
//		// 경계를 벗어나는 칸에는 나무가 생기지않음
//		for (int i = 1; i < n + 1; i++)
//		{
//			for (int j = 1; j < n + 1; j++)
//			{
//				if (addTree[i][j] > 0) // 가을에 번식가능한 나무가 있다면
//				{
//					for (int l = 0; l < 8; l++) // 8개 인접한 칸 체크
//					{
//						// 체크 할 위치
//						int checkI = i + checkDir[l].first;
//						int checkJ = j + checkDir[l].second;
//
//						// 경계체크
//						if (checkI < 1 || checkJ < 1 || checkI >= n + 1 || checkJ >= n + 1)
//						{
//							continue;
//						}
//
//						// 번식할수있는 나무개수만큼 8개 인접칸에 추가
//						for (int p = 0; p < addTree[i][j]; p++)
//						{
//							tree[checkI][checkJ].push(1);
//						}
//					}
//				}
//
//				// 가을에 추가되는 나무 수 다시 초기화
//				addTree[i][j] = 0;
//
//				// 겨울
//				// 로봇이 땅을 돌아다니면서 땅에 양분을 추가함
//				// 각 칸에 추가되는 양분의 양은 add 그래프의 값
//				food[i][j] += addFood[i][j];
//			}
//		}
//
//		// 1년 지남
//		k--;
//	}
//
//	// K년이 지난 후 상도의 땅에 살아있는 나무의 개수 구하기
//	int treeCnt = 0;
//
//	for (int i = 1; i < n + 1; i++)
//	{
//		for (int j = 1; j < n + 1; j++)
//		{
//			if (!tree[i][j].empty())
//			{
//				while (!tree[i][j].empty())
//				{
//					treeCnt++;
//
//					tree[i][j].pop();
//				}
//			}
//		}
//	}
//
//	cout << treeCnt << '\n';
//
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <fstream>
//using namespace std;
//
//// 나무 구조체
//struct Tree
//{
//	// 나이
//	int age;
//
//	// 생성자
//	Tree() {}
//	Tree(int a) : age(a) {}
//
//	// 나이가 적은순
//	bool operator<(const Tree &tree)const
//	{
//		return age > tree.age;
//	}
//};
//
//// 나무재테크
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	ifstream cin;
//	cin.open("input.txt");
//
//	// n by n 1-based 
//	// 모든 칸에 초기양분 5
//	// m개의 묘목을 심음
//	// 봄 : 심어진 나무의 나이만큼 양분을 먹고 나이가 1증가함
//	// 해당 나무가 심어진 칸의 양분만 먹을수있음
//	// 하나의 칸에 여러개의 나무가 있다면 어린나무부터 양분을 먹음
//	// 만약 자신의 나이만큼 양분을 먹을수없는 나무는 죽음
//	// 여름 : 봄에 죽은 나무가 양분으로 변함
//	// 각 죽은 나무마다 나이를 2로 나눈값이 해당 나무가 있던칸의 양분으로 추가되고 소수점 아래는 버림
//	// 가을 : 나무가 번식함
//	// 번식 가능한 나무는 나이가 5의 배수이며 인접한 8개의 칸에 나이가 1인 나무가 생김
//	// 경계를 벗어나는 칸에는 나무가 생기지않음
//	// 겨울 : 로봇이 땅을 돌아다니면서 땅에 양분을 추가함
//	// 각 칸에 추가되는 양분의 양은 A[r][c]로 입력을 통해 주어짐
//
//	// K년이 지난 후 상도의 땅에 살아있는 나무의 개수 구하기
//
//	int n, m, k; // N, M, K 5, 2, 1
//	cin >> n >> m >> k;
//
//	vector<pair<int, int> > checkDir; // 인접한 8개 칸
//	checkDir.push_back({ -1, -1 });
//	checkDir.push_back({ -1, 0 });
//	checkDir.push_back({ -1, 1 });
//	checkDir.push_back({ 0, -1 });
//	checkDir.push_back({ 0, 1 });
//	checkDir.push_back({ +1, -1 });
//	checkDir.push_back({ +1, 0 });
//	checkDir.push_back({ 1, 1 });
//
//	//	5 5 5 5 5
//	//	5 5 5 5 5
//	//	5 5 5 5 5
//	//	5 5 5 5 5
//	//	5 5 5 5 5
//	//  각 칸에 남아있는 현재 양분의 양
//	vector<vector<int> > food(n + 1, vector<int>(n + 1, 5));
//
//	//	2 3 2 3 2
//	//	2 3 2 3 2
//	//	2 3 2 3 2
//	//	2 3 2 3 2
//	//	2 3 2 3 2
//	// 겨울에 로봇이 땅을 돌아다니면서 각 칸에 추가하는 양분의 양
//	vector<vector<int> > addFood(n + 1, vector<int>(n + 1));
//
//	for (int i = 1; i < n + 1; i++)
//	{
//		for (int j = 1; j < n + 1; j++)
//		{
//			cin >> addFood[i][j];
//		}
//	}
//
//	// m개의 묘목 심기
//	// 2 1 3 -> (2,1)에 나이가 3인 나무 push
//	// 3 2 3 -> (3,2)에 나이가 3인 나무 push
//	// 각 칸에 심어져있는 나무로 우선순위 큐를 이용해 나이가 적은 순서대로 뽑아냄
//	vector<vector<priority_queue<Tree> > > tree(n + 1, vector<priority_queue<Tree> >(n + 1));
//
//	int iPos, jPos, treeAge;
//
//	for (int i = 0; i < m; i++)
//	{
//		cin >> iPos >> jPos >> treeAge;
//
//		tree[iPos][jPos].push(Tree(treeAge));
//	}
//
//	// 가을에 각 칸마다 번식하는 나무의 수 카운팅
//	vector<vector<int> > addTree(n + 1, vector<int>(n + 1));
//
//	// K년이 지나면 종료
//	while (k != 0)
//	{
//		for (int i = 1; i < n + 1; i++)
//		{
//			for (int j = 1; j < n + 1; j++)
//			{
//				if (!tree[i][j].empty()) // 해당칸에 심어진 나무가 있다면
//				{
//					vector<Tree> liveTree; // 봄에 살아남은 나무 저장
//					int addFood = 0; // 여름에 추가될 양분의 양
//
//					while (!tree[i][j].empty()) // 해당칸에 심어진 나무를 모두 체크해서
//					{
//						// 봄
//						// 해당 칸에 심어진 나무의 나이만큼 해당 칸의 양분을 먹고 나이가 1증가함
//						// 하나의 칸에 나무가 여러개 있다면 어린나무부터 양분을 먹음
//						// 자기 나이만큼 양분을 못먹는 나무는 죽음
//						if (food[i][j] >= tree[i][j].top().age)
//						{
//							// 칸의 양분과 꺼낸 나무의 나이를 비교해서
//							// 만약 꺼낸 나무의 나이만큼 양분을 먹을수있다면
//							// 칸의 양분을 꺼낸 나무의 나이만큼 감소
//							// 꺼낸 나무의 나이를 1증가시켜 liveTree에 저장
//							food[i][j] -= tree[i][j].top().age;
//							liveTree.push_back(Tree(tree[i][j].top().age + 1));
//							tree[i][j].pop();
//						}
//						else
//						{
//							// 여름
//							// 만약 꺼낸 나무의 나이만큼 양분을 먹을수없다면
//							// 죽은 나무가되고 나이 / 2 만큼의 양분이 추가되어야함
//							addFood += tree[i][j].top().age / 2;
//							tree[i][j].pop();
//						}
//					}
//
//					// 살아남은 나무를 다시 칸에 심어진 나무로 저장
//					for (int l = 0; l < liveTree.size(); l++)
//					{
//						tree[i][j].push(liveTree[l]);
//
//						// 가을에 번식하는 나무 개수 카운팅
//						if (liveTree[l].age % 5 == 0)
//						{
//							addTree[i][j]++;
//						}
//					}
//
//					// 여름에 추가될 양분 추가
//					food[i][j] += addFood;
//				}
//			}
//		}
//
//		// 가을
//		// 나무가 번식
//		// 번식 가능한 나무는 나이가 5의 배수
//		// 인접한 8개의 칸에 나이가 1인 나무 추가
//		// 경계를 벗어나는 칸에는 나무가 생기지않음
//		for (int i = 1; i < n + 1; i++)
//		{
//			for (int j = 1; j < n + 1; j++)
//			{
//				if (addTree[i][j] > 0) // 가을에 번식가능한 나무가 있다면
//				{
//					for (int l = 0; l < 8; l++) // 8개 인접한 칸 체크
//					{
//						// 체크 할 위치
//						int checkI = i + checkDir[l].first;
//						int checkJ = j + checkDir[l].second;
//
//						// 경계체크
//						if (checkI < 1 || checkJ < 1 || checkI >= n + 1 || checkJ >= n + 1)
//						{
//							continue;
//						}
//
//						// 번식할수있는 나무개수만큼 8개 인접칸에 추가
//						for (int p = 0; p < addTree[i][j]; p++)
//						{
//							tree[checkI][checkJ].push(Tree(1));
//						}
//					}
//				}
//
//				// 가을에 추가되는 나무 수 다시 초기화
//				addTree[i][j] = 0;
//
//				// 겨울
//				// 로봇이 땅을 돌아다니면서 땅에 양분을 추가함
//				// 각 칸에 추가되는 양분의 양은 add 그래프의 값
//				food[i][j] += addFood[i][j];
//			}
//		}
//
//		// 1년 지남
//		k--;
//	}
//
//	// K년이 지난 후 상도의 땅에 살아있는 나무의 개수 구하기
//	int treeCnt = 0;
//
//	for (int i = 1; i < n + 1; i++)
//	{
//		for (int j = 1; j < n + 1; j++)
//		{
//			if (!tree[i][j].empty())
//			{
//				while (!tree[i][j].empty())
//				{
//					treeCnt++;
//
//					tree[i][j].pop();
//				}
//			}
//		}
//	}
//
//	cout << treeCnt << '\n';
//
//	return 0;
//}