#include <string>
#include <iostream>
#include <vector>
using namespace std;

vector<int> selected; // 선택된 학생들의 번호 저장
int answer; // 삼총사 수

// DFS
void DFS(int L, int cnt, vector<int> &num)
{
    if(L == num.size() || cnt == 3) // 종료조건 : 선택가능한 학생수를 넘기거나 세명을 뽑은경우
    {
        // 선택가능한 학생수를 넘긴경우
        if(L == num.size())
        {
            // 3명을 뽑은게 아니면 리턴
            if(cnt != 3)
            {
                return;
            }
        }
        
        int sum = 0; // 세명의 학생들의 번호 합
        
        for(int i = 0; i < selected.size(); i++)
        {
            sum += selected[i];
            
            // 디버깅용
            // cout << selected[i] << ' ';
        }
        //cout << '\n';
        
        if(sum == 0) // 세 학생의 번호합이 0이면 카운팅
        {
            answer++;
        }
    }
    else
    {
        selected.push_back(num[L]); // 선택
        DFS(L + 1, cnt += 1, num);
        selected.pop_back(); // 미선택
        DFS(L + 1, cnt -= 1, num);
    }
}

int solution(vector<int> number)
{
    // number : 한국중학교 학생들의 번호 배열
    // 삼총사 : 학생 3명의 번호를 더했을때 0
    // 한국중학교에서 삼총사를 만들수있는 수 구하기
    
    // DFS
    DFS(0, 0, number);
    
    return answer;
}