#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, int w, int num)
{
    // 한 줄에 w개 씩 n개를 쌓을 때 num을 꺼내기 위해 꺼내야 하는 상자 개수
    // 1.상자 쌓기
    // 2.쌓을 때 num 위치와 num 열의 최대행 저장
    // 3.num 열의 최대행 - num 행 + 1
    
    vector<vector<int>> graph(n / w + 1, vector<int>(w));
    int cur = 1; // 택배 상자 번호
    pair<int, int> numPos = {-1, -1}; // num 위치
    int maxI = 0; // num열의 최대행
    for(int i = 0; i < n / w + 1; i++)
    {
        // 짝수행 왼쪽
        if(i % 2 == 0)
        {
            for(int j = 0; j < w; j++)
            {
                // num이면 num 위치 저장
                if(cur == num) numPos = {i, j};
                
                // num열이면 num 열의 최대행 저장
                if(j == numPos.second) maxI = i;
                
                // 택배 쌓기
                graph[i][j] = cur++;
                
                // n까지 쌓았으면 종료
                if(cur == n + 1) break;
            }
        }
        // 홀수행 오른쪽
        else
        {
            for(int j = w - 1; j > -1; j--)
            {
                // num이면 num열 저장
                if(cur == num) numPos = {i, j};
            
                // num열이면 num 열의 최대행 저장
                if(j == numPos.second) maxI = i;
                
                // 택배 쌓기
                graph[i][j] = cur++;
                
                // n까지 쌓았으면 종료
                if(cur == n + 1) break;
            }
        }
        
        // n까지 쌓았으면 종료
        if(cur == n + 1) break;
    }
    
    // for(auto a : graph)
    // {
    //     for(auto b : a)
    //     {
    //         cout << b << ' ';
    //     }
    //     cout << '\n';
    // }
    
    return maxI - numPos.first + 1;
}