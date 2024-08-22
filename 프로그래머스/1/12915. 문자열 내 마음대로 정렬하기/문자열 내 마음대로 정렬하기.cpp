#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int globalN;

bool comp(string &s1, string &s2)
{
    if(s1[globalN] != s2[globalN]) return s1[globalN] < s2[globalN];
    return s1 < s2;
}

vector<string> solution(vector<string> strings, int n)
{
    globalN = n;
    sort(strings.begin(), strings.end(), comp);
    return strings;
}