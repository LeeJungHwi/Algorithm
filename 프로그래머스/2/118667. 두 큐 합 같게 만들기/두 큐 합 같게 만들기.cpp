#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2)
{
    int answer = -2;
    
    // 길이가 같은 두 개의 큐가 주어짐
    // 작업단위 : 하나의 큐에서 꺼내서 다른 큐에 저장하는 작업
    // 두 큐 요소의 합이 같도록 하는 작업의 최소횟수 구하기
    
    // queue1 : 첫 큐
    // queue2 : 둘 큐
    // answer : 듀 큐 요소의 합이 같도록 하는 작업 최소횟수, 같게 만들수없으면 -1
    
    // 초기 첫큐합 둘큐합 첫큐합+둘큐합 구해놓기
    // 첫큐합이 < 첫큐합+둘큐합 / 2 이면 둘큐에서 꺼내서 첫큐에 저장
    // 첫큐합이 > 첫큐합+둘큐합 / 2 이면 첫큐에서 꺼내서 둘큐에 저장
    // 첫큐합 = 첫큐합+둘큐합 / 2 이면 answer에 작업횟수 저장
    // 첫큐 또는 둘큐 중 하나라도 비게되면 answer에 -1 저장
    
    queue<int> firstQueue; // 첫큐
    queue<int> secondQueue; // 둘큐
    long firstQueueSum = 0; // 첫큐합
    long secondQueueSum = 0; // 둘큐합
    long bothQueueSum = 0; // 첫큐합+둘큐합 / 2
    
    for(int i = 0; i < queue1.size(); i++)
    {
        firstQueue.push(queue1[i]); // 3 2 7 2
        firstQueueSum += queue1[i]; // 14
        secondQueue.push(queue2[i]); // 4 6 5 1
        secondQueueSum += queue2[i]; // 16
    }
    
    // 첫큐합 + 둘큐합이 짝수가아니면 같게만들수없음
//     if((firstQueueSum + secondQueueSum) % 2 != 0)
//     {
//         answer = -1;
        
//         return answer;
//     }
    
    bothQueueSum = (firstQueueSum + secondQueueSum) / 2; // 15
    int taskCnt = 0; // 작업횟수
    
    while(true)
    {
        // 첫큐합이 < 첫큐합+둘큐합 / 2 이면
        if(firstQueueSum < bothQueueSum)
        {
            // 둘큐에서 꺼내서 첫큐에 저장
            firstQueue.push(secondQueue.front());
            firstQueueSum += secondQueue.front();
            secondQueueSum -= secondQueue.front();
            secondQueue.pop();
            
            taskCnt++;
        }
        // 첫큐합이 > 첫큐합+둘큐합 / 2 이면
        else if(firstQueueSum > bothQueueSum)
        {
            // 첫큐에서 꺼내서 둘큐에 저장
            secondQueue.push(firstQueue.front());
            secondQueueSum += firstQueue.front();
            firstQueueSum -= firstQueue.front();
            firstQueue.pop();
            
            taskCnt++;
        }
        // 첫큐합 = 첫큐합+둘큐합 / 2 이면
        else if(firstQueueSum == bothQueueSum)
        {
            // answer에 작업횟수 저장
            answer = taskCnt;
            
            break;
        }
        
        // 첫큐 또는 둘큐 중 하나라도 비게되거나
        // 작업횟수가 큐 크기 * 4가되면 만들수없음
        if(firstQueue.empty() || secondQueue.empty() || taskCnt == queue1.size() * 4)
        {
            // answer에 -1 저장
            answer = -1;
            
            break;
        }
    }
    
    return answer;
}