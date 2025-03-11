#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<string> storage, vector<string> requests)
{
    // 그래프 n + 2, m + 2
    // 요청한 문자의 길이가 2 => 크레인이므로 그래프 돌면서 요청한 문자 빼내고 빈공간으로
    // 요청한 문자의 길이가 1 => 지게차이므로 0,0에서 BFS돌려서 요청한 문자를 만나면 빼내고 빈공간으로 만들고 분기는 X
    
    int n = storage.size(), m = storage[0].size();
    vector<vector<char>> graph(n + 2, vector<char>(m + 2, '.'));
    vector<vector<bool>> vis(n + 2, vector<bool>(m + 2));
    queue<pair<int, int>> cp;
    vector<pair<int, int>> cd = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for(int i = 1; i < n + 1; i ++) for(int j = 1; j < m + 1; j++) graph[i][j] = storage[i - 1][j - 1];
    
    int answer = n * m; // 남은 컨테이너 수
    for(int i = 0; i < requests.size(); i++)
    {
        // 크레인이면 그래프에서 요청한 문자를 모두 꺼내고 빈공간으로
        if(requests[i].size() == 2)
        {
            for(int j = 1; j < n + 1; j++)
            {
                for(int k = 1; k < m + 1; k++)
                {
                    if(graph[j][k] == requests[i][0])
                    {
                        answer--;
                        graph[j][k] = '.';
                    }
                }
            }
            
            continue;
        }
        
        // 지게차면 0, 0 부터 BFS 돌려서 요청한 문자는 꺼내고 빈공간으로 만들고 분기 X
        cp.push({0, 0});
        vis[0][0] = true;
        
        while(!cp.empty())
        {
            int si = cp.front().first;
            int sj = cp.front().second;
            cp.pop();
            
            for(int j = 0; j < 4; j++)
            {
                int ci = si + cd[j].first;
                int cj = sj + cd[j].second;
                
                if(ci < 0 || cj < 0 || ci >= n + 2 || cj >= m + 2) continue;
                if(vis[ci][cj]) continue;
                
                // 알파벳 이면서 요청한 문자가 아니면 X
                if(isalpha(graph[ci][cj]) && graph[ci][cj] != requests[i][0]) continue;
                
                // 요청한 문자인 경우 꺼내고 빈공간으로 만들고 분기 X
                if(graph[ci][cj] == requests[i][0])
                {
                    answer--;
                    graph[ci][cj] = '.';
                    vis[ci][cj] = true;
                    
                    continue;
                }
                
                // 빈공간인 경우 분기
                cp.push({ci, cj});
                vis[ci][cj] = true;
            }
        }

        // 방문체크 초기화
        for(int j = 0; j < n + 2; j++) for(int k = 0; k < m + 2; k++) vis[j][k] = false;
        
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