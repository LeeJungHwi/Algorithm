#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0;
    
    // board : 인형이 들어있는 그래프
    // moves : 크레인을 작동시킨 위치
    // 크레인을 작동시킨 위치의 인형을 스택에 쌓음
    // 스택에 같은인형이 두개쌓이면 사라짐
    // 사라진 인형의 개수 구하기
    
    // moves 돌면서
    // 크레인을 작동시키는 위치 열을 기준으로 가장 위쪽 행의 인형을 스택탑과 비교해서
    // 같은인형이 아니면 스택에 쌓고 같은인형이면 스택팝하고 사라진인형수 += 2
    // 그래프에서 해당인형 빈칸으로
    
    stack<int> s; // 크레인을 작동시켜 인형이 쌓임
    
    for(int i = 0; i < moves.size(); i++)
    {
        for(int j = 0; j < board.size(); j++)
        {
            if(board[j][moves[i] - 1] != 0) // 가장 위쪽 인형을 찾음
            {
                if(s.empty() || board[j][moves[i] - 1] != s.top()) // 비어있거나 다른인형이면 그냥 쌓음
                {
                    s.push(board[j][moves[i] - 1]);
                }
                else // 비어있지 않으면서 같은인형이면 팝하고 사라진인형수 += 2
                {
                    s.pop();
                    answer += 2;
                }
                
                // 그래프에서 해당인형 빈칸으로
                board[j][moves[i] - 1] = 0;
                
                break;
            }
        }
    }
    
    return answer;
}