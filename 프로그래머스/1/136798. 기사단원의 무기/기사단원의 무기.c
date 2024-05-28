#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int number, int limit, int power)
{
    int answer = 0;
    
    // number : 기사단원 수
    // limit : 제한수치
    // power : 제한수치를 넘긴 기사가 사야 할 무기
    // 기사는 각 number의 약수 개수에 해당하는 무기를 사야함
    // 제한수치를 넘어가면 power에 해당하는 무기를 사야함
    
    // 약수 개수 구하고 limit 넘어가면 power로 아니면 cnt로
    int curPower = 0;
    int cnt = 0;
    for(int i = 1; i < number + 1; i++)
    {
        curPower = i;
        cnt = 0;
        for(int j = 1; j * j <= i; j++)
        {
            if(i % j == 0)
            {
                cnt++;
                if(i / j != j) cnt++;
            }
        }
        
        answer += cnt > limit ? power : cnt;
    }
    
    return answer;
}