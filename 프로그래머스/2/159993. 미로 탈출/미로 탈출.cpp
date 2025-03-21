#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> maps)
{
    // 레버 위치 부터 BFS 돌려서 레버 -> 시작 + 레버 -> 도착 - 2
    
    int n = maps.size(), m = maps[0].size();
    pair<int, int> sPos, ePos, lPos;
    vector<vector<char>> graph(n, vector<char>(m));
    vector<vector<int>> dis(n, vector<int>(m));
    queue<pair<int, int>> cp;
    vector<pair<int, int>> cd = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            graph[i][j] = maps[i][j];
            if(graph[i][j] == 'S') sPos = {i, j};
            else if(graph[i][j] == 'E') ePos = {i, j};
            else if(graph[i][j] == 'L') lPos = {i, j};
        }
    }
    
    cp.push(lPos);
    dis[lPos.first][lPos.second] = 1;
    
    while(!cp.empty())
    {
        int si = cp.front().first;
        int sj = cp.front().second;
        cp.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int ci = si + cd[i].first;
            int cj = sj + cd[i].second;
            
            if(ci < 0 || cj < 0 || ci >= n || cj >= m) continue;
            if(dis[ci][cj] > 0) continue;
            if(graph[ci][cj] == 'X') continue;
            
            cp.push({ci, cj});
            dis[ci][cj] = dis[si][sj] + 1;
        }
    }
    
    if(dis[sPos.first][sPos.second] == 0 || dis[ePos.first][ePos.second] == 0) return -1;
    return dis[sPos.first][sPos.second] + dis[ePos.first][ePos.second] - 2;
}