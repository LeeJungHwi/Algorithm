#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w)
{
    int answer = 0;
    
    // board : 그래프
    // h w : board[h][w] 인접한 칸 중 색이 같은 칸 구하기
    
    vector<pair<int, int> > checkDir;
    checkDir.push_back({-1, 0});
    checkDir.push_back({1, 0});
    checkDir.push_back({0, -1});
    checkDir.push_back({0, 1});
    
    for(int i = 0; i < 4; i++)
    {
        int checkI = h + checkDir[i].first;
        int checkJ = w + checkDir[i].second;
        
        if(checkI < 0 || checkJ < 0 || checkI >= board[0].size() || checkJ >= board[0].size()) continue;
        if(board[checkI][checkJ] != board[h][w]) continue;
        
        answer++;
    }
    
    return answer;
}