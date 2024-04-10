#include <vector>
#include <algorithm>
using namespace std;

int maxScoreDiff; // 최대 점수 차이
vector<int> maxScoreDiffInfo(11); // 최대 점수 차이로 내가 이기는 방법

// DFS
void DFS(int L, int n, vector<int>& enemyinfo, vector<int>& myInfo, int myScore, int enemyScore)
{
    if (L == 11) // 종료조건 : 모든 과녁을 지난경우
    {
        // 현재 점수 차이
        int curScoreDiff = myScore - enemyScore;
        
        // 현재 점수 차이가 최대 점수 차이보다 클때 갱신
        if (curScoreDiff > maxScoreDiff)
        {
            maxScoreDiff = curScoreDiff; // 최대 점수 차이 갱신
            maxScoreDiffInfo = myInfo; // 내가 상대를 가장 큰 점수차로 이길수있는 방법을 현재 방법으로
            maxScoreDiffInfo[10] += n; // 남은 모든 화살은 0점 대에 사용
        }
        // 현재 점수 차이와 최대 점수 차이가 같을때
        else if (curScoreDiff == maxScoreDiff)
        {
            // 낮은 점수에 더 많은 화살을 쏜 경우일때 갱신
            for (int i = 10; i > -1; i--)
            {
                if (myInfo[i] > maxScoreDiffInfo[i])
                {
                    maxScoreDiffInfo = myInfo; // 내가 상대를 가장 큰 점수차로 이길수있는 방법을 현재 방법으로
                    maxScoreDiffInfo[10] += n; // 남은 모든 화살은 0점 대에 사용
                    
                    break;
                }
                else if (myInfo[i] < maxScoreDiffInfo[i])
                {
                    break;
                }
            }
        }
    }
    else
    {
        // 현재 과녁에서 상대보다 한발 더 쏘는 경우
        if (n > enemyinfo[L])
        {
            myInfo[L] = enemyinfo[L] + 1;
            DFS(L + 1, n - myInfo[L], enemyinfo, myInfo, myScore + 10 - L, enemyScore);
            myInfo[L] = 0;
        }

        // 현재 과녁을 포기하는 경우
        if (enemyinfo[L] > 0)
        {
            DFS(L + 1, n, enemyinfo, myInfo, myScore, enemyScore + 10 - L);
        }
        else
        {
            DFS(L + 1, n, enemyinfo, myInfo, myScore, enemyScore);
        }
    }
}

vector<int> solution(int n, vector<int> info)
{
    vector<int> answer(11, 0);
    
    // 1.점수계산
    // 1-1.k(1~10) 점을 상대가 a발 내가 b발 쐈으면 더 많은 화살을 k점에 쏜 사람이 k점을 가져감
    // 1-2.a와 b가 같으면 상대가 k점을 가져감
    // 1-3.k점을 여러발 쏴도 k점보다 많은점수를 가져가는게아니고 k점만 가져감
    // 1-4.둘다 k점을 한번이라도 쏜적이없으면 누구도 k점을 가져갈수없음
    // 2.상대 최종점수가 내 최종점수 이상이면 상대가 우승하고 작으면 내가 우승함
    
    // 현재상황은 상대가 n발을 이미 다 쏜 상태이고 내가 n발 쏠 차례임
    // 내가 상대를 가장 큰 점수차로 이기기위해 n발의 화살을 어떤 과녁에 쏴야하는지 구하기
    // 내가 무조건 지는경우 -1
    
    // n(1개이상 10개이하) : 쏠 화살 수
    // info(10점부터 0점) : 상대가 쏜 과녁 점수
    // answer(10점부터 0점) : 내가 쏴야하는 과녁 점수

    // DFS
    DFS(0, n, info, answer, 0, 0);

    // 내가 무조건 지는경우 -1
    if (maxScoreDiff == 0)
    {
        vector<int> neverWin(1, -1);
    
        return neverWin;
    }
    
    // 내가 상대를 가장 큰 점수차로 이길수있는 방법
    return maxScoreDiffInfo;
}
