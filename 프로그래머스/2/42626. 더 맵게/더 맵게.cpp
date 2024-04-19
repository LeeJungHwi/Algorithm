#include <string>
#include <vector>
#include <queue>

using namespace std;

// 최소힙
struct Scoville
{
    int value;
    
    Scoville() {}
    Scoville(int v) : value(v) {}
    
    bool operator<(const Scoville &scoville)const
    {
        return value > scoville.value;
    }
};

int solution(vector<int> scoville, int K)
{
    int answer = 0;
    
    // scoville : 가진 음식의 스코빌지수
    // K : 원하는 스코빌지수
    // 가장 맵지 않은 음식과 두번째로 맵지 않은 음식을 섞음
    // 섞은 스코빌지수 = 가장 맵지 않은 스코빌지수 + 두번째로 맵지 않은 스코빌 지수 * 2
    // 모든 음식이 원하는 스코빌지수를 가지기위해 섞은 최소횟수 구하기
    
    // 1.scoville 최소힙
    // 2.힙 탑이 K 이상이면 종료
    // 3.아니면 힙에서 두개 꺼내서 섞고 최소힙에 저장
    // 4.힙이 비었으면 -1 아니면 최소횟수 출력
    
    priority_queue<Scoville> minHeap;
    
    // 초기화
    for(int i = 0; i < scoville.size(); i++)
    {
        minHeap.push(Scoville(scoville[i]));
    }
    
    int cnt = 0;
    
    // 섞기전에 이미 K 이상이면 0 출력
    if(minHeap.top().value >= K) return answer = 0;
    
    while(!minHeap.empty())
    {
        // 가장 맵지 않은 음식
        int firstScoville = minHeap.top().value;
        minHeap.pop();
        
        // 가장 맵지 않은 음식을 꺼냈는데 힙이 비었으면
        // 원래 힙에 하나 음식만 있어서 섞을 수 없으므로
        // K 이상이면 cnt 아니면 -1
        if(minHeap.empty())
        {
            if(firstScoville >= K) return cnt;
            else break;
        }
        
        // 두번째로 맵지 않은 음식
        int secondScoville = 0; 
        if(!minHeap.empty())
        {
            secondScoville = minHeap.top().value;
            minHeap.pop();
        }
        
        // 섞은 스코빌지수 = 가장 맵지 않은 스코빌지수 + 두번째로 맵지 않은 스코빌 지수 * 2
        firstScoville += secondScoville * 2;
        
        minHeap.push(Scoville(firstScoville));
        
        cnt++;
        
        // 힙 탑이 K 이상이면 cnt 출력
        if(minHeap.top().value >= K) return cnt;
    }
    
    return answer = -1;
}