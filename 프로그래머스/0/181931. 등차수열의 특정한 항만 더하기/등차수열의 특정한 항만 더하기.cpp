#include <string>
#include <vector>

using namespace std;

int solution(int a, int d, vector<bool> included)
{
    int answer = 0;
    for(int i = 0; i < included.size(); i++) answer += included[i] ? a + i * d : 0;
    return answer;
}