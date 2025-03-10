#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday)
{
    // 시간 분 단위 처리 고려 + 요일 순환
    // 이벤트가 시작한 날 부터 주말을 제외하고 출근 희망 시각 + 10분 까지 모든 날을 출근 했다면 상품을 받는 직원
    // 이벤트가 시작한 날 => startday => 1(월) ~ 7(일)
    // 각 직원의 희망 출근 시간 => schedules => startday 부터 7일 => startday % 8
    // 각 직원이 출근한 시간 => timelogs
    
    // 모든 직원을 돌면서 상품을 받는 직원인지 확인
    int answer = 0;
    for(int i = 0; i < schedules.size(); i++)
    {
        bool is = true; // 상품을 받는 직원인지 체크
        int s = startday; // 이벤트가 시작한 날
        int limit = (schedules[i] % 100 >= 50) ? schedules[i] + 100 - 50 : schedules[i] + 10; // 출근 희망 시각 + 10
        for(int j = 0; j < 7; j++)
        {
            // 주말은 제외
            if(s == 6 || s == 7)
            {
                s = (s % 7) + 1;
                continue;
            }
            s = (s % 7) + 1;
            
            // 출근 희망 시각 + 10분을 넘긴 경우 X
            if(timelogs[i][j] > limit)
            {
                is = false;
                break;
            }
        }
        
        // 상품을 받는 직원이면 카운팅
        if(is) answer++;
    }
    
    return answer;
}