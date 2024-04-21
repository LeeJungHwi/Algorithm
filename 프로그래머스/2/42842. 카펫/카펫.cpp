#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    vector<int> answer;
    
    // brown : 갈색 격자 수
    // yellow : 노란색 격자 수
    // answer : 카펫의 가로, 세로 크기, 가로가 더 긴값을 가짐
    
    // 2 1
    // 4 4 1 1
    // 4 3
    
    // 1 1
    // 3 3 1 1
    // 3 3
    
    // 6 4
    // 8 8 4 4
    // 8 6
    
    // +2, +2
    
    // yellow에서 나누는수와 몫의 차가 가장 작은값을 구해서
    // 가로 : 나누는수와 몫 중 큰값을 + 2
    // 세로 : 작은값을 + 2
    // answer에 push
    
    for (int i = 1; i <= sqrt(yellow); i++)
    {
        // i : 나누는 수
        if (yellow % i == 0)
        {
            // j : 몫
            int j = yellow / i;
            
            int total = (j + 2) * (i + 2); // 전체 격자 수
            
            // 갈색 격자 수와 같으면
            if (brown == total - yellow)
            {
                // 가로 세로 answer에 push
                answer.push_back(max(j + 2, i + 2));
                answer.push_back(min(j + 2, i + 2));
                break; // 정답을 찾으면 반복 종료
            }
        }
    }
    
    return answer;
}