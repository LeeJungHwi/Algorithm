#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    
    // 폭탄 1
    // 폭탄 상하좌우 좌상 우상 좌하 우하는 위험지역
    // 안전지역 칸수 구하기
    
    // 그래프 돌면서
    // 폭탄을 만나면 상하좌우 좌상 우상 좌하 우하 2로 표시
    
    // 그래프 돌면서
    // 0이면 개수 카운팅
    
    vector<pair<int, int> > checkDir; // 상하좌우 좌상 우상 좌하 우하
    checkDir.push_back({-1, 0});
    checkDir.push_back({1, 0});
    checkDir.push_back({0, -1});
    checkDir.push_back({0, 1});
    checkDir.push_back({-1, -1});
    checkDir.push_back({-1, 1});
    checkDir.push_back({1, -1});
    checkDir.push_back({1, 1});
    
    // 그래프 돌면서
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board.size(); j++)
        {
            if(board[i][j] == 1) // 폭탄을 만나면
            {
                // 상하좌우 좌상 우상 좌하 우하
                for(int k = 0; k < 8; k++)
                {
                    // 체크 할 위치
                    int checkI = i + checkDir[k].first;
                    int checkJ = j + checkDir[k].second;
                    
                    // 경계체크
                    if(checkI < 0 || checkJ < 0 || checkI >= board.size() || checkJ >= board.size())
                    {
                        continue;
                    }
                    
                    // 폭탄체크
                    if(board[checkI][checkJ] == 1)
                    {
                        continue;
                    }
                    
                    // 이미 위험지역으로 된곳 체크
                    if(board[checkI][checkJ] == 2)
                    {
                        continue;
                    }
                    
                    // 위험지역으로
                    board[checkI][checkJ] = 2;
                }
            }
        }
    }
    
    // 그래프 돌면서
    // 0이면 개수 카운팅
    
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board.size(); j++)
        {
            if(board[i][j] == 0)
            {
                answer++;
            }
        }
    }
    
    return answer;
}