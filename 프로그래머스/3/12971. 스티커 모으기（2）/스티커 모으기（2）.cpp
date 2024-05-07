#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> sticker)
{
    int answer = 0;
    
    // 원형으로 연결된 스티커 중 몇 장을 뜯어 스티커에 적힌 숫자의 합이 최대가 되도록 해야함
    // 뜯은 스티커를 기준으로 양 옆 스티커는 사용할 수 없음
    
    if(sticker.size() == 1) return sticker[0];
    else if(sticker.size() == 2) return max(sticker[0], sticker[1]);
    
    vector<int> score(sticker.size() + 1); // i 번 째 스티커의 점수 저장
    for(int i = 0; i < sticker.size(); i++) score[i + 1] = sticker[i];
    vector<int> dp1(sticker.size() + 1); // i 번 째 스티커를 뗄 때 최대점수 저장, 첫 스티커를 선택
    vector<int> dp2(sticker.size() + 1); // i 번 째 스티커를 뗄 때 최대점수 저장, 막 스티커를 선택
    int maxScore = 0; // 스티커 최대점수
    
    // 첫 스티커 선택
    dp1[1] = score[1];
    dp1[2] = score[1];
    
    // 막 스티커 선택
    dp2[1] = 0;
    dp2[2] = score[2];
    
    // 이전 스티커, 두 개 이전 스티커 + 현재 스티커 둘 중 최댓값으로 갱신
    
    // 첫 스티커 dp => 막 스티커 고려 X
    for(int i = 3; i < sticker.size(); i++)
    {
        dp1[i] = max(dp1[i - 1], dp1[i - 2] + score[i]);
        maxScore = max(maxScore, dp1[i]);
    }
    
    // 막 스티커 dp => 막 스티커 고려
    for(int i = 3; i < sticker.size() + 1; i++)
    {
        dp2[i] = max(dp2[i - 1], dp2[i - 2] + score[i]);
        maxScore = max(maxScore, dp2[i]);
    }
    
    answer = maxScore;

    return answer;
}