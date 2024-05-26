#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
    vector<string> answer;
    
    // n by n : 지도 크기
    // arr1 : 지도 1
    // arr2 : 지도 2
    
    // 지도 1, 2 돌면서 이진변환 후 그래프에 저장 9 (4 1) (2 0) (1 0)
    // 지도 1 그래프 돌면서 공백인 부분을 만나면 지도 2가 벽인지 체크
    // 문자열로 변환 후 answer에 저장
    
    vector<vector<int> > graph1(n, vector<int>(n));
    vector<vector<int> > graph2(n, vector<int>(n));
    
    // 지도 1, 2 돌면서 이진변환 후 그래프에 저장 9 (4 1) (2 0) (1 0)
    for(int i = 0; i < arr1.size(); i++)
    {
        int curNum = arr1[i];
        int curIdx = n - 1;
        while(curNum > 0 && curIdx > -1)
        {
            graph1[i][curIdx--] = curNum % 2;
            curNum /= 2;
        }
    }
    for(int i = 0; i < arr2.size(); i++)
    {
        int curNum = arr2[i];
        int curIdx = n - 1;
        while(curNum > 0 && curIdx > -1)
        {
            graph2[i][curIdx--] = curNum % 2;
            curNum /= 2;
        }
    }
    
    // for(auto a : graph1)
    // {
    //     for(auto b : a)
    //     {
    //         cout << b << ' ';
    //     }
    //     cout << '\n';
    // }
    
    // 지도 1 그래프 돌면서 공백인 부분을 만나면 지도 2가 벽인지 체크
    // 문자열로 변환 후 answer에 저장
    for(int i = 0; i < n; i++)
    {
        string outputString = "";
        for(int j = 0; j < n; j++)
        {
            if(graph1[i][j] == 1)
            {
                outputString += '#';
                continue;
            }
            
            if(graph2[i][j] == 1)
            {
                outputString += '#';
                continue;
            }
            
            outputString += ' ';
        }
        answer.push_back(outputString);
    }
    
    // for(auto a : graph1)
    // {
    //     for(auto b : a)
    //     {
    //         cout << b << ' ';
    //     }
    //     cout << '\n';
    // }
    
    return answer;
}