#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words)
{
    vector<int> answer;
    
    map<string, int> wordMap;
    string pre = "";
    int curPlayer = 0;
    int curStep = 0;
    
    for(int i = 0; i < words.size(); i++)
    {
        curStep = i / n + 1;
        curPlayer = i % n + 1;

        if(words[i].size() == 1 || wordMap[words[i]] > 0 || (i > 0 && words[i][0] != pre.back())) return {curPlayer, curStep};

        wordMap[words[i]]++;
        pre = words[i];
    }
    
    return {0, 0};
}