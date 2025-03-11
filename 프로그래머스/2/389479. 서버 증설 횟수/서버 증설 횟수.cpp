#include <string>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k)
{
    // 같은 시간대 이용자가 m명 늘어나면 서버 1대가 추가됨
    // 어느 시간대 이용자가 n * m명 이상 (n + 1) * m명 미만이면 서버가 최소 n대가 있어야함
    // 한번 생긴 서버는 k 시간 동안 이용 후 반납함
    // 하루 동안 모든 이용자가 게임을 하기 위해 증설해야하는 서버의 개수
    
    // 모든 시각의 이용자의 수를 돌면서
    // 현재 서버 개수 => 현재 유지되는 서버 개수 - 현재 시각에 반납해야 할 서버 개수
    // 서버 증설 개수 => 현재 서버로 현재 이용자 수를 감당하고 남은 인원 / m
    // 서버 증설 개수가 0이 아니면 서버를 증설하고 현재 시각 + k 시각에 반납해야하는 개수로 저장
    
    int answer = 0; // 증설해야하는 서버의 개수
    int curCnt = 0; // 현재 서버 개수
    vector<int> returnCnt(24); // 각 시각 0~23에서 반납해야 할 서버 개수 저장
    for(int i = 0; i < players.size(); i++)
    {
        // 현재 서버 개수 => 현재 유지되는 서버 개수 - 현재 시각에 반납해야 할 서버 개수
        curCnt -= returnCnt[i];
        
        // 서버 증설 개수
        int addCnt = (players[i] - curCnt * m) / m;
        
        // 현재 서버로 현재 이용자 수가 이용 가능함
        if(addCnt <= 0) continue;
        
        // 현재 서버로 이용 불가능하면 서버 증설
        answer += addCnt;
        curCnt += addCnt;
        
        // 24시 이상은 반납 X
        if(i + k >= 24) continue;
        
        // k시간 이후 반납할 서버 개수 저장
        returnCnt[i + k] = addCnt;
    }
    
    return answer;
}