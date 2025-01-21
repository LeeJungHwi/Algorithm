#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    vector<int> answer;
    vector<vector<int> > graph(rows + 1, vector<int>(columns + 1));
    int start = 1;
    for(int i = 1; i < rows + 1; i++)
    {
        for(int j = 1; j < columns + 1; j++)
        {
            graph[i][j] = start++;
        }
    }
    
    for(int i = 0; i < queries.size(); i++)
    {
        int temp = graph[queries[i][0]][queries[i][1]];
        int minVal = temp;
        for(int j = queries[i][0] + 1; j < queries[i][2] + 1; j++)
        {
            graph[j - 1][queries[i][1]] = graph[j][queries[i][1]];
            minVal = min(minVal, graph[j][queries[i][1]]);
        }
        for(int j = queries[i][1] + 1; j < queries[i][3] + 1; j++)
        {
            graph[queries[i][2]][j - 1] = graph[queries[i][2]][j];
            minVal = min(minVal, graph[queries[i][2]][j]);
        }
        for(int j = queries[i][2] - 1; j > queries[i][0] - 1; j--)
        {
            graph[j + 1][queries[i][3]] = graph[j][queries[i][3]];
            minVal = min(minVal, graph[j][queries[i][3]]);
        }
        for(int j = queries[i][3] - 1; j > queries[i][1]; j--)
        {
            graph[queries[i][0]][j + 1] = graph[queries[i][0]][j];
            minVal = min(minVal, graph[queries[i][0]][j]);
        }
        graph[queries[i][0]][queries[i][1] + 1] = temp;
        
        answer.push_back(minVal);
        
        // for(auto a : graph)
        // {
        //     for(auto b : a)
        //     {
        //         cout << b << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
    }
    return answer;
}