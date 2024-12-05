#include <string>
#include <vector>

using namespace std;

int solution(int hp)
{
    int answer = 0;
    vector<int> ants = {5, 3, 1};
    for (int i = 0; i < ants.size(); i++)
    {
        if (hp == 0) break;
        answer += hp / ants[i];
        hp %= ants[i];
    }
    return answer;
}