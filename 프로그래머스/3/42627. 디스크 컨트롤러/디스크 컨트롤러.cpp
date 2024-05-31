#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool comp(const vector<int> &v1, const vector<int> &v2)
{
    if(v1[0] != v2[0]) return v1[0] < v2[0];
    return v1[1] > v2[1];
}

struct Job
{
    int start;
    int end;
    
    Job() {}
    Job(int s, int e) : start(s), end(e) {}
    
    bool operator<(const Job &job)const
    {
        return end > job.end;
    }
};

int solution(vector<vector<int>> jobs)
{
    int answer = 0;
    
    // jobs : 진입 시간, 소요 시간
    
    // 0.jobs 진입 시간 오름차순, 소요 시간 내림차순 정렬
    // 1.curEnd, curIdx 초기화
    // 2.curIdx ~ jobs.size() 까지 돌면서 진입 시간이 curEnd 이하인 작업을 소요 시간 최소힙에 저장, curIdx 갱신
    // 3.최소힙에서 하나 꺼내서 answer += curEnd + 꺼낸 작업 소요 시간 - 꺼낸 작업 진입 시간, curEnd += 꺼낸 작업 소요 시간으로 갱신
    // 4.2~3 반복하다가 curIdx == jobs.size() && minHeap.empty() 가 되면 종료
    // 5.평균 시간 소수점 이하 버림
    
    sort(jobs.begin(), jobs.end(), comp);
    int curEnd = 0;
    int curIdx = 0;
    priority_queue<Job> minHeap;
    
    while(curIdx != jobs.size() || !minHeap.empty())
    {
        while(curIdx != jobs.size() && jobs[curIdx][0] <= curEnd)
        {
            minHeap.push(Job(jobs[curIdx][0], jobs[curIdx][1]));
            curIdx++;
        }
        
        if(!minHeap.empty())
        {
            curEnd += minHeap.top().end;
            answer += curEnd - minHeap.top().start;
            minHeap.pop();
        }
        else curEnd = jobs[curIdx][0];
    }
    
    return answer / jobs.size();
}