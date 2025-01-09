#include <string>
#include <vector>

using namespace std;

string solution(int a, int b)
{
    vector<int> m = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<string> w = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    
    int d = 0;
    for (int i = 0; i < a - 1; ++i) d += m[i];
    d += --b;
    
    return w[d % 7];
}