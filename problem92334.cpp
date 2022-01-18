#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <sstream>
using namespace std;

void print(const vector<int> &v) {
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << ' ';
    }
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    // 중복된 신고를 제거
    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());

    // 신고당한 횟수를 저장할 자료구조
    unordered_map<string, int> um;
    // 결과 메일 수를 저장할 자료구조
    unordered_map<string, int> um2;

    // 모든 사람들의 신고 횟수를 0으로 저장
    for (string s: id_list) {
        um[s] = 0;
        um2[s] = 0;
    }

    // 문자열 파싱에 사용할 sstream
    for (string s: report) {
        stringstream st;
        st.str(s);
        string target;
        st >> target; st >> target;

        um[target]++;
    }


    for (string s: report) {
        stringstream st;
        st.str(s);
        string reporter;
        string target;
        st >> reporter; st >> target;

        if (um[target]>=k) {
            um2[reporter]++;
        }
    }

    vector<int> answer;
    for (int i=0; i<id_list.size(); i++) {
        string target = id_list[i];
        answer.push_back(um2[target]);
    }

    return answer;
}