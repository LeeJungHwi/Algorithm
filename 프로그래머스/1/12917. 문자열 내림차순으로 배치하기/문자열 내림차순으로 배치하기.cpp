#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string solution(string s)
{
    sort(s.rbegin(), s.rend());
    return s;
}