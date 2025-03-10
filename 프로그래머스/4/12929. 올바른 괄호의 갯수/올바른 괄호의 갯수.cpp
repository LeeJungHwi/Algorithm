#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer;
string order;

void DFS(int L, vector<char> &v, int &n)
{
    if(L == n * 2)
    {
        //cout << order << '\n';
        
        // 선택한 순열이 올바른 괄호 문자열인지 체크
        int cnt = 0;
        for(int i = 0; i < n * 2; i++)
        {
            if(order[i] == '(') cnt++;
            else cnt--;
            
            if(cnt < 0) return;
        }
        
        if(cnt > 0) return;
        
        // 올바른 괄호 문자열이면 카운팅
        answer++;
    }
    else
    {
        // 중복순열
        for(int i = 0; i < v.size(); i++)
        {
            order += v[i];
            DFS(L + 1, v, n);
            order.pop_back();
        }
    }
}

int solution(int n)
{
    // 중복순열 n * 2개 괄호 문자 선택
    // 각 순열이 올바른 괄호 문자열인지 확인
    vector<char> v = {'(', ')'};
    DFS(0, v, n);
    return answer;
}