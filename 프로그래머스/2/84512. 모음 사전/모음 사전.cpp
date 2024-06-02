#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<char> aeiou = {'A', 'E', 'I', 'O', 'U'}; // 모음
int curIdx; // 현재 순서

void DFS(int L, string curW, string targetW, int &ans)
{
    // 최대길이 체크
    if(L > 5) return;
    
    // 타겟 단어 순서 찾으면
    if(curW == targetW) ans = curIdx;
    
    // 현재 순서 카운팅
    curIdx++;
    
    // 타겟 단어 순서 찾았는지 체크
    if(ans > 0) return;
    
    // 타겟 단어 순서를 찾지 않았으면 재귀
    for(int i = 0; i < aeiou.size(); i++) DFS(L + 1, curW + aeiou[i], targetW, ans);
}

int solution(string word)
{
    int answer = 0;
    
    DFS(0, "", word, answer);
    
    return answer;
}