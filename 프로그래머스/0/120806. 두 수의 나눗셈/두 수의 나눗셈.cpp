#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2)
{
    double n1 = num1, n2 = num2;
    return int((n1 / n2) * 1000);
}