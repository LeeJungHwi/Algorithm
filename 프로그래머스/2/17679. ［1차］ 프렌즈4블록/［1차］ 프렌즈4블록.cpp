#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<string> board)
{
    int answer = 0;
    
    // 그래프 돌면서
    // 각 요소를 기준으로 2by2가 같은블록이면
    // 2by2에 해당하는 각 요소를 사라질블록으로 맵핑
    // 그래프를 모두 돌고나면 맵핑된게없으면 그래프 돌면서 비어있는 블록 개수를 answer에 저장하고 break;
    // 만약 맵핑된게 있다면 맵핑된 블록 위치를 모두 빈공간(1)로 만들고 그래프 역으로 돌면서 자기 아래가 빈공간(1)이 아닐때까지 내리고 맵 초기화
    
    map<pair<int, int>, int> deletePos; // 사라질블록 맵핑
    vector<pair<int, int> > checkDir; // 오른쪽 아래 오른쪽아래
    checkDir.push_back({0, 1});
    checkDir.push_back({1, 0});
    checkDir.push_back({1, 1});
    
    // 맵핑된게 없으면 종료
    while(true)
    {
        // 그래프 -1(2by2니까 마지막줄은 안 봐도 됨) 돌면서
        for(int i = 0; i < board.size() - 1; i++)
        {
            for(int j = 0; j < board[i].size() - 1; j++)
            {
                // 빈블록이면 continue
                if(board[i][j] == '1')
                {
                    continue;
                }
                
                // 기준위치
                pair<int, int> standardPos = {i, j};
                bool isDelete = true; // 삭제할 블록인지 체크
                vector<pair<int, int> > deleteBlock; // 삭제할 블록 저장
                deleteBlock.push_back({i, j});

                // 오른쪽 아래 오른쪽아래
                for(int k = 0; k < 3; k++)
                {
                    // 체크 할 위치
                    int checkI = standardPos.first + checkDir[k].first;
                    int checkJ = standardPos.second + checkDir[k].second;

                    // 하나라도 다른블록이거나 빈블록이면 삭제할블록 아님
                    if(board[checkI][checkJ] != board[standardPos.first][standardPos.second] || board[checkI][checkJ] == '1')
                    {
                        isDelete = false;

                         break;
                    }

                    // 일단 삭제할 블록에 저장
                    deleteBlock.push_back({checkI, checkJ});
                }

                // 삭제할 블록이면 맵핑
                if(isDelete)
                {
                    for(int k = 0; k < deleteBlock.size(); k++)
                    {
                        deletePos[{deleteBlock[k].first, deleteBlock[k].second}] = 1;
                    }
                }
            }
        }
        
        // 그래프를 모두 돌고나면 맵핑된게없으면 그래프 돌면서 비어있는 블록 개수를 answer에 저장하고 break;
        if(deletePos.empty())
        {
            for(int i = 0; i < board.size(); i++)
            {
                for(int j = 0; j < board[i].size(); j++)
                {
                    if(board[i][j] == '1')
                    {
                        answer++;
                    }
                }
            }
            
            break;
        }
        
        // 만약 맵핑된게 있다면 맵핑된 블록 위치를 모두 빈공간(1)로 만들고 그래프 역으로 돌면서 자기 아래가 빈공간(1)이 아닐때까지 내리고 맵 초기화
        
        // 만약 맵핑된게 있다면 맵핑된 블록 위치를 모두 빈공간(1)로 만들고
        for(auto it = deletePos.begin(); it != deletePos.end(); it++)
        {
            board[it->first.first][it->first.second] = '1';
        }
        
        // 그래프 역으로 돌면서 자기 아래가 빈공간(1)이 아닐때까지 내리고 맵 초기화
        for(int i = board.size() - 2; i > -1; i--)
        {
            for(int j = 0; j < board[i].size(); j++)
            {
                // 기준위치
                pair<int, int> standard = {i, j};
                
                // 기준위치 아래가 빈공간(1)이 아닐때까지 내림
                while(true)
                {
                    // 체크 할 위치
                    standard.first += 1;
                    
                    // 경계체크
                    if(standard.first >= board.size())
                    {
                        break;
                    }
                    
                    // 기준위치 아래가 1이 아니면 break
                    if(board[standard.first][standard.second] != '1')
                    {
                        break;
                    }
                    
                    // 기준위치 아래가 1이면 내리고 기준위치는 빈공간으로 바꿈
                    board[standard.first][standard.second] = board[standard.first - 1][standard.second];
                    board[standard.first - 1][standard.second] = '1';
                }
            }
        }
        
        // 맵 초기화
        deletePos.clear();
    }
    
    return answer;
}