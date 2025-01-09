#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Num
{
    int number;
    Num() {}
    Num(int n) : number(n) {}
    
	bool operator<(const Num& num) const
	{
		return number > num.number;
	}
};

vector<int> solution(int k, vector<int> score)
{
    vector<int> answer;
    priority_queue<Num> minHeap;
    
    for(int i = 0; i < score.size(); i++)
    {
        minHeap.push(Num(score[i]));
        while(minHeap.size() > k) minHeap.pop();
        answer.push_back(minHeap.top().number);
    }
    
    return answer;
}