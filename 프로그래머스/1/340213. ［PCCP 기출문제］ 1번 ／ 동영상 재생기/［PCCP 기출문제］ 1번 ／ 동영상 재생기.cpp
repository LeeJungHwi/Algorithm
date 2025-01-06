#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands)
{
    string answer = "";
    
    // video_len : 영상 길이
    // pos : 기능 수행 직전 재생위치 문자열
    // op_start : 오프닝 시작
    // op_end : 오프닝 끝
    // commands : 사용자 입력
    // 사용자 입력이 모두 수행된 후 영상의 위치 mm : ss

    int vm = stoi(video_len.substr(0, 2)), vs = stoi(video_len.substr(3, 2));
    int pm = stoi(pos.substr(0, 2)), ps = stoi(pos.substr(3, 2));
    int os = stoi(op_start.substr(0, 2) + op_start.substr(3, 2));
    int oe = stoi(op_end.substr(0, 2) + op_end.substr(3, 2));
    
    if(os <= pm * 100 + ps && pm * 100 + ps < oe)
    {
        pm = oe / 100;
        ps = oe % 100;
    }
    
    int curCommand = 0;
    for(int i = 0; i < commands.size(); i++)
    {
        // next 0 prev 1
        curCommand = commands[i] == "prev" ? 1 : 0;
        switch(curCommand)
        {
            case 0 :
                ps += 10;
                if(ps >= 60)
                {
                    pm += 1;
                    ps -= 60;
                }
                if(pm * 100 + ps > vm * 100 + vs)
                {
                    pm = vm;
                    ps = vs;
                }
                break;
            case 1 :
                ps -= 10;
                if(ps < 0)
                {
                    pm -= 1;
                    ps += 60;
                }
                if(pm < 0)
                {
                    pm = 0;
                    ps = 0;
                }
                break;
        }
        
        if(os <= pm * 100 + ps && pm * 100 + ps < oe)
        {
            pm = oe / 100;
            ps = oe % 100;
        }
    }
    
    //cout << pm << ' ' << ps;
    
    string spm = to_string(pm), sps = to_string(ps);
    if(spm.size() == 1) spm = '0' + spm;
    if(sps.size() == 1) sps = '0' + sps;
    return spm + ':' + sps;
}