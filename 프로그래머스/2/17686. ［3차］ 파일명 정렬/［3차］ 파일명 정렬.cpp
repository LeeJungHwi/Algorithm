#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct File
{
    int order;
    string head;
    string number;
    string tail;
    
    File() {}
    File(int o, string h, string n, string t) : order(o), head(h), number(n), tail(t) {}
    
    bool operator<(const File &f) const
    {
        string lhsHead = "", rhsHead = "";
        for(int i = 0; i < head.size(); i++) lhsHead += isupper(head[i]) ? tolower(head[i]) : head[i];
        for(int i = 0; i < f.head.size(); i++) rhsHead += isupper(f.head[i]) ? tolower(f.head[i]) : f.head[i];
        if(lhsHead != rhsHead) return lhsHead < rhsHead;
        if(stoi(number) != stoi(f.number)) return stoi(number) < stoi(f.number);
        return order < f.order;
    }
};

vector<string> solution(vector<string> files)
{
    vector<string> answer;
    
    vector<File> sortFile;
    int cur = 1;
    for(int i = 0; i < files.size(); i++)
    {
        int order = cur++;
        string head = "", number = "", tail = "";
        bool isHead = false, isNumber = false;
        int numberCnt = 0;
        for(int j = 0; j < files[i].size(); j++)
        {
            if(!isHead && isdigit(files[i][j]))
            {
                isHead = true;
                j--;
                continue;
            }
            
            if(isHead && !isNumber && (!isdigit(files[i][j]) || numberCnt >= 5))
            {
                isNumber = true;
                j--;
                continue;
            }
            
            if(!isHead) head += files[i][j];
            else if(!isNumber)
            {
                numberCnt++;
                number += files[i][j];
            }
            else tail += files[i][j];
        }
        
        sortFile.push_back(File(order, head, number, tail));
        
        cout << order << ' ' << head << ' ' << number << ' ' << tail << '\n';
    }
    
    cout << '\n';
    sort(sortFile.begin(), sortFile.end());
    
    for(auto a : sortFile)
    {
        cout << a.order << ' ' << a.head << ' ' << a.number << ' ' << a.tail << '\n';
        string temp = a.head + a.number + a.tail;
        answer.push_back(temp);
    }
    
    return answer;
}