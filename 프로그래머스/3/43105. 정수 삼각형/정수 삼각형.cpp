#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle)
{
    int answer = 0;
    
    // triangle : 정수 삼각형 그래프
    // 합이 최대가 되는 경로에 있는 수의 합 구하기 
    // 좌상, 상 둘 중 최대값 + 자기자신
    // dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + graph[i][j]
    
    vector<vector<int> > graph(triangle.size() + 1, vector<int>(triangle.size() + 1));
    
	//	7
	//	3 8
	//	8 1 0
	//	2 7 4 4
	//	4 5 2 6 5
	for (int i = 1; i < triangle.size() + 1; i++)
	{
		for (int j = 1; j < i + 1; j++)
		{
            graph[i][j] = triangle[i - 1][j - 1];
		}
	}
    
    // for(auto a : graph)
    // {
    //     for(auto b : a)
    //     {
    //         cout << b << ' ';
    //     }
    //     cout << '\n';
    // }
    
    vector<vector<int> > dp(triangle.size() + 1, vector<int>(triangle.size() + 1));
    
	for (int i = 1; i < triangle.size() + 1; i++)
	{
		for (int j = 1; j < i + 1; j++)
		{
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + graph[i][j];
			answer = max(answer, dp[i][j]);
		}
	}
    
    return answer;
}