#include <string>
#include <vector>

using namespace std;

int solution(int a, int b)
{
    int answer = 0;
    string s1 = to_string(a), s2 = to_string(b), s3 = s1 + s2;
    int t1 = stoi(s3), t2 = 2 * a * b;
    return t1 >= t2 ? t1 : t2;
}