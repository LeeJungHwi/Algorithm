#include <string>
#include <vector>

using namespace std;

bool IsPrime(int n)
{
    for(int i = 2; i * i <= n; i++)
    {
        if(n % i == 0) return false;
    }
    return true;
}

vector<int> solution(int n)
{
    vector<int> answer;
    vector<int> prime;
    
    // n이하 소인수 찾기
    for(int i = 2; i < n + 1; i++) if(IsPrime(i)) prime.push_back(i);
    
    for(int i = 0; i < prime.size(); i++) if(n % prime[i] == 0) answer.push_back(prime[i]);
    
    return answer;
}