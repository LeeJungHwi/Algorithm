#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score)
{
    if(score.size() < m) return 0;
    int answer = 0;
    sort(score.rbegin(), score.rend());
    int boxCnt = 0;
    for(int i = 0; i < score.size() - m + 1; i += m) answer += score[i + m - 1] * m;
    return answer;
}