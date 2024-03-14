#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section)
{
    int answer = 0;
    
    // n : 페인트가 칠해진 벽 길이
    // m : 페인트를 칠하는 롤러 길이
    // 롤러로 벽에 페인트를 한번 칠하는 규칙
    // 1. 롤러가 벽에서 벗어나면 안됨
    // 2. 구역의 일부분만 포함되도록 칠하면 안됨
    // section : 벽을 1 / n 길이의 구역 n개로 나누고 1번부터 n까지 번호를 붙인 배열
    // answer : 롤러로 페인트칠해야하는 최소횟수
    
    // standardValue에 section[0] 저장, answer++
    // 섹션 돌면서
    // 섹션값 > standardValue + (m - 1)이면 standardValue에 섹션값 저장, answer++
    
    int standardValue = section[0];
    answer++;
    
    for(int i = 1; i < section.size(); i++)
    {
        if(section[i] > standardValue + m - 1)
        {
            standardValue = section[i];
            
            answer++;
        }
    }
    
    return answer;
}