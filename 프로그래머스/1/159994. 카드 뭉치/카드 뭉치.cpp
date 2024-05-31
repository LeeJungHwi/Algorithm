#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal)
{
    string answer = "";
    
    // cards1, cards2 를 사용해 goal을 만들 수 있는지 체크
    
    int curCard1 = 0;
    int curCard2 = 0;
    int curGoal = 0;
    
    while(true)
    {
        // Find
        bool isGoal = false;
        
        if(goal[curGoal] == cards1[curCard1])
        {
            isGoal = true;
            curCard1++;
            curGoal++;
        }
        
        if(goal[curGoal] == cards2[curCard2])
        {
            isGoal = true;
            curCard2++;
            curGoal++;
        }
        
        // 못 찾았으면 No
        if(!isGoal) return "No";
        // curGoal이 goal.size 되면 Yes
        if(curGoal == goal.size()) return "Yes";
    }
    
    return answer;
}