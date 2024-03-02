#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 비밀번호 찾기
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M 16, 4
	cin >> n >> m;

	map<string, string> sitePassword; // (주소, 비번)

	string site; // 주소
	string password; // 비번

	//	noj.am IU
	//	acmicpc.net UAENA
	//	startlink.io THEKINGOD
	//	google.com ZEZE
	//	nate.com VOICEMAIL
	//	naver.com REDQUEEN
	//	daum.net MODERNTIMES
	//	utube.com BLACKOUT
	//	zum.com LASTFANTASY
	//	dreamwiz.com RAINDROP
	//	hanyang.ac.kr SOMEDAY
	//	dhlottery.co.kr BOO
	//	duksoo.hs.kr HAVANA
	//	hanyang - u.ms.kr OBLIVIATE
	//	yd.es.kr LOVEATTACK
	//	mcc.hanyang.ac.kr ADREAMER
	//	startlink.io
	//	acmicpc.net
	//	noj.am
	//	mcc.hanyang.ac.kr
	for (int i = 0; i < n; i++)
	{
		cin >> site >> password;

		sitePassword[site] = password; // 주소 비번 매핑
	}

	//	startlink.io
	//	acmicpc.net
	//	noj.am
	//	mcc.hanyang.ac.kr
	for (int i = 0; i < m; i++)
	{
		cin >> site;

		// 사이트에따른 비번 출력
		password.clear();
		password = sitePassword.find(site)->second;
		cout << password << '\n';
	}

	return 0;
}