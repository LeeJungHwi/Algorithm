#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 1234;
    
    // 그래프에서 1로 이루어진 가장 큰 정사각형 크기 구하기
    
    vector<vector<int> > graph(board.size() + 1, vector<int>(board[0].size() + 1)); // 그래프
    for(int i = 1; i < board.size() + 1; i++)
    {
        for(int j = 1; j < board[0].size() + 1; j++)
        {
            graph[i][j] = board[i - 1][j - 1];
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
    
    vector<vector<int> > dp(board.size() + 1, vector<int>(board[0].size() + 1)); // i,j를 우하로 했을 때 만들 수 있는 정사각형 한 변의 최대길이 저장
    
    // 1행 및 1열 : 그래프값
    // maxLen 갱신 : 단일 행렬 고려
    int maxLen = 0;
    for(int i = 1; i < board.size() + 1; i++)
    {
        dp[i][1] = graph[i][1];
        maxLen = max(maxLen, dp[i][1]);
    }
    for(int i = 1; i < board[0].size() + 1; i++)
    {
        dp[1][i] = graph[1][i];
        maxLen = max(maxLen, dp[1][i]);
    }
    
    // 2,2 부터 : 현재 dp값을 좌, 상, 좌상 중 최솟값 + 1로 저장
    for(int i = 2; i < board.size() + 1; i++)
    {
        for(int j = 2; j < board[0].size() + 1; j++)
        {
            if(graph[i][j] == 1)
            {
                dp[i][j] = min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]}) + 1;
                maxLen = max(maxLen, dp[i][j]);
            }
        }
    }
    
    answer = maxLen * maxLen;

    return answer;
}