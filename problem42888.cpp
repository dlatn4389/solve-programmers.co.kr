#include <iostream>
#include <algorithm>
using namespace std;

#include <unordered_map>
#include <vector>

// 명령과 닉네임을 이용해 적절한 문장을 반환
string make_sentence(string command, string nickname) {
    if (command=="Enter") {
        return nickname+"님이 들어왔습니다.";
    }
    return nickname+"님이 나갔습니다.";
}

vector<string> solution(vector<string> record) {
    // 명령과 유저 아이디를 담을 배열
    // first = 명령, second = 유저 아이디
    vector<pair<string, string>> command_and_userid;
    // key = 유저 아이디, value = 닉네임인 hashmap
    unordered_map<string, string> userid_nickname;

    for (string rec: record) {
        // vector record에 담긴 각각의 문자열에 대하여 수행
        vector<string> split;
        string tmp = "";
        // 문자열을 ' '를 기준으로 분할
        for (auto iter=rec.begin(); iter!=rec.end(); iter++) {
            if (*iter!=' ') {
                tmp += *iter;
            }
            else {
                split.push_back(tmp);
                tmp = "";
            }
        }
        split.push_back(tmp);

        string command = split[0];
        string user_id = split[1];

        // 명령에 따라 작업을 세분화
        if (command=="Enter") {
            string nickname = split[2];
            command_and_userid.push_back({command, user_id});
            userid_nickname[user_id] = nickname;
        }
        else if (command=="Leave") {
            command_and_userid.push_back({command, user_id});
        }
        else {
            // Change의 경우 command_and_userid에 추가하지 않고 hashmap만 사용
            string nickname = split[2];
            userid_nickname[user_id] = nickname;
        }
    }

    vector<string> answer;
    for (int i=0; i<command_and_userid.size(); i++) {
        string command = command_and_userid[i].first;
        string userid = command_and_userid[i].second;
        string nickname = userid_nickname[userid];
        answer.push_back(make_sentence(command, nickname));
    }
    return answer;
}