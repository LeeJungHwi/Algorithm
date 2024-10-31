#include <string>
#include <vector>

using namespace std;

int solution(int a, int b)
{
    string t1 = to_string(a);
    string t2 = to_string(b);
    string t3 = t1 + t2;
    return t3 > t2 + t1 ? stoi(t3) : stoi(t2 + t1);
}