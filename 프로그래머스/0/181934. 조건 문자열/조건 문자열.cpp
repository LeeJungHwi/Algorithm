#include <string>
#include <vector>

using namespace std;

int solution(string ineq, string eq, int n, int m)
{
    if(eq == "=") return (ineq == "<" ? n <= m : n >= m) ? 1 : 0;
    return ineq == "<" ? n < m : n > m;
}