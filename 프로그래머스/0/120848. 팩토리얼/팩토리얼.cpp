#include <string>
#include <vector>

using namespace std;

vector<int> fact(11);

int solution(int n)
{
    int temp = 1;
    for(int i = 1; i < 11; i++)
    {
        fact[i] = temp *= i;
        if(fact[i] > n) return --i;
    }
    return 10;
}