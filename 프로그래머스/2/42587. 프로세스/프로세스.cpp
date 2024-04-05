#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// 프로세스 구조체
struct Process
{
    int prior; // 우선순위
    int loc; // 초기위치
    
    // 생성자
    Process() {}
    Process(int p, int l) : prior(p), loc(l) {}
};

int solution(vector<int> priorities, int location)
{
    int answer = 0;
    
    // priorities : 우선순위
    // location : 실행순서를 알고자하는 프로세스 인덱스
    
    // 일단 priorities 돌면서 큐에 저장
    
    queue<Process> processQueue; // 프로세스 큐
    
    for(int i = 0; i < priorities.size(); i++)
    {
        processQueue.push(Process(priorities[i], i)); // 1 1 9 1 1 1
    }
    
    int cnt = 0; // location에 위치한 프로세스가 몇번째로 실행되는지 카운팅
    
    // 큐가 빌때까지
    while(!processQueue.empty())
    {
        // 실행할 프로세스 하나 꺼냄
        Process curPorcess = processQueue.front();
        processQueue.pop();
        
        bool isPrior = false; // 더 높은 우선순위가 있는지 체크
        
        // 큐 돌면서 더 높은 우선순위가 있는지 체크
        for(int i = 0; i < processQueue.size(); i++)
        {
            // 더 높은 우선순위의 프로세스를 발견함
            if(curPorcess.prior < processQueue.front().prior)
            {
                isPrior = true;
            }
            
            // 더 높은 우선순위의 프로세스를 발견하거나
            // 모든 프로세스를 확인할때까지 다시 큐에 넣음
            processQueue.push(processQueue.front());
            processQueue.pop();
        }
        
        // 만약 더 높은 우선순위 프로세스를 발견했다면
        if(isPrior)
        {
            // 실행할 프로세스 다시 큐에 넣음
            processQueue.push(curPorcess);
        }
        else // 발견하지못했다면 실행할 프로세스를 실행
        {
            // 실행순서 카운팅
            cnt++;
            
            // 실행할 프로세스 초기위치가 location이면 종료
            if(curPorcess.loc == location)
            {
                answer = cnt;
                break;
            }
        }
    }
    
    return answer;
}