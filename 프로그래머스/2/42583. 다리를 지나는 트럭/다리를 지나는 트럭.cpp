#include <string>
#include <vector>
#include <queue>

using namespace std;

// 트럭 구조체
struct Truck
{
    int weight;
    int entryTime;
    
    // 생성자
    Truck(){}
    Truck(int w, int e) : weight(w), entryTime(e) {}
};

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;
    
    // bridge_length : 다리 길이
    // weight : 다리가 견딜수있는 무게
    // truck_weights : 트럭 무게
    // answer : 모든 트럭이 다리를 지나는데 걸리는 시간
    
    int crossSum = 0; // 현재 건너는트럭 큐 무게 합
    int waitIdx = 0; // 다음에 건너는트럭 큐에 추가할 대기중인 트럭 인덱스
    queue<Truck> crossQueue; // 건너는트럭 큐

    while (true)
    {
        // 건너는시간 카운팅
        answer++;

        // 다리를 건너고 있는 트럭의 경과시간(건너는시간 - 진입한시간)이 다리 길이와 같다면 pop
        if (!crossQueue.empty() && answer - crossQueue.front().entryTime == bridge_length)
        {
            crossSum -= crossQueue.front().weight;
            crossQueue.pop();
        }

        // 대기중인 트럭이 있으면서 허용무게를 초과하지않으면 push
        if (waitIdx < truck_weights.size() && crossSum + truck_weights[waitIdx] <= weight)
        {
            crossSum += truck_weights[waitIdx];
            crossQueue.push(Truck(truck_weights[waitIdx], answer));
            waitIdx++;
        }

        // 건너는트럭과 대기중인트럭이 모두 비었으면 break
        if (crossQueue.empty() && waitIdx == truck_weights.size())
        {
            break;
        }
    }

    return answer;
}
