#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = n - lost.size(); // 체육복을 도난당하지 않은 사람 수로 초기화
    
    // n : 전체 학생수, 체격순
    // lost : 체육복을 도난당한 학생들의 번호 배열
    // reserve : 여벌의 체육복을 가져온 학생들의 번호 배열, 자신의 앞 또는 뒤 학생에게만 빌려줄수있음
    // answer : 체육수업을 들을수있는 학생 수 최대값
    
    // 1.여벌 체육복을 가져온 학생이 도난당한 경우
    // 여벌 체육복을 없애고 도난당한 학생에서 자기번호를 지우고 카운팅
    // 2.여벌 체육복을 가져온 학생이 체육복을 도난당한 학생을 빌려주는 경우
    // 가장 그리디한 것은 도난당한 학생기준 앞쪽에 여벌체육복을 가진 학생한테 빌려야함
    // 앞쪽에 여벌체육복을 가진 학생이 없으면 뒤쪽에 여벌체육복을 가진 학생한테 빌림
    
    // 도난당한 학생 오름차순 정렬
    sort(lost.begin(), lost.end());

    // 1.여벌 체육복을 가져온 학생이 도난당한 경우
    for (int i = 0; i < lost.size(); i++)
    {
        // 자기가 도난당한 학생이고 여벌체육복을 가진 학생을 가져옴
        auto it = find(reserve.begin(), reserve.end(), lost[i]);
        
        // 자기가 도난당한 학생이고 여벌체육복을 가진 학생이 있는 경우
        if (it != reserve.end())
        {
            // 여벌 체육복을 없애고 도난당한 학생에서 자기번호를 지우고 카운팅
            reserve.erase(it);
            lost.erase(lost.begin() + i);
            answer++;
            i--;
        }
    }

    // 2.여벌 체육복을 가져온 학생이 체육복을 도난당한 학생을 빌려주는 경우
    // 가장 그리디한 것은 도난당한 학생기준 앞쪽에 여벌체육복을 가진 학생한테 빌려야함
    // 앞쪽에 여벌체육복을 가진 학생이 없으면 뒤쪽에 여벌체육복을 가진 학생한테 빌림
    for (int i = 0; i < lost.size(); i++)
    {
        // 현재 학생의 앞 번호에 여벌 체육복을 가진 학생을 가져옴
        auto it = find(reserve.begin(), reserve.end(), lost[i] - 1);
        
        // 현재 학생의 앞 번호에 여벌 체육복을 가진 학생이 있는 경우
        if (it != reserve.end())
        {
            // 해당 학생의 여벌 체육복을 빌려주고 카운팅
            reserve.erase(it);
            answer++;
        }
        else // 현재 학생의 앞 번호에 여벌 체육복을 가진 학생이 없는 경우
        {
            // 현재 학생의 뒷 번호에 여벌 체육복을 가진 학생을 가져옴
            it = find(reserve.begin(), reserve.end(), lost[i] + 1);
            
            // 현재 학생의 뒷 번호에 여벌 체육복을 가진 학생이 있는 경우
            if (it != reserve.end())
            {
                // 해당 학생의 여벌 체육복을 빌려주고 카운팅
                reserve.erase(it);
                answer++;
            }
        }
    }
    
    return answer;
}