#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

// 최소힙
struct Num
{
    int number;
    
    Num() {}
    Num(int n) : number(n) {}
    
    bool operator<(const Num &num)const
    {
        return number > num.number;
    }
};

string solution(string s)
{
    string answer = "";
    
    // s : 숫자 문자열
    // 최댓값 최솟값 찾기
    
    priority_queue<int> maxHeap;
    priority_queue<Num> minHeap;
    
    // 1.s 돌면서 최대힙 최소힙에 저장
    // 2.answer에 최소힙 탑, 공백, 최대힙 탑 저장
    
    s += ' ';
    string curNum = "";
    
    for(int i = 0; i < s.size(); i++)
    {
        // 공백 만나면 저장
        if(s[i] == ' ')
        {
            maxHeap.push(stoi(curNum));
            minHeap.push(Num(stoi(curNum)));
            curNum = "";
            continue;
        }
        
        curNum += s[i];
    }
    
    answer += to_string(minHeap.top().number);
    answer += ' ';
    answer += to_string(maxHeap.top());
    //cout << answer;
    
    return answer;
}